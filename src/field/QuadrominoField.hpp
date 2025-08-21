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
    QuadrominoColor color;

    DrawableBlock(bool isForeground, QuadrominoColor color)
        : isForeground(isForeground), color(color) {};
};

class QuadrominoField
{
public:
    std::vector<std::vector<DrawableBlock>> field;
    int width, height;
    void setBlock(int x, int y, QuadrominoColor color, bool isForeground);
    void stampPiece(Piece piece);
    void clear();

    QuadrominoField(int width, int height);
};