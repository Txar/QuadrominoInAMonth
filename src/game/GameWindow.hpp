#pragma once

#include <SFML/Graphics.hpp>
#include "../assets/AssetManager.hpp"
#include "../piece/Piece.hpp"
#include "../field/DrawableField.hpp"
#include "../field/SimulationField.hpp"

class TextureLoader {
public:
    std::string blockAsset;
    sf::Texture block;

    TextureLoader();
    ~TextureLoader();
};

class GameWindow {
private:
    sf::RenderWindow window;
    DrawableField field;
    SimulationField simulationField;

    TextureLoader textureLoader;

    sf::Clock gravityClock;
    sf::Time currentGravityTickTime;

    Piece currentPiece;

    static void initializeAssets();

public:
    GameWindow();
    ~GameWindow();

    int mainLoop();
};