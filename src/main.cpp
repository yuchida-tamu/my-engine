#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "shader.h"
#include "mesh/triangle.h"
#include "mesh/plane.h"
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

    Mesh* plane = new Plane();
    plane->create();
    int width, height, nrChannels;
    unsigned char* data = stbi_load("../assets/images/container.jpg", &width, &height, &nrChannels, 0);
    if(data)
    {
       plane->setTexture(data, width, height);
    }
    else
    {
        std::cerr << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glGetError();
   
    while (!window.shouldClose())
    {
        window.clear();

        shader.use();
        plane->draw();

        window.swapBuffers();
        glfwPollEvents();
    }

    glDeleteProgram(shader.ID);
    plane->destroy();

    window.~Window(); 

    return 0;
}
