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

        glm::vec4 toVector() const;
    };

    namespace Colors {
        const Color WHITE       {1.0f,  1.0f,  1.0f,  1.0f};
        const Color LIGHT_GRAY  {0.75f, 0.75f, 0.75f, 1.0f};
        const Color GRAY        {0.5f,  0.5f,  0.5f,  1.0f};
        const Color DARK_GRAY   {0.25f, 0.25f, 0.25f, 1.0f};
        const Color BLACK       {0.0f,  0.0f,  0.0f,  1.0f};
        const Color RED         {1.0f,  0.0f,  0.0f,  1.0f};
        const Color GREEN       {0.0f,  1.0f,  0.0f,  1.0f};
        const Color BLUE        {0.0f,  0.0f,  1.0f,  1.0f};
        const Color YELLOW      {1.0f,  1.0f,  0.0f,  1.0f};
        const Color CYAN        {0.0f,  1.0f,  1.0f,  1.0f};
        const Color MAGENTA     {1.0f,  0.0f,  1.0f,  1.0f};
        const Color ORANGE      {1.0f,  0.8f,  0.0f,  1.0f};
        const Color PURPLE      {0.5f,  0.0f,  0.5f,  1.0f};
        const Color PINK        {1.0f,  0.7f,  0.7f,  1.0f};
    }
}

#endif //CPP_GAME_ENGINE_COLOR_H
