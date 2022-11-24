/*Project-------CPP_Game_Engine
 *File----------Main.h
 *Author--------Justin Kachele
 *Date----------11/15/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include "engine/Engine.h"

using namespace GameEngine;

const int WIDTH = 1920;
const int HEIGHT = 1080;
const char* TITLE = "Game Engine";
const Color BACKGROUND_COLOR = Colors::PURPLE;

int main() {
    Engine engine{WIDTH, HEIGHT, TITLE, BACKGROUND_COLOR};
    engine.run();
    engine.terminate();
    return 0;
}
