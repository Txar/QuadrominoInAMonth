#include "GameWindow.hpp"
#include <iostream>

TextureLoader::TextureLoader() {
    AssetManager::initialize();
    blockAsset = AssetManager::getAsset("sprites/block.png");
    block = sf::Texture(blockAsset.data(), blockAsset.size());
}

TextureLoader::~TextureLoader() {
    
}

GameWindow::GameWindow()
    : 
    textureLoader(),
    window(sf::VideoMode({(FIELD_WIDTH + 2) * BLOCK_SIZE * SCALE_FACTOR, (FIELD_HEIGHT + 2) * BLOCK_SIZE * SCALE_FACTOR}), "Tetromino In A Month by Txar"),
    field(FIELD_WIDTH + 2, FIELD_HEIGHT + 2, textureLoader.block, SCALE_FACTOR, BLOCK_SIZE), 
    simulationField(FIELD_WIDTH + 2, FIELD_HEIGHT + 2),
    currentPiece(Piece::I)
{
    window.setFramerateLimit(144);
    currentPiece.summon(6, 6);
    // field.blockTexture.reset();

    gravityClock = sf::Clock();
    currentGravityTickTime = sf::seconds(60 * 0.01667f);
}

int GameWindow::mainLoop() {
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            if (event->is<sf::Event::KeyPressed>())
            {
                
                sf::Keyboard::Key key = event->getIf<sf::Event::KeyPressed>()->code;
                switch (key) {
                    case (sf::Keyboard::Key::Left): {
                        currentPiece.x--;
                        break;
                    }
                    case (sf::Keyboard::Key::Right): {
                        currentPiece.x++;
                        break;
                    }
                    case (sf::Keyboard::Key::Up): {
                        currentPiece.rotateRight();
                        break;
                    }
                    case (sf::Keyboard::Key::RControl): {
                        currentPiece.rotateLeft();
                        break;
                    }
                    case (sf::Keyboard::Key::Num1): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(Piece::I);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num2): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(Piece::O);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num3): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(Piece::T);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num4): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(Piece::J);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num5): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(Piece::L);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num6): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(Piece::S);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num7): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(Piece::Z);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Escape): {
                        window.close();
                        return 0;
                    }
                    case (sf::Keyboard::Key::Down): {
                        Piece newPiece(currentPiece);
                        newPiece.y++;
                        if (simulationField.isValidPosition(newPiece))
                        {
                            currentPiece.y++;
                        }
                        else
                        {
                            simulationField.stampPiece(currentPiece);
                            currentPiece = Piece(Piece::I);
                            currentPiece.summon(6, 6);
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
        }

        // if (gravityClock.getElapsedTime() > currentGravityTickTime)
        // {
        //     Piece newPiece(currentPiece);
        //     newPiece.y++;
        //     if (simulationField.isValidPosition(newPiece))
        //     {
        //         currentPiece.y++;
        //     }
        //     else
        //     {
        //         simulationField.stampPiece(currentPiece);
        //         currentPiece = Piece(Piece::I);
        //         currentPiece.summon(6, 6);
        //     }

        //     gravityClock.restart();
        // }
        field.clear();
        field.field = simulationField.field;

        window.clear(sf::Color::Black);

        field.stampPiece(currentPiece);
        field.render();
        sf::Sprite s(field.buffer.getTexture());
        s.setPosition({0, 0});
        window.draw(s);

        window.display();
    }
    return -1;
}

GameWindow::~GameWindow() {
    // AssetManager::cleanup();
}