#pragma once

#include <glad/gl.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#ifndef SHADER_BASE_DIR
#define SHADER_BASE_DIR "shaders"
#endif

class Shader 
{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void compile();
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

private:
    const char* vertexShaderSource;
    const char* fragShaderSource;
    unsigned int vertexShader, fragmentShader;
    char* readShaderFile (const char* filename);
};