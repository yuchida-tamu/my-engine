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
    void setPrimaryTexture(unsigned char* data, int width, int height);
    void setSecondaryTexture(unsigned char* data, int width, int height);
private:
    unsigned int VAO, VBO, EBO, texture1, texture2;
    float* vertices;
    unsigned int vertexCount;
    unsigned int* indices;
    unsigned int indexCount;
};