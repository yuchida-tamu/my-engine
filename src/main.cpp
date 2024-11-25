#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "mesh/triangle.h"
#include "mesh/mesh.h"



void setUpGlfw(){
    glfwInit();

    // specifies glfw version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // specifies glfw profile 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

int main(){
   
    setUpGlfw();

    GLFWwindow* window = glfwCreateWindow(800, 800, "My Engine", NULL, NULL);
    if(window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glViewport(0, 0, 800, 800);

    Shader shader("basic.vert", "basic.frag");
    shader.compile();

    Mesh* triangle = new Triangle2D();
  
    glClearColor(0.07f, 0.07f, 0.07f, 1.0f);
    glGetError();
   
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        triangle->draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(shader.ID);
    triangle->destroy();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
