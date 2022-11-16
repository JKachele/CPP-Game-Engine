/*Project-------CPP_Game_Engine
 *File----------Engine.h
 *Author--------Justin Kachele
 *Date----------11/15/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#ifndef CPP_GAME_ENGINE_ENGINE_H
#define CPP_GAME_ENGINE_ENGINE_H
#include "core.h"
#include "util/Color.h"
#include "Window.h"

namespace GameEngine {
    class Engine {
        Window* window;
        Color backgroundColor;

    public:
        Engine(int width, int height, const char* title, Color backgroundColor);
        void run();
        void terminate();

    private:
        void gameLoop();
    };
}
#endif //CPP_GAME_ENGINE_ENGINE_H
