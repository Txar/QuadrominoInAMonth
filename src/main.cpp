#include <SFML/Graphics.hpp>
#include "assets/AssetManager.hpp"
#include "piece/Piece.hpp"
#include "piece/DrawableField.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({(FIELD_WIDTH + 2) * BLOCK_SIZE * SCALE_FACTOR, (FIELD_HEIGHT + 2) * BLOCK_SIZE * SCALE_FACTOR}), "CMake SFML Project");
    window.setFramerateLimit(144);

    AssetManager::initialize();
    std::string blockAsset = AssetManager::getAsset("sprites/block.png");
    sf::Texture block(blockAsset.data(), blockAsset.size());
    sf::Sprite blockSprite(block);
    blockSprite.setScale({SCALE_FACTOR, SCALE_FACTOR});
    blockSprite.setTextureRect(sf::IntRect({BLOCK_SIZE * 7, 0}, {BLOCK_SIZE, BLOCK_SIZE}));

    Piece currentPiece(PredefinedPiece::I);

    currentPiece.summon(6, 6);

    DrawableField field(FIELD_WIDTH + 2, FIELD_HEIGHT + 2, std::make_shared<sf::Texture>(block));

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
                        currentPiece = Piece(PredefinedPiece::I);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num2): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(PredefinedPiece::O);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num3): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(PredefinedPiece::T);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num4): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(PredefinedPiece::J);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num5): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(PredefinedPiece::L);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num6): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(PredefinedPiece::S);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    case (sf::Keyboard::Key::Num7): {
                        int x = currentPiece.x;
                        int y = currentPiece.y;
                        int r = currentPiece.rotationIndex;
                        currentPiece = Piece(PredefinedPiece::Z);
                        currentPiece.summon(x, y);
                        currentPiece.rotationIndex = r;
                        break;
                    }
                    default:
                        break;
                }
            }
        }

        window.clear(sf::Color::Black);

        // for (int i = 0; i < FIELD_WIDTH + 2; i++)
        // {
        //     for (int j = 0; j < FIELD_HEIGHT + 2; j++)
        //     {
        //         int x = i * BLOCK_SIZE * SCALE_FACTOR;
        //         int y = j * BLOCK_SIZE * SCALE_FACTOR;
        //         blockSprite.setPosition({(float) x, (float) y });
        //         window.draw(blockSprite);
        //     }
        // }
        field.clear();
        field.stampPiece(currentPiece);
        field.render();
        sf::Sprite s(field.buffer.getTexture());
        s.setPosition({0, 0});
        window.draw(s);

        window.draw(blockSprite);
        window.display();
    }
}
