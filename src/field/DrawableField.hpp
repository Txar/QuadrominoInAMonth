#pragma once
#include "TetrominoField.hpp"
#include <SFML/Graphics.hpp>

class DrawableField : public TetrominoField {
    public:
        sf::RenderTexture buffer;
        sf::Sprite sprite;
        int scale_factor;
        int block_size;

        void render();

        DrawableField(int width, int height, sf::Texture &blockTexture, int scale_factor, int block_size);
};