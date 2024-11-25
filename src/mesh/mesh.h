#pragma once

#include <glad/gl.h>

class Mesh 
{
public:
    Mesh(float* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount);
    ~Mesh();
    void draw();
    void destroy();
    void create();
private:
    unsigned int VAO, VBO, EBO;
    float* vertices;
    unsigned int vertexCount;
    unsigned int* indices;
    unsigned int indexCount;
};