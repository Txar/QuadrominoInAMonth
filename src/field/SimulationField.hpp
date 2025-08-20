#pragma once

#include "TetrominoField.hpp"

class SimulationField : public TetrominoField {
    public:
        SimulationField(int width, int height);
        bool isValidPosition(Piece &piece);
};