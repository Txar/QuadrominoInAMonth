#include "Controller.hpp"
#include "GameWindow.hpp"

Controller::Controller(GameWindow *gameWindow)
    : gameWindow(gameWindow)
{
}

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::appendEvent(EventType event)
{
    eventQueue.push_back(event);
}

void Controller::pollEvents()
{
    sf::RenderWindow *window = &gameWindow->window;
    Piece &currentPiece = gameWindow->currentPiece;
    while (const std::optional event = window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window->close();
        }
        if (event->is<sf::Event::KeyPressed>())
        {

            sf::Keyboard::Key key = event->getIf<sf::Event::KeyPressed>()->code;
            switch (key)
            {
            case (sf::Keyboard::Key::Left):
            {
                appendEvent(EventType::MoveLeft);
                break;
            }
            case (sf::Keyboard::Key::Right):
            {
                appendEvent(EventType::MoveRight);
                break;
            }
            case (sf::Keyboard::Key::Up):
            {
                appendEvent(EventType::RotateRight);
                break;
            }
            case (sf::Keyboard::Key::RControl):
            {
                appendEvent(EventType::RotateLeft);
                break;
            }
            case (sf::Keyboard::Key::Num1):
            {
                int x = currentPiece.x;
                int y = currentPiece.y;
                int r = currentPiece.rotationIndex;
                currentPiece = Piece(Piece::I);
                currentPiece.summon(x, y);
                currentPiece.rotationIndex = r;
                break;
            }
            case (sf::Keyboard::Key::Num2):
            {
                int x = currentPiece.x;
                int y = currentPiece.y;
                int r = currentPiece.rotationIndex;
                currentPiece = Piece(Piece::O);
                currentPiece.summon(x, y);
                currentPiece.rotationIndex = r;
                break;
            }
            case (sf::Keyboard::Key::Num3):
            {
                int x = currentPiece.x;
                int y = currentPiece.y;
                int r = currentPiece.rotationIndex;
                currentPiece = Piece(Piece::T);
                currentPiece.summon(x, y);
                currentPiece.rotationIndex = r;
                break;
            }
            case (sf::Keyboard::Key::Num4):
            {
                int x = currentPiece.x;
                int y = currentPiece.y;
                int r = currentPiece.rotationIndex;
                currentPiece = Piece(Piece::J);
                currentPiece.summon(x, y);
                currentPiece.rotationIndex = r;
                break;
            }
            case (sf::Keyboard::Key::Num5):
            {
                int x = currentPiece.x;
                int y = currentPiece.y;
                int r = currentPiece.rotationIndex;
                currentPiece = Piece(Piece::L);
                currentPiece.summon(x, y);
                currentPiece.rotationIndex = r;
                break;
            }
            case (sf::Keyboard::Key::Num6):
            {
                int x = currentPiece.x;
                int y = currentPiece.y;
                int r = currentPiece.rotationIndex;
                currentPiece = Piece(Piece::S);
                currentPiece.summon(x, y);
                currentPiece.rotationIndex = r;
                break;
            }
            case (sf::Keyboard::Key::Num7):
            {
                int x = currentPiece.x;
                int y = currentPiece.y;
                int r = currentPiece.rotationIndex;
                currentPiece = Piece(Piece::Z);
                currentPiece.summon(x, y);
                currentPiece.rotationIndex = r;
                break;
            }
            case (sf::Keyboard::Key::Escape):
            {
                appendEvent(EventType::WindowClose);
                break;
            }
            case (sf::Keyboard::Key::Down):
            {
                appendEvent(EventType::SoftDrop);
                break;
            }
            case (sf::Keyboard::Key::Space):
            {
                appendEvent(EventType::HardDrop);
                break;
            }
            case (sf::Keyboard::Key::RShift):
            case (sf::Keyboard::Key::LControl):
            {
                if (!gameWindow->swappedOnThisPiece)
                {
                    if (gameWindow->swapInitialized)
                    {
                        Piece temp = gameWindow->swapPiece;
                        gameWindow->swapPiece = currentPiece;
                        currentPiece = temp;
                        currentPiece.x = gameWindow->simulationField.width / 2 - 1;
                        currentPiece.y = 1;
                    }
                    else
                    {
                        gameWindow->swapPiece = currentPiece;
                        gameWindow->swapInitialized = true;
                        gameWindow->dropNextPiece();
                    }
                    gameWindow->swappedOnThisPiece = true;
                }
                break;
            }
            default:
                break;
            }
        }
    }
}

GameState Controller::handleEvent(EventType event)
{
    switch (event)
    {
    case EventType::MoveLeft:
        gameWindow->attemptMovement(-1);
        return GameState::Neutral;
    case EventType::MoveRight:
        gameWindow->attemptMovement(1);
        return GameState::Neutral;
    case EventType::RotateLeft:
        // gameWindow->attemptRotation(false);
        gameWindow->attemptRotationLeft();
        return GameState::Neutral;
    case EventType::RotateRight:
        // gameWindow->attemptRotation(true);
        gameWindow->attemptRotationRight();
        return GameState::Neutral;
    case EventType::SoftDrop:
        gameWindow->executeGameTick();
        return GameState::Neutral;
    case EventType::HardDrop:
        gameWindow->performHardDrop();
        return GameState::Neutral;
    case EventType::WindowClose:
        gameWindow->window.close();
        return GameState::Exit;
    case EventType::Pause:
        // Handle pause
        return GameState::Neutral;
    default:
        return GameState::Neutral;
    }
}

GameState Controller::handleEvents()
{
    GameState state = GameState::Running;
    while (!eventQueue.empty())
    {
        EventType event = eventQueue.front();
        eventQueue.pop_front();
        GameState returnedState = handleEvent(event);
        if (returnedState != GameState::Neutral)
        {
            state = returnedState;
        }
        if (state == GameState::Exit)
        {
            break;
        }
    }
    return state;
}