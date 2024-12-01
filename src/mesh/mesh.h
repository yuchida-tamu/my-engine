#pragma once

#include <glad/gl.h>

class Mesh 
{
public:
    Mesh();
    Mesh(float* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount);
    ~Mesh();
    void draw();
    void destroy();
    void create();
    void setTexture(unsigned char* data, int width, int height);
private:
    unsigned int VAO, VBO, EBO, texture;
    float* vertices;
    unsigned int vertexCount;
    unsigned int* indices;
    unsigned int indexCount;
};