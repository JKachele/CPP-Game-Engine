/*Project-------CPP_Game_Engine
 *File----------ShaderParser.h
 *Author--------Justin Kachele
 *Date----------11/17/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include "render/Shader.h"

namespace GameEngine {
    Shader::Shader(std::string vertexShaderFile, std::string fragmentShaderFile) {
        this->vertexShaderFile = vertexShaderFile;
        this->fragmentShaderFile = fragmentShaderFile;

    }
}
