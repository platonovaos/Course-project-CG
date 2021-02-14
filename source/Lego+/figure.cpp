#include "figure.h"

Figure::Figure(const char *filename, const QColor& color, const Vector3f& center) :
    center(center),
    color(color)
{
    std::ifstream in;

    in.open(filename, std::ifstream::in);

    if (in.fail()) {
        return;
    }

    std::string line;

    while (!in.eof()) {
        std::getline(in, line);

        std::istringstream iss(line.c_str());
        char trash;

        if (!line.compare(0, 2, "v ")) {
            iss >> trash;
            Vector3f v;

            for (int i = 0; i < 3; i++) {
                iss >> v[i];
            }

            verts.push_back(v);
        }

        else if (!line.compare(0, 3, "vn ")) {
            iss >> trash >> trash;
            Vector3f n;

            for (int i = 0; i < 3; i++) {
                iss >> n[i];
            }

            norms.push_back(n);
        }

        else if (!line.compare(0, 2, "f ")) {
            std::vector<Vector3i> f;
            Vector3i tmp;

            iss >> trash;

            while (iss >> tmp[0] >> trash >> tmp[1] >> trash >> tmp[2]) {
                for (int i = 0; i < 3; i++) {
                    tmp[i]--;
                }

                f.push_back(tmp);
            }
            faces.push_back(f);
        }
    }
}

Vector3f& Figure::getCenter()
{
    return center;
}

void Figure::setCenter(const Vector3f& newCenter)
{
    center = newCenter;
}

int Figure::countVerts()
{
    return verts.size();
}

Vector3f& Figure::vert(const int& idx)
{
    return verts[idx];
}


int Figure::countFaces()
{
    return faces.size();
}

std::vector<int> Figure::face(const int& idx)
{
    std::vector<int> face;
    size_t size = faces[idx].size();

    for (size_t i = 0; i < size; i++) {
        face.push_back(faces[idx][i][0]);
    }

    return face;
}


int Figure::countNorms()
{
    return norms.size();
}

void Figure::setNorm(const int& iface, const int& nvert, const Vector3f& n)
{
    int idx = faces[iface][nvert][2];
    norms[idx] = n;
}

Vector3f& Figure::norm(const int& iface, const int& nvert)
{
    int idx = faces[iface][nvert][2];
    return norms[idx].normalize();
}

Vector3f Figure::normalCalculate(const Vector3f& a, const Vector3f& b, const Vector3f& c)
{
    Vector3f n = (c - a) ^ (b - a);
    return n;
}

void Figure::normalsProcessing()
{
    size_t nface = faces.size();

    for (size_t i = 0; i < nface; i++) {
        std::vector<int> f = face(i);

        setNorm(i, 0, normalCalculate(vert(f[0]), vert(f[1]), vert(f[2])));
        setNorm(i, 1, normalCalculate(vert(f[1]), vert(f[2]), vert(f[0])));
        setNorm(i, 2, normalCalculate(vert(f[2]), vert(f[0]), vert(f[1])));
    }
}


QColor& Figure::getColor()
{
    return color;
}

void Figure::setColor(const QColor& newColor)
{
    color = newColor;
}

void Figure::move(const Vector3f& d)
{
    int nverts = verts.size();

    for (int i = 0; i < nverts; i++) {
        verts[i].x += d.x;
        verts[i].y += d.y;
        verts[i].z += d.z;
    }
}

void Figure::scale(const Vector3f& k)
{
    int nverts = verts.size();

    for (int i = 0; i < nverts; i++) {
        verts[i].x *= k.x;
        verts[i].y *= k.y;
        verts[i].z *= k.z;
    }

    normalsProcessing();
}


void Figure::rotate(const Vector3f& angle)
{
    std::shared_ptr<Matrix> rx(new RotateOxMatrix(angle.x * M_PI / 180));
    std::shared_ptr<Matrix> ry(new RotateOyMatrix(angle.y * M_PI / 180));
    std::shared_ptr<Matrix> rz(new RotateOzMatrix(angle.z * M_PI / 180));

    size_t nverts = verts.size();

    for (size_t i = 0; i < nverts; i++) {
        verts[i].transform(rx);
        verts[i].transform(ry);
        verts[i].transform(rz);
    }
}
