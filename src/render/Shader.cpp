/*Project-------CPP_Game_Engine
 *File----------ShaderParser.h
 *Author--------Justin Kachele
 *Date----------11/17/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include <fstream>
#include <iostream>
#include "render/Shader.h"

namespace GameEngine {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "LocalValueEscapesScope"
    Shader::Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) {
        std::ifstream vert{vertexShaderFile};
        std::ifstream frag{fragmentShaderFile};
        std::string vertexShaderString;
        std::string fragmentShaderString;

        if (!vert) {
            std::cerr << "Failed to open file " << vertexShaderFile << std::endl;
            return;
        }
        if (!frag) {
            std::cerr << "Failed to open file " << fragmentShaderFile << std::endl;
            return;
        }

        while (vert) {
            std::string line;
            std::getline(vert, line);
            if (line.empty()) continue;
            vertexShaderString += line;
            vertexShaderString += "\n";
        }
        vert.close();
        this->vertexShader = vertexShaderString.c_str();

        while (frag) {
            std::string line;
            std::getline(frag, line);
            if (line.empty()) continue;
            fragmentShaderString += line;
            fragmentShaderString += "\n";
        }
        frag.close();
        this->fragmentShader = fragmentShaderString.c_str();
    }
#pragma clang diagnostic pop

    void Shader::compile() {
        // =========================================================
        // Compile the shaders
        // =========================================================
        unsigned int vertexID;
        unsigned int fragmentID;

        // create a unique id for the vertex shader
        vertexID = glCreateShader(GL_VERTEX_SHADER);

        // Load and compile the vertex shader
        glShaderSource(vertexID, 1, &this->vertexShader, NULL);
        glCompileShader(vertexID);

        // Check for shader compile errors
        int success;
        glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // create a unique id for the fragment shader
        fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

        // Load and compile the fragment shader
        glShaderSource(fragmentID, 1, &this->fragmentShader, NULL);
        glCompileShader(fragmentID);

        // Check for shader compile errors
        glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // =========================================================
        // link the shaders
        // =========================================================
        this->shaderProgramID = glCreateProgram();
        glAttachShader(this->shaderProgramID, vertexID);
        glAttachShader(this->shaderProgramID, fragmentID);
        glLinkProgram(this->shaderProgramID);

        // Check for linking errors
        glGetProgramiv(this->shaderProgramID, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(this->shaderProgramID, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
    }

    void Shader::use() {
        glUseProgram(this->shaderProgramID);
    }

    void Shader::detach() {
        glUseProgram(0);
    }

    // =========================================================
    // Upload data types to the GPU
    // =========================================================
    void Shader::uploadInt(std::string &varName, int val) {
        int varLocation = glGetUniformLocation(this->shaderProgramID, varName.c_str());
        Shader::use();
        glUniform1i(varLocation, val);
    }

    void Shader::uploadIntArray(std::string &varName, int* array, int size) {
        int varLocation = glGetUniformLocation(this->shaderProgramID, varName.c_str());
        Shader::use();
        glUniform1iv(varLocation, size, array);
    }

    void Shader::uploadFloat(std::string &varName, float val) {
        int varLocation = glGetUniformLocation(this->shaderProgramID, varName.c_str());
        Shader::use();
        glUniform1f(varLocation, val);
    }

    void Shader::uploadVec2(std::string &varName, glm::vec2 vec2) {
        int varLocation = glGetUniformLocation(this->shaderProgramID, varName.c_str());
        Shader::use();
        glUniform2f(varLocation, vec2.x, vec2.y);
    }

    void Shader::uploadVec3(std::string &varName, glm::vec3 vec3) {
        int varLocation = glGetUniformLocation(this->shaderProgramID, varName.c_str());
        Shader::use();
        glUniform3f(varLocation, vec3.x, vec3.y, vec3.z);
    }

    void Shader::uploadVec4(std::string &varName, glm::vec4 vec4) {
        int varLocation = glGetUniformLocation(this->shaderProgramID, varName.c_str());
        Shader::use();
        glUniform4f(varLocation, vec4.x, vec4.y, vec4.z, vec4.w);
    }

    void Shader::uploadMat3(std::string &varName, glm::mat3 mat3) {
        int varLocation = glGetUniformLocation(this->shaderProgramID, varName.c_str());
        Shader::use();
        glUniformMatrix3fv(varLocation, 1, GL_FALSE, glm::value_ptr(mat3));
    }

    void Shader::uploadMat4(std::string &varName, glm::mat4 mat4) {
        int varLocation = glGetUniformLocation(this->shaderProgramID, varName.c_str());
        Shader::use();
        glUniformMatrix4fv(varLocation, 1, GL_FALSE, glm::value_ptr(mat4));
    }

    void Shader::uploadTexture(std::string &varName, int slot) {
        int varLocation = glGetUniformLocation(this->shaderProgramID, varName.c_str());
        Shader::use();
        glUniform1i(varLocation, slot);
    }
}