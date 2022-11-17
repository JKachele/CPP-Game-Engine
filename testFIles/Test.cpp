/*Project-------CPP_Game_Engine
 *File----------Test.h
 *Author--------Justin Kachele
 *Date----------11/16/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include <iostream>
#include <fstream>

int main() {
    std::string vertexShaderFile = "../assets/shaders/defaultVert.glsl";

    std::ifstream vert{vertexShaderFile};

    if (!vert) {
        std::cerr << "Failed to open file " << vertexShaderFile << std::endl;
        return -1;
    }

    while (vert) {
        std::string vertexShader;
        vert >> vertexShader;
        std::cout << vertexShader << std::endl;
    }

}
