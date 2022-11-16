/*Project-------CPP_Game_Engine
 *File----------Main.h
 *Author--------Justin Kachele
 *Date----------11/15/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include "engine/Engine.h"
#include "util/Color.h"

using namespace GameEngine;

const int WIDTH = 1920;
const int HEIGHT = 1080;
const char* TITLE = "Game Engine";
const Color BACKGROUND_COLOR{1.0f, 1.0f, 0.0f, 1.0f};

int main() {
    Engine::initEngine(WIDTH, HEIGHT, TITLE, BACKGROUND_COLOR);
    Engine::run();
    Engine::terminate();
    return 0;
}
