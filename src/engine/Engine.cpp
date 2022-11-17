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
    }

    void Engine::gameLoop() {
        float beginTime = glfwGetTime();
        float endTime;
        float dt = -1;

        glClearColor(backgroundColor.r, backgroundColor.g,
                     backgroundColor.b, backgroundColor.a);

        while(!glfwWindowShouldClose(window->getGlfwWindow())) {

            glfwPollEvents();

            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window->getGlfwWindow());

            UserInputs::endFrame();

            endTime = glfwGetTime();
            dt = endTime - beginTime;
            beginTime = endTime;
        }
    }
}
