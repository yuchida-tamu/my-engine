#include "mesh.h"

class Triangle2D : public Mesh
{
public:
    Triangle2D() : Mesh(vertices, 9, indices, 3) {}
    void create() {
        Mesh::create();
    }
private:
    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    unsigned int indices[3] = {
        0, 1, 2
    };
};