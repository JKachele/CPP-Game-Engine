/*Project-------CPP_Game_Engine
 *File----------UserCallbacks.h
 *Author--------Justin Kachele
 *Date----------11/16/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#ifndef CPP_GAME_ENGINE_USERINPUTS_H
#define CPP_GAME_ENGINE_USERINPUTS_H
#include "core.h"

namespace GameEngine {
    namespace UserInputs {
        extern double scrollX;
        extern double scrollY;
        extern double posX;
        extern double posY;
        extern double lastPosX;
        extern double lastPosY;
        extern bool mouseButtonDown[9];
        extern int mouseButtonsDown;
        extern bool isDragging;
        extern bool keyPressed[350];
        extern bool keyBeginPressed[350];

        void mousePosCallback(GLFWwindow* window, double posX, double posY);

        void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

        void mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

        void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

        bool isKeyPressed(int key);

        bool keyBeginPress(int key);

        void endFrame();
    }
}

#endif //CPP_GAME_ENGINE_USERINPUTS_H
