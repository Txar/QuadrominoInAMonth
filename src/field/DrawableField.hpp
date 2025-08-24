#pragma once
#include "QuadrominoField.hpp"
#include <SFML/Graphics.hpp>

class ShaderLoader {
public:
    sf::Shader blockShader;
    sf::Shader ghostShader;
    sf::Shader wallShader;

    ShaderLoader();
    ~ShaderLoader();
};

class DrawableField : public QuadrominoField {
    private:
        int getMaxBlockHeight();

    public:
        sf::RenderTexture buffer;
        sf::Sprite sprite;
        int scale_factor;
        int block_size;
        ShaderLoader *shaderLoader;

        void draw();
        void render();
        void drawGhost(Piece ghostPiece);
        void drawPiece(Piece piece);

        DrawableField(int width, int height, sf::Texture &blockTexture, ShaderLoader *shaderLoader, int scale_factor, int block_size);
};