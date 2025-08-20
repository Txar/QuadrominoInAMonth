#include "DrawableField.hpp"

DrawableField::DrawableField(int width, int height, sf::Texture &blockTexture, int scale_factor, int block_size)
    : TetrominoField(width, height),
      buffer({(unsigned int)width * scale_factor * block_size, (unsigned int)height * scale_factor * block_size}),
      sprite(blockTexture),
      scale_factor(scale_factor),
      block_size(block_size)
{
    sprite.setScale({(float) scale_factor, (float) scale_factor});
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
                sprite.setTextureRect(sf::IntRect({block_size * ColorPosition(block.color), 0}, {block_size, block_size}));
                sprite.setPosition({(float)i * scale_factor * block_size, (float)j * scale_factor * block_size});
                buffer.draw(sprite);
            }
        }
    }
    buffer.display();
}