/*Project-------CPP_Game_Engine
 *File----------Engine.h
 *Author--------Justin Kachele
 *Date----------11/15/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include "engine/Engine.h"
#include "engine/Window.h"

namespace GameEngine {
    void printFPS(uint64_t dt);
    void gameLoop();

    void Engine::initEngine(int width, int height, const char *title, GameEngine::Color color) {
        backgroundColor = color;
        Window::initWindow(width, height, title);
    }

    uint64_t getCurrentTime() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }

    void Engine::run() {
        gameLoop();
    }

    void Engine::terminate() {
        glfwTerminate();
    }

    void gameLoop() {
        uint64_t beginTime = getCurrentTime();
        uint64_t endTime;
        int dt = -1;

        glClearColor(Engine::backgroundColor.r, Engine::backgroundColor.g,
                     Engine::backgroundColor.b, Engine::backgroundColor.a);

        while(!glfwWindowShouldClose(Window::glfwWindow)) {

            glfwPollEvents();

            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(Window::glfwWindow);

            printFPS(dt);

            endTime = getCurrentTime();
            dt = endTime - beginTime;
            beginTime = endTime;
        }
    }

    void printFPS(uint64_t dt) {
        std::cout << 1 / dt << " FPS" << std::endl;
    }
}
