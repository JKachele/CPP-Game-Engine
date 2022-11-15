/*Project-------CPP_Game_Engine
 *File----------window.h
 *Author--------Justin Kachele
 *Date----------11/14/2022
 *License-------GNU GENERAL PUBLIC LICENSE
******************************************/
#ifndef window_H
#define window_H
#include "core.h"
#include "util/Color.h"

namespace GameEngine {
    class Window {
    public:
        static GLFWwindow* glfwWindow;
        static int windowWidth;
        static int windowHeight;

        static void initWindow(int width, int height, const char* title);
    };
}

#endif //window_H
