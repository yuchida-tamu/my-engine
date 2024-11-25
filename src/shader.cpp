#include "shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath){
    vertexShaderSource = readShaderFile(vertexPath);
    if (vertexShaderSource == NULL) {
        std::cerr << "Failed to read vertex shader file" << std::endl;
        return;
    }

    fragShaderSource = readShaderFile(fragmentPath);
    if (fragShaderSource == NULL) {
        std::cerr << "Failed to read fragment shader file" << std::endl;
        return;
    }

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
}

void Shader::compile(){
    
    if(vertexShaderSource == NULL || fragShaderSource == NULL){
        std::cerr << "Failed to compile shader" << std::endl;
        return;
    }


    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glShaderSource(fragmentShader, 1, &fragShaderSource, NULL);
    glCompileShader(fragmentShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use(){
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

char* Shader::readShaderFile(const char* filename){
    std::filesystem::path filepath = std::filesystem::path(SHADER_BASE_DIR) / filename;

    if (!std::filesystem::exists(filepath)) {
        std::cerr << "File does not exist: " << filepath << std::endl;
        return NULL;
    }

    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath << std::endl;
        return NULL;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    char* data = (char*)malloc(content.size() + 1);
    if (data == NULL) {
        std::cerr << "Failed to allocate memory for: " << filepath << std::endl;
        return NULL;
    }

    std::copy(content.begin(), content.end(), data);
    data[content.size()] = '\0';

    return data;
}