/*Project-------CPP_Game_Engine
 *File----------Texture.h
 *Author--------Justin Kachele
 *Date----------11/15/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/

#ifndef CPP_GAME_ENGINE_TEXTURE_H
#define CPP_GAME_ENGINE_TEXTURE_H
#include "core.h"

namespace GameEngine {

    class Texture {
        string filePath;
        unsigned int id;
        int width;
        int height;

    public:
        Texture(const string& filePath);

        void bind();

        void unbind();

        int getID() const;

        int getWidth() const;

        int getHeight() const;

    };

} // GameEngine

#endif //CPP_GAME_ENGINE_TEXTURE_H
