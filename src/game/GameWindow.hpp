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
        {0 / 2,   1.1111f},
        {10 / 2,  0.8333f},
        {20 / 2,  0.6666f},
        {40 / 2,  0.4777f},
        {80 / 2,  0.3777f},
        {120 / 2, 0.2777f},
        {160 / 2, 0.1888f},
        {200 / 2, 0.1388f},
        {240 / 2, 0.0925f},
        {300 / 2, 0.0641f},
        {380 / 2, 0.0427f},
        {460 / 2, 0.0277f},
        {540 / 2, 0.0183f},
        {620 / 2, 0.0114f},
        {700 / 2, 0.0098f},
        {800 / 2, 0.0084f},
        {900 / 2, 0.0072f},
        {1000 / 2, 0.0063f},
        {1500 / 2, 0.0052f},
        {2000 / 2, 0.0047f}
    };

    TextureLoader textureLoader;
    ShaderLoader shaderLoader;

    sf::Clock gravityClock;
    sf::Time currentGravityTickTime;

    PieceQueue pieceQueue;
    Piece currentPiece;

    Controller controller;

    bool attemptMovement(int x);
    // void attemptRotation(bool clockwise);
    void attemptRotationRight();
    void attemptRotationLeft();

    void drawGhostPiece();
    void performHardDrop();
    void executeGameTick();
    void dropNextPiece();
    GameWindow();
    ~GameWindow();

    int mainLoop();
};