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
    Scene* Window::currentScene = 0;

    Window* Window::getInstance() {     // Singleton instance
        if (!instance) {
            instance = new Window();
        }
        return instance;
    }

    void Window::init(int windowWidth, int windowHeight, const char* title) {
        this->windowWidth = windowWidth;
        this->windowHeight = windowHeight;
        this->title = title;
    }

    void Window::startWindow() {
        if (!glfwInit()) {
            cerr << "Failed to initialize GLFW" << endl;
            return;
        }

        // Set the opengl version to opengl version 4.6 core
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);   // Window will not be visible during creation
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);  // Window will be resizeable

        // Create the window
        glfwWindow = glfwCreateWindow(windowWidth, windowHeight, title, nullptr, nullptr);
        if (glfwWindow == nullptr) {
            cerr << "Failed to create GLFW window" << endl;
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(glfwWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            cerr << "Failed to initialize GLAD" << endl;
            glfwTerminate();
            return;
        }

        // Add user input callbacks
        glfwSetCursorPosCallback(glfwWindow, UserInputs::mousePosCallback);
        glfwSetMouseButtonCallback(glfwWindow, UserInputs::mouseButtonCallback);
        glfwSetScrollCallback(glfwWindow, UserInputs::mouseScrollCallback);
        glfwSetKeyCallback(glfwWindow, UserInputs::keyCallback);

        // set the viewport to the size of the window
        glViewport(0, 0, windowWidth, windowHeight);
        glfwSetFramebufferSizeCallback(glfwWindow, [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        });

        // Set the window position to the middle of the screen
        const GLFWvidmode* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        if (vidMode != nullptr) {
            glfwSetWindowPos(glfwWindow,
                             (vidMode->width - windowWidth) / 2, (vidMode->height - windowHeight) / 2);
        }

        glfwSwapInterval(1);    // Enable v-sync: Sets max FPS to screen refresh rate

        glfwShowWindow(glfwWindow);
        changeScene(0);
    }

    void Window::changeScene(int scene) {
        switch(scene) {
            case 0:
                currentScene = new MainScene();
                currentScene->init();
                break;
        }
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

    Scene* Window::getCurrentScene() {
        return currentScene;
    }
}
