/*Project-------CPP_Game_Engine
 *File----------MainScene.h
 *Author--------Justin Kachele
 *Date----------11/17/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include "scenes/MainScene.h"

namespace GameEngine {

    void MainScene::init() {
        std::string defaultShaderVert = "../assets/shaders/defaultVert.glsl";
        std::string defaultShaderFrag = "../assets/shaders/defaultFrag.glsl";
        defaultShader = new Shader(defaultShaderVert, defaultShaderFrag);
        defaultShader->compile();

        // ============================================================
        // Generate VAO, VBO, and EBO buffer objects, and send to GPU
        // ============================================================
        glGenVertexArrays(1, &vaoID);
        glBindVertexArray(vaoID);

        glGenBuffers(1, &vboID);
        glBindBuffer(GL_ARRAY_BUFFER, vboID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray), vertexArray, GL_STATIC_DRAW);

        glGenBuffers(1, &eboID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elementArray), elementArray, GL_STATIC_DRAW);

        // Add the vertex Attribute pointers
        int posSize = 3;
        int colorSize = 4;
        int uvCoordsSize = 2;
        int vertexSizeBytes = (posSize + colorSize + uvCoordsSize) * sizeof(float);

        glVertexAttribPointer(0, posSize, GL_FLOAT, false, vertexSizeBytes, 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, colorSize, GL_FLOAT, false, vertexSizeBytes, (void*)(posSize * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, uvCoordsSize, GL_FLOAT, false, vertexSizeBytes,
                              (void*)((posSize + colorSize) * sizeof(float)));
        glEnableVertexAttribArray(2);
    }

    void MainScene::update(float dt) {
        defaultShader->use();

        glBindVertexArray(vaoID);

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);

        glBindVertexArray(0);
        defaultShader->detach();
    }
}