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
    struct Engine {
        static Color backgroundColor;

        static void initEngine(int width, int height, const char *title, Color backgroundColor);
        static void run();
        static void terminate();
    };
}
#endif //CPP_GAME_ENGINE_ENGINE_H
