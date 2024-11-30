#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

void frame_buffer_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

class Window 
{
public:
    int width, height;
    const char* title;
    glm::vec4 clearColor;
    
    GLFWwindow* window;

    Window() {
        width = 800;
        height = 800;
        title = "My Engine";
        clearColor = glm::vec4(0.07f, 0.07f, 0.07f, 1.0f);
    }
    Window(int width, int height, const char* title) {
        this->width = width;
        this->height = height;
        this->title = title;
        clearColor = glm::vec4(0.07f, 0.07f, 0.07f, 1.0f);
    }
    bool init()
    {
        setUpGlfw();

        GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
        if(window == NULL){
            std::cerr << "Failed to create GLFW window" << std::endl;
            return false;
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, frame_buffer_callback);
        gladLoadGL(glfwGetProcAddress);
        glViewport(0, 0, width, height);
        this->window = window;
        return true;
    }

    void clear(){
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void swapBuffers(){
        glfwSwapBuffers(window);
    }  

    bool shouldClose(){
        return glfwWindowShouldClose(window);
    }

    ~Window(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }
private:
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
};