#pragma once

#include "../piece/Color.hpp"
#include "../piece/Piece.hpp"

const int SCALE_FACTOR = 4;
const int BLOCK_SIZE = 8;
const int FIELD_WIDTH = 10;
const int FIELD_HEIGHT = 20;
const int SCALED_BLOCK = BLOCK_SIZE * SCALE_FACTOR;

class DrawableBlock
{
public:
    bool isForeground;
    TetrominoColor color;

    DrawableBlock(bool isForeground, TetrominoColor color)
        : isForeground(isForeground), color(color) {};
};

class TetrominoField
{
public:
    std::vector<std::vector<DrawableBlock>> field;
    int width, height;
    void setBlock(int x, int y, TetrominoColor color, bool isForeground);
    void stampPiece(Piece piece);
    void clear();

    TetrominoField(int width, int height);
};