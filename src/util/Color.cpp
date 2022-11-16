/*Project-------CPP_Game_Engine
 *File----------Color.h
 *Author--------Justin Kachele
 *Date----------11/15/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include "util/Color.h"

namespace GameEngine {
    glm::vec4 Color::toVector() const{
        glm::vec4 vector{r, g, b, a};
        return vector;
    }
}
