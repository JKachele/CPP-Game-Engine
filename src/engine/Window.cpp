/*Project-------CPP_Game_Engine
 *File----------window.cpp
 *Author--------Justin Kachele
 *Date----------11/14/2022
 *License-------GNU GENERAL PUBLIC LICENSE
******************************************/
#include "engine/Window.h"

namespace GameEngine {

    void framebuffer_size_callback(__attribute__((unused)) GLFWwindow* window, int width, int height);

    Window* getInstance() {
        if (instance) {
            instance = new Window();

        }
    }

    void Window::initWindow(int width, int height, const char* title) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (glfwWindow == nullptr) {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(glfwWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }

        glViewport(0, 0, width, height);

        glfwSetFramebufferSizeCallback(glfwWindow, framebuffer_size_callback);
    }

    GLFWwindow* Window::getGlfwWindow() const {
        return glfwWindow;
    }

    int Window::getWindowWidth() const {
        return windowWidth;
    }

    int Window::getWindowHeight() const {
        return windowHeight;
    }

    void framebuffer_size_callback(__attribute__((unused)) GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }
}
