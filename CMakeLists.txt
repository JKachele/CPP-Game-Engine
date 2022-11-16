cmake_minimum_required(VERSION 3.23)
project(CPP_Game_Engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game_Engine src/main.cpp
        external/glad/src/glad.c
        src/engine/Window.cpp
        src/util/Color.cpp
        src/engine/Engine.cpp
        src/engine/UserInputs.cpp)
add_executable(Scratch testFiles/Test.cpp)
include_directories(include)
include_directories(include)
include_directories(external/glad/include)
include_directories(external/glfw/include)
include_directories(external/glm)

find_library(GLFW3 glfw3 external/glfw/lib)
find_library(GLFW3DLL glfw3dll external/glfw/lib)
target_link_libraries(Game_Engine LINK_PUBLIC ${GLFW3})
target_link_libraries(Game_Engine LINK_PUBLIC ${GLFW3dll})
