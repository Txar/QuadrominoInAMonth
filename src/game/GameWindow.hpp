#pragma once

#include <SFML/Graphics.hpp>
#include "../assets/AssetManager.hpp"
#include "../piece/Piece.hpp"
#include "../field/DrawableField.hpp"
#include "../field/SimulationField.hpp"
#include "PieceQueue.hpp"
#include "Controller.hpp"

class TextureLoader
{
public:
    std::string blockAsset;
    sf::Texture block;

    TextureLoader();
    ~TextureLoader();
};

typedef std::pair<int, float> Level;

class GameWindow
{
public:
    sf::RenderWindow window;
    DrawableField field;
    SimulationField simulationField;
    Piece swapPiece;
    bool swapInitialized = false;
    bool swappedOnThisPiece = false;

    int piecesDropped = 0;
    int currentLevel = 0;
    std::vector<Level> levels = {
        {0 / 2, (1 / 0.016f) / 60},
        {10 / 2, (1 / 0.021f) / 60},
        {20 / 2, (1 / 0.026f) / 60},
        {40 / 2, (1 / 0.035f) / 60},
        {80 / 2, (1 / 0.046f) / 60},
        {120 / 2, (1 / 0.063f) / 60},
        {160 / 2, (1 / 0.087f) / 60},
        {200 / 2, (1 / 0.123f) / 60},
        {240 / 2, (1 / 0.177f) / 60},
        {300 / 2, (1 / 0.259f) / 60},
        {380 / 2, (1 / 0.388f) / 60},
        {460 / 2, (1 / 0.59f) / 60},
        {540 / 2, (1 / 0.92f) / 60},
        {620 / 2, (1 / 1.46f) / 60},
        {800 / 2, (1 / 2.36f) / 60},
    };

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