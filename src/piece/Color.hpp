#pragma once

enum TetrominoColor {
    LIGHT_BLUE,
    YELLOW,
    PINK,
    NAVY_BLUE,
    ORANGE,
    GREEN,
    RED,
    GRAY
};

inline constexpr int ColorPosition(TetrominoColor color) {
    switch (color) {
        case LIGHT_BLUE: return 0;
        case YELLOW: return 1;
        case PINK: return 2;
        case NAVY_BLUE: return 3;
        case ORANGE: return 4;
        case GREEN: return 5;
        case RED: return 6;
        case GRAY: return 7;
    }
    return -1; // Invalid color
}