#include "DrawableField.hpp"

DrawableField::DrawableField(int width, int height, std::shared_ptr<sf::Texture> blockTexture)
    : blockTexture(blockTexture),
      buffer({(unsigned int)width * SCALED_BLOCK, (unsigned int)height * SCALED_BLOCK}),
      sprite(*blockTexture),
      width(width), height(height)
{
    sprite.setScale({SCALE_FACTOR, SCALE_FACTOR});
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

void DrawableField::render()
{
    buffer.clear();
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            const DrawableBlock &block = field.at(i).at(j);
            if (block.isForeground)
            {
                sprite.setTextureRect(sf::IntRect({BLOCK_SIZE * ColorPosition(block.color), 0}, {BLOCK_SIZE, BLOCK_SIZE}));
                sprite.setPosition({(float)i * SCALED_BLOCK, (float)j * SCALED_BLOCK});
                buffer.draw(sprite);
            }
        }
    }
    buffer.display();
}

void DrawableField::clear()
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

void DrawableField::setBlock(int x, int y, TetrominoColor color, bool isForeground)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
    {
        throw std::out_of_range("Coordinates out of bounds");
    }
    field.at(x).at(y) = DrawableBlock(isForeground, color);
}

void DrawableField::stampPiece(Piece piece)
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