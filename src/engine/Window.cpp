/*Project-------CPP_Game_Engine
 *File----------window.cpp
 *Author--------Justin Kachele
 *Date----------11/14/2022
 *License-------GNU GENERAL PUBLIC LICENSE
******************************************/
#include "engine/Window.h"
#include "engine/UserInputs.h"

namespace GameEngine {
    Window* Window::instance = 0;

    Window* Window::getInstance() {
        if (!instance) {
            instance = new Window();
        }
        return instance;
    }

    void Window::initWindow(int width, int height, const char* title) {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return;
        }

        // Set the opengl version to opengl version 4.6 core
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);   // Window will not be visible during creation
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);  // Window will be resizeable

        // Create the window
        glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (glfwWindow == nullptr) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(glfwWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD" << std::endl;
            glfwTerminate();
            return;
        }

        // Add user input callbacks
        glfwSetCursorPosCallback(glfwWindow, UserInputs::mousePosCallback);
        glfwSetMouseButtonCallback(glfwWindow, UserInputs::mouseButtonCallback);
        glfwSetScrollCallback(glfwWindow, UserInputs::mouseScrollCallback);
        glfwSetKeyCallback(glfwWindow, UserInputs::keyCallback);

        // set the viewport to the size of the window
        glViewport(0, 0, width, height);
        glfwSetFramebufferSizeCallback(glfwWindow, [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        });

        // Set the window position to the middle of the screen
        const GLFWvidmode* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        if (vidMode != nullptr) {
            glfwSetWindowPos(glfwWindow,
                             (vidMode->width - width) / 2, (vidMode->height - height) / 2);
        }

        glfwSwapInterval(1);    // Enable v-sync: Sets max FPS to screen refresh rate

        glfwShowWindow(glfwWindow);
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
}
