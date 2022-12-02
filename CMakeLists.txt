cmake_minimum_required(VERSION 3.23)
project(CPP_Game_Engine)

set(CMAKE_CXX_STANDARD 14)

set(EXTERNAL external/glad/src/glad.c)
set(SOURCE_FILES
        src/main.cpp
        include/core.h
        src/engine/Window.cpp
        include/engine/Window.h
        src/util/Color.cpp
        include/util/Color.h
        src/engine/Engine.cpp
        include/engine/Engine.h
        src/engine/UserInputs.cpp
        include/engine/UserInputs.h
        src/scenes/Scene.cpp
        include/scenes/Scene.h
        src/scenes/MainScene.cpp
        include/scenes/MainScene.h
        src/render/Shader.cpp
        include/render/Shader.h
        src/render/Texture.cpp
        include/render/Texture.h)

add_executable(Game_Engine ${SOURCE_FILES} ${EXTERNAL})
include_directories(include)
include_directories(include)
include_directories(external/glad/include)
include_directories(external/glfw/include)
include_directories(external/glm)
include_directories(external/stbi)

target_link_libraries(Game_Engine LINK_PUBLIC dl)
target_link_libraries(Game_Engine LINK_PUBLIC glfw)
