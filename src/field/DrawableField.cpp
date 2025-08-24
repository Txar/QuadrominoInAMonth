#include "DrawableField.hpp"
#include <iostream>
#include "../assets/AssetManager.hpp"

ShaderLoader::ShaderLoader()
{
    std::string blockShaderAsset = AssetManager::getAsset("shaders/BlockShader.frag");
    if (!blockShader.loadFromMemory(blockShaderAsset, sf::Shader::Type::Fragment))
    {
        std::cerr << "Failed to load block shader from memory!" << std::endl;
    }
    blockShader.setUniform("coloredLayerOffset", 8.0f);
    blockShader.setUniform("topLayerOffset", 16.0f);
    blockShader.setUniform("texture", sf::Shader::CurrentTexture);

    std::string ghostShaderAsset = AssetManager::getAsset("shaders/GhostShader.frag");
    if (!ghostShader.loadFromMemory(ghostShaderAsset, sf::Shader::Type::Fragment))
    {
        std::cerr << "Failed to load ghost shader from memory!" << std::endl;
    }
    ghostShader.setUniform("coloredLayerOffset", 8.0f);
    ghostShader.setUniform("topLayerOffset", 16.0f);
    ghostShader.setUniform("texture", sf::Shader::CurrentTexture);
    ghostShader.setUniform("opacity", 0.75f);

    std::string wallShaderAsset = AssetManager::getAsset("shaders/WallShader.frag");
    if (!wallShader.loadFromMemory(wallShaderAsset, sf::Shader::Type::Fragment))
    {
        std::cerr << "Failed to load wall shader from memory!" << std::endl;
    }
}

ShaderLoader::~ShaderLoader()
{
}

DrawableField::DrawableField(int width, int height, sf::Texture &blockTexture, ShaderLoader *shaderLoader, int scale_factor, int block_size)
    : QuadrominoField(width, height),
      buffer({(unsigned int)width * scale_factor * block_size, (unsigned int)height * scale_factor * block_size}),
      sprite(blockTexture),
      scale_factor(scale_factor),
      block_size(block_size),
      shaderLoader(shaderLoader)
{
    sprite.setScale({(float)scale_factor, (float)scale_factor});
}

void DrawableField::render()
{
    buffer.display();
}

void DrawableField::draw()
{
    int maxBlockHeight = getMaxBlockHeight();
    buffer.clear();
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            const DrawableBlock &block = field.at(i).at(j);
            if (block.isForeground)
            {
                sprite.setTextureRect(sf::IntRect({block_size * 0, 0}, {block_size, block_size}));
                sprite.setPosition({(float)i * scale_factor * block_size, (float)j * scale_factor * block_size});
                if (block.isStatic)
                buffer.draw(sprite, &shaderLoader->wallShader);
                else {
                    // shaderLoader->blockShader.setUniform("blockX", i);
                    shaderLoader->blockShader.setUniform("blockY", height - j);
                    shaderLoader->blockShader.setUniform("fieldHeight", maxBlockHeight);
                    // shaderLoader->blockShader.setUniform("fieldWidth", width);
                    shaderLoader->blockShader.setUniform("color", ColorPalette::currentPalette.getGlslColor(block.color));
                    // ColorPalette::currentPalette.getColor(block.color);
                    buffer.draw(sprite, &shaderLoader->blockShader);
                }
            }
        }
    }
}

void DrawableField::drawGhost(Piece ghostPiece)
{
    QuadrominoShape shape = ghostPiece.getCurrentRotation();
    for (int i = 0; i < shape.size(); i++)
    {
        for (int j = 0; j < shape.at(i).size(); j++)
        {
            if (shape.at(i).at(j))
            {
                shaderLoader->ghostShader.setUniform("color", ColorPalette::currentPalette.getGlslColor(ghostPiece.color));
                sprite.setTextureRect(sf::IntRect({block_size * 0, 0}, {block_size, block_size}));
                sprite.setPosition({(ghostPiece.x + (float)i) * scale_factor * block_size, (ghostPiece.y + (float)j) * scale_factor * block_size});
                buffer.draw(sprite, &shaderLoader->ghostShader);
            }
        }
    }
}

void DrawableField::drawPiece(Piece piece)
{
    QuadrominoShape shape = piece.getCurrentRotation();
    for (int i = 0; i < shape.size(); i++)
    {
        for (int j = 0; j < shape.at(i).size(); j++)
        {
            if (shape.at(i).at(j))
            {
                sprite.setTextureRect(sf::IntRect({block_size * 0, 0}, {block_size, block_size}));
                sprite.setPosition({(float)(piece.x + i) * scale_factor * block_size, (float)(piece.y + j) * scale_factor * block_size});
                // shaderLoader->blockShader.setUniform("blockX", i);
                shaderLoader->blockShader.setUniform("blockY", 0);
                shaderLoader->blockShader.setUniform("fieldHeight", height);
                // shaderLoader->blockShader.setUniform("fieldWidth", width);
                shaderLoader->blockShader.setUniform("color", ColorPalette::currentPalette.getGlslColor(piece.color));
                // ColorPalette::currentPalette.getColor(block.color);
                buffer.draw(sprite, &shaderLoader->blockShader);
            }
        }
    }
}

int DrawableField::getMaxBlockHeight() {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            if (!field.at(i).at(j).isStatic) {
                return height - j;
            }
        }
    }
    return 0;
}