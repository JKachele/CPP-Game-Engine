/*Project-------CPP_Game_Engine
 *File----------Scene.h
 *Author--------Justin Kachele
 *Date----------11/17/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#ifndef CPP_GAME_ENGINE_SCENE_H
#define CPP_GAME_ENGINE_SCENE_H

class Scene {
public:
    Scene();

    virtual void update(float dt) = 0;
};


#endif //CPP_GAME_ENGINE_SCENE_H
