#pragma once
#include <deque>
#include <memory>

class GameWindow;

enum class EventType {
    MoveLeft,
    MoveRight,
    RotateLeft,
    RotateRight,
    SoftDrop,
    HardDrop,
    WindowClose,
    Pause,
};

enum class GameState {
    Running,
    Paused,
    Exit,
    Neutral
};

class Controller
{
private:
    std::deque<EventType> eventQueue = {};
    void appendEvent(EventType event);
    
public:
    GameWindow *gameWindow;
    Controller(const Controller &) = delete;
    Controller(GameWindow *gameWindow);
    Controller();
    ~Controller();

    void pollEvents();
    GameState handleEvent(EventType event);
    GameState handleEvents();
};