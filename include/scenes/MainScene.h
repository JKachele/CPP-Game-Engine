/*Project-------CPP_Game_Engine
 *File----------MainScene.h
 *Author--------Justin Kachele
 *Date----------11/17/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#ifndef CPP_GAME_ENGINE_MAINSCENE_H
#define CPP_GAME_ENGINE_MAINSCENE_H
#include "Scene.h"
#include "render/Shader.h"
#include "render/Texture.h"

namespace GameEngine {
    class MainScene : public Scene {
        unsigned int vaoID;
        unsigned int vboID;
        unsigned int eboID;
        Shader* defaultShader;
        Texture* texture1;
        Texture* texture2;

        float vertexArray[36] = {
                // Position                            // Color                                   // UV Coordinates
                -1.0f,  -1.0f,  0.0f,      1.0f, 0.0f,  0.0f,  1.0f,      0.0f, 0.0f,
                -1.0f,  1.0f, 0.0f,     0.0f, 1.0f, 0.0f, 1.0f,     0.0f, 1.0f,
                1.0f,  1.0f, 0.0f,     0.0f, 0.0f, 1.0f, 1.0f,     1.0f, 1.0f,
                1.0f, -1.0f, 0.0f,     1.0f, 1.0f, 1.0f, 1.0f,     1.0f, 0.0f,
        };

        int elementArray[6] = {
                0, 2, 1,
                0, 3, 2
        };

    public:
        void init();

        void update(float dt);
    };
}


#endif //CPP_GAME_ENGINE_MAINSCENE_H
