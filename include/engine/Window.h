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
        static Window* instance;
        GLFWwindow* glfwWindow;
        int windowWidth;
        int windowHeight;
        const char* title;

        Window() {};

    public:
        static Window* getInstance();

        void init(int windowWidth, int windowHeight, const char* title);

        void startWindow();

        GLFWwindow *getGlfwWindow() const;

        int getWindowWidth() const;

        int getWindowHeight() const;
    };
}

#endif //window_H
