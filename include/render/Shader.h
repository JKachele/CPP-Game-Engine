/*Project-------CPP_Game_Engine
 *File----------ShaderParser.h
 *Author--------Justin Kachele
 *Date----------11/17/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#ifndef CPP_GAME_ENGINE_SHADER_H
#define CPP_GAME_ENGINE_SHADER_H
#include <valarray>
#include <array>
#include "core.h"

namespace GameEngine {
    class Shader {
        unsigned int shaderProgramID;
        const char* vertexShader;
        const char* fragmentShader;

    public:
        Shader(const string& vertexShaderFile, const string& fragmentShaderFile);

        void compile();

        void use();
        void detach();

        void uploadInt(const string &varName, const int val);
        template<std::size_t size>
        void uploadIntArray(const string &varName, const std::array<int, size> &array);
        void uploadFloat(const string &varName, const float val);
        void uploadVec2(const string &varName, const glm::vec2 vec2);
        void uploadVec3(const string &varName, const glm::vec3 vec3);
        void uploadVec4(const string &varName, const glm::vec4 vec4);
        void uploadMat3(const string &varName, const glm::mat3 mat3);
        void uploadMat4(const string &varName, const glm::mat4 mat4);
        void uploadTexture(const string &varName, const int slot);
    };
}

#endif //CPP_GAME_ENGINE_SHADER_H
