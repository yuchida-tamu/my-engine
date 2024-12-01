#include "mesh.h"

class Triangle2D : public Mesh
{
public:
    Triangle2D() : Mesh(vertices, 9, indices, 3) {}
    void create() {
        Mesh::create();
    }
private:
    float vertices[24] = {
        // positions          // colors           // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    };

    unsigned int indices[3] = {
        0, 1, 2
    };
};