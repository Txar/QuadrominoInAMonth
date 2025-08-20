#include "TetrominoField.hpp"
#include <stdexcept>

TetrominoField::TetrominoField(int width, int height)
    : width(width), height(height)
{
    for (int i = 0; i < width; i++)
    {
        field.push_back({});
        for (int j = 0; j < height; j++)
        {
            field.at(i).push_back(DrawableBlock(
                i == 0 || i == width - 1 || j == 0 || j == height - 1, GRAY));
        }
    }
}

void TetrominoField::clear()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            field.at(i).at(j) = (DrawableBlock(
                i == 0 || i == width - 1 || j == 0 || j == height - 1, GRAY));
        }
    }
}

void TetrominoField::setBlock(int x, int y, TetrominoColor color, bool isForeground)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
    {
        throw std::out_of_range("Coordinates out of bounds");
    }
    field.at(x).at(y) = DrawableBlock(isForeground, color);
}

void TetrominoField::stampPiece(Piece piece)
{
    TetrominoShape shape = piece.getCurrentRotation();
    for (int i = 0; i < shape.size(); i++)
    {
        for (int j = 0; j < shape[i].size(); j++)
        {
            if (shape[i][j])
            {
                setBlock(piece.x + i, piece.y + j, piece.color, true);
            }
        }
    }
}