/*Project-------CPP_Game_Engine
 *File----------UserCallbacks.h
 *Author--------Justin Kachele
 *Date----------11/16/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include "engine/UserInputs.h"

namespace GameEngine {
    namespace UserInputs {
        double scrollX = 0.0f;
        double scrollY = 0.0f;
        double posX = 0.0f;
        double posY = 0.0f;
        double lastPosX = 0.0f;
        double lastPosY = 0.0f;
        bool mouseButtonDown[9] = {};
        int mouseButtonsDown = 0;
        bool isDragging = false;
        bool keyPressed[350] = {};
        bool keyBeginPressed[350] = {};

        void mousePosCallback(GLFWwindow *window, double mousePosX, double mousePosY) {
            if (mouseButtonsDown > 0) {
                isDragging = true;
            }

            lastPosX = posX;
            lastPosY = posY;
            posX = mousePosX;
            posY = mousePosY;
        }

        void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
            if (action == GLFW_PRESS) {
                mouseButtonsDown++;
                if (button < sizeof(mouseButtonDown) / sizeof(mouseButtonDown[0] && button >= 0)) {
                    mouseButtonDown[button] = true;
                }
            } else if (action == GLFW_RELEASE) {
                mouseButtonsDown--;
                if (button < sizeof(mouseButtonDown) / sizeof(mouseButtonDown[0] && button >= 0)) {
                    mouseButtonDown[button] = false;
                    isDragging = false;
                }
            }
        }

        void mouseScrollCallback(GLFWwindow *window, double xOffset, double yOffset) {
            scrollX = xOffset;
            scrollY = yOffset;
        }

        void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
            if (action == GLFW_PRESS) {
                if (key < sizeof(keyPressed) / sizeof(keyPressed[0]) && key >= 0) {
                    keyPressed[key] = true;
                    keyBeginPressed[key] = true;
                }
            } else if (action == GLFW_RELEASE) {
                if (key < sizeof(keyPressed) / sizeof(keyPressed[0]) && key >= 0) {
                    keyPressed[key] = false;
                    keyBeginPressed[key] = false;
                }
            }
        }

        bool isKeyPressed(int key) {
            if (key < sizeof(keyPressed) / sizeof(keyPressed[0]) && key >= 0) {
                return keyPressed[key];
            } else {
                std::cerr << "Invalid Key Pressed!" << std::endl;
                return false;
            }
        }

        bool keyBeginPress(int key) {
            if (key < sizeof(keyPressed) / sizeof(keyPressed[0]) && key >= 0) {
                bool result = keyBeginPressed[key];
                if (result) {
                    keyBeginPressed[key] = false;
                }
                return result;
            } else {
                std::cerr << "Invalid Key Pressed!" << std::endl;
                return false;
            }
        }

        void endFrame() {
            scrollX = 0.0f;
            scrollY = 0.0f;
            lastPosX = posX;
            lastPosY = posY;
        }
    }
}
