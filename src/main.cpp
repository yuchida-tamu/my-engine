#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "mesh/triangle.h"
#include "mesh/mesh.h"
#include "window/window.h"

int main(){
   
    Window window(800, 800, "My Engine");
    int success = window.init();
    if(!success){
        return -1;
    }

    Shader shader("basic.vert", "basic.frag");
    shader.compile();

    Mesh* triangle = new Triangle2D();
    triangle->create();

    glGetError();
   
    while (!window.shouldClose())
    {
        window.clear();

        shader.use();
        triangle->draw();

        window.swapBuffers();
        glfwPollEvents();
    }

    glDeleteProgram(shader.ID);
    triangle->destroy();

    window.~Window(); 

    return 0;
}
