#pragma once

#include <SFML/Graphics.hpp>
#include "../assets/AssetManager.hpp"
#include "../piece/Piece.hpp"
#include "../field/DrawableField.hpp"
#include "../field/SimulationField.hpp"
#include "PieceQueue.hpp"
#include "Controller.hpp"

class TextureLoader {
public:
    std::string blockAsset;
    sf::Texture block;

    TextureLoader();
    ~TextureLoader();
};

class GameWindow {
public:
    sf::RenderWindow window;
    DrawableField field;
    SimulationField simulationField;

    TextureLoader textureLoader;

    sf::Clock gravityClock;
    sf::Time currentGravityTickTime;

    PieceQueue pieceQueue;
    Piece currentPiece;

    Controller controller;

    bool attemptMovement(int x);
    bool attemptRotation(bool clockwise);

    void executeGameTick();
    void dropNextPiece();
    GameWindow();
    ~GameWindow();

    int mainLoop();
};