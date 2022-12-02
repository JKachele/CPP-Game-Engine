#version 460 core

in vec2 fUVCoords;
in vec4 fColor;

uniform sampler2D uTextures;

out vec4 color;

void main() {
    color = texture(uTextures, fUVCoords);
//    color = fColor;
}