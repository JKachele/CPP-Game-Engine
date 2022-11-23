/*Project-------CPP_Game_Engine
 *File----------Test.h
 *Author--------Justin Kachele
 *Date----------11/16/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include <iostream>
#include <glm/mat4x4.hpp>

int main() {
    glm::mat4x4 mat{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    std::cout << mat[1][0] << std::endl;
}
