/*Project-------CPP_Game_Engine
 *File----------Texture.cpp
 *Author--------Justin Kachele
 *Date----------11/15/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#include "render/Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace GameEngine {

    Texture::Texture(const string& filePath) {

        glGenTextures(1, &id);
        glBindTexture(GL_TEXTURE_2D, id);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        stbi_set_flip_vertically_on_load(true);
        int nChannels;
        unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nChannels, 0);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        stbi_image_free(data);
    }

    void Texture::bind() {
        glBindTexture(GL_TEXTURE_2D, id);
    }

    void Texture::unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    int Texture::getID() const {
        return id;
    }

    int Texture::getWidth() const {
        return width;
    }

    int Texture::getHeight() const {
        return height;
    }

} // GameEngine
#pragma clang diagnostic pop