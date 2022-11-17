/*Project-------CPP_Game_Engine
 *File----------ShaderParser.h
 *Author--------Justin Kachele
 *Date----------11/17/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#ifndef CPP_GAME_ENGINE_SHADER_H
#define CPP_GAME_ENGINE_SHADER_H
#include <string>
#include <glm/mat4x4.hpp>
#include <glm/mat3x3.hpp>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace GameEngine {
    class Shader {
        int shaderProgramID;
        std::string vertexShaderFile;
        std::string vertexShader;
        std::string fragmentShaderFile;
        std::string fragmentShader;

    public:
        Shader(std::string vertexShaderFile, std::string fragmentShaderFile);

        void compile();

        void use();
        void detach();

        void uploadMat4(std::string varName, glm::mat4x4 mat4);
        void uploadMat3(std::string varName, glm::mat3x3 mat3);
        void uploadVec4(std::string varName, glm::vec4 vec4);
        void uploadVec3(std::string varName, glm::vec3 vec3);
        void uploadVec2(std::string varName, glm::vec2 vec2);
        void uploadFloat(std::string varName, float val);
        void uploadInt(std::string varName, int val);
        void uploadIntArray(std::string varName, int vals[]);
        void uploadTexture(std::string varName, int slot);
    };
}

#endif //CPP_GAME_ENGINE_SHADER_H
