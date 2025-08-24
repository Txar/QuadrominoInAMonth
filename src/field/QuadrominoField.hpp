#pragma once

#include "../piece/Color.hpp"
#include "../piece/Piece.hpp"

const int SCALE_FACTOR = 4;
const int BLOCK_SIZE = 8;
const int FIELD_WIDTH = 12;
const int FIELD_HEIGHT = 24;
const int SCALED_BLOCK = BLOCK_SIZE * SCALE_FACTOR;

class DrawableBlock
{
public:
    bool isForeground;
    bool isStatic;;
    ColorIndex color;

    DrawableBlock(bool isForeground, ColorIndex color, bool isStatic = false)
        : isForeground(isForeground), color(color), isStatic(isStatic) {};
};

class QuadrominoField
{
public:
    std::vector<std::vector<DrawableBlock>> field;
    int width, height;
    void setBlock(int x, int y, ColorIndex color, bool isForeground);
    void stampPiece(Piece piece);
    void clear();

    QuadrominoField(int width, int height);
};