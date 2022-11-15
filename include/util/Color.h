/*Project-------CPP_Game_Engine
 *File----------Color.h
 *Author--------Justin Kachele
 *Date----------11/15/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#ifndef CPP_GAME_ENGINE_COLOR_H
#define CPP_GAME_ENGINE_COLOR_H
#include <glm/vec4.hpp>

namespace GameEngine {
    class Color {
    public:
        float r;
        float g;
        float b;
        float a;

        glm::vec4 toVector();
    };
}

#endif //CPP_GAME_ENGINE_COLOR_H
