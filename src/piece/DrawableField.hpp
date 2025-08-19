#pragma once
#include "Color.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Piece.hpp"

const int SCALE_FACTOR = 4;
const int BLOCK_SIZE = 8;
const int FIELD_WIDTH = 10;
const int FIELD_HEIGHT = 20;
const int SCALED_BLOCK = BLOCK_SIZE * SCALE_FACTOR;

class DrawableBlock {
    public:
        bool isForeground;
        TetrominoColor color;

        DrawableBlock(bool isForeground, TetrominoColor color) 
        : isForeground(isForeground), color(color) {};
};

class DrawableField {
    public:
        std::vector<std::vector<DrawableBlock>> field;
        sf::RenderTexture buffer;
        sf::Sprite sprite;
        std::shared_ptr<sf::Texture> blockTexture;

        int width, height;

        void render();
        void clear();
        void setBlock(int x, int y, TetrominoColor color, bool isForeground);

        DrawableField(int width, int height, std::shared_ptr<sf::Texture> blockTexture);

        void stampPiece(Piece piece);
};