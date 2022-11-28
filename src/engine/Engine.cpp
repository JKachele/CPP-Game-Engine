/*Project-------CPP_Game_Engine
 *File----------Engine.h
 *Author--------Justin Kachele
 *Date----------11/15/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include "engine/Engine.h"
#include "engine/Window.h"
#include "engine/UserInputs.h"

namespace GameEngine {
    Engine::Engine(int width, int height, const char* title, GameEngine::Color color) : backgroundColor(color){
        window = Window::getInstance();
        window->init(width, height, title);
        window->startWindow();
    }

    void Engine::run() {
        gameLoop();
    }

    void Engine::terminate() {
        glfwTerminate();
        window->terminateWindow();
    }

    void Engine::gameLoop() {
        float beginTime = glfwGetTime();
        float endTime;
        float dt = -1;

        glClearColor(backgroundColor.r, backgroundColor.g,
                     backgroundColor.b, backgroundColor.a);     // Sets the background color of the screen

        while(!glfwWindowShouldClose(window->getGlfwWindow())) {

            glfwPollEvents();       // looks or events like a mouse or keyboard being pressed

            glClear(GL_COLOR_BUFFER_BIT);       // Sets the color of the screen to be updated

            if (dt >= 0) {
                window->getCurrentScene()->update(dt);
            }

            glfwSwapBuffers(window->getGlfwWindow());   // Render the new frame to the window

            UserInputs::endFrame();

            endTime = glfwGetTime();        // Calculate the tine to render a frame (Framerate)
            dt = endTime - beginTime;
            beginTime = endTime;
        }
    }
}
