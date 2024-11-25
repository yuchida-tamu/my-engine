#include "mesh.h"
#include <iostream>

Mesh::Mesh(float* vertices, unsigned int vertexCount, unsigned int* indices, unsigned int indexCount){
    VAO = 0;
    VBO = 0;
    EBO = 0;
    this->vertices = vertices;
    this->vertexCount = vertexCount;
    this->indices = indices;
    this->indexCount = indexCount;
}

void Mesh::create(){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * vertexCount, vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * indexCount, indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::draw(){
    glBindVertexArray(VAO);
    // glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, indexCount);
    glBindVertexArray(0);
}

void Mesh::destroy(){
    std::cout << "Mesh destroyed" << std::endl;
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

Mesh::~Mesh(){
    destroy();
}