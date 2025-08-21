#include "GameWindow.hpp"
#include <iostream>

TextureLoader::TextureLoader()
{
    AssetManager::initialize();
    blockAsset = AssetManager::getAsset("sprites/block.png");
    block = sf::Texture(blockAsset.data(), blockAsset.size());
}

TextureLoader::~TextureLoader()
{
}

void GameWindow::dropNextPiece()
{
    swappedOnThisPiece = false;
    currentPiece = pieceQueue.getNextPiece();
    currentPiece.summon(FIELD_WIDTH / 2 - 1, 1);
    piecesDropped++;
    int index = 0;
    for (Level i : levels)
    {
        if (simulationField.clearedLines >= i.first)
        {
            currentGravityTickTime = sf::seconds(i.second);
            currentLevel = index;
        }
        index++;
    }
    std::cout << "Line clears: " << simulationField.clearedLines << ", pieces dropped: " << piecesDropped << ", current level: " << currentLevel << ", gravity tick time: " << currentGravityTickTime.asSeconds() << " seconds" << std::endl;
}

void GameWindow::performHardDrop()
{
    while (simulationField.isValidPosition(currentPiece))
    {
        currentPiece.y++;
    }
    currentPiece.y--;
    simulationField.stampPiece(currentPiece);
    dropNextPiece();
}

void GameWindow::drawGhostPiece() {
    Piece ghostPiece(currentPiece);
    ghostPiece.color = QuadrominoColor::GHOST;
    while (simulationField.isValidPosition(ghostPiece))
    {
        ghostPiece.y++;
    }
    ghostPiece.y--;
    field.stampPiece(ghostPiece);
}

void GameWindow::executeGameTick()
{
    Piece newPiece(currentPiece);
    newPiece.y++;
    if (simulationField.isValidPosition(newPiece))
    {
        currentPiece.y++;
    }
    else
    {
        simulationField.stampPiece(currentPiece);
        dropNextPiece();
    }
}

bool GameWindow::attemptMovement(int x)
{
    Piece newPiece(currentPiece);
    newPiece.x += x;
    if (simulationField.isValidPosition(newPiece))
    {
        currentPiece.x += x;
        return true;
    }
    else
    {
        return false;
    }
}

bool GameWindow::attemptRotation(bool clockwise)
{
    Piece newPiece(currentPiece);
    if (clockwise)
    {
        newPiece.rotateRight();
    }
    else
    {
        newPiece.rotateLeft();
    }

    if (simulationField.isValidPosition(newPiece))
    {
        currentPiece = newPiece;
        return true;
    }
    else
    {
        return false;
    }
}

GameWindow::GameWindow()
    : textureLoader(),
      window(sf::VideoMode({(FIELD_WIDTH + 2) * BLOCK_SIZE * SCALE_FACTOR, (FIELD_HEIGHT + 2) * BLOCK_SIZE * SCALE_FACTOR}), "Quadromino In A Month by Txar"),
      field(FIELD_WIDTH + 2, FIELD_HEIGHT + 2, textureLoader.block, SCALE_FACTOR, BLOCK_SIZE),
      simulationField(FIELD_WIDTH + 2, FIELD_HEIGHT + 2),
      pieceQueue(),
      currentPiece(pieceQueue.getNextPiece()),
      controller(this),
      swapPiece(Piece::I)
{
    window.setFramerateLimit(144);
    currentPiece.summon(FIELD_WIDTH / 2 - 1, 1);

    gravityClock = sf::Clock();
    currentGravityTickTime = sf::seconds((1 / 0.01667f) / 60);
}

int GameWindow::mainLoop()
{
    while (window.isOpen())
    {
        controller.pollEvents();
        GameState state = controller.handleEvents();
        if (state == GameState::Exit)
        {
            return 0;
        }
        if (gravityClock.getElapsedTime() > currentGravityTickTime)
        {
            executeGameTick();
            gravityClock.restart();
        }

        field.clear();
        field.field = simulationField.field;

        window.clear(sf::Color::Black);

        drawGhostPiece();
        field.stampPiece(currentPiece);
        field.render();
        sf::Sprite s(field.buffer.getTexture());
        s.setPosition({0, 0});
        window.draw(s);

        window.display();
    }
    return -1;
}

GameWindow::~GameWindow()
{
    // AssetManager::cleanup();
}