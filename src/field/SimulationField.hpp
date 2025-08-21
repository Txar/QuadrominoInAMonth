#pragma once

#include "QuadrominoField.hpp"

class SimulationField : public QuadrominoField
{
private:
    void pasteLineDown(int line, int shiftBy);
    void shiftLineDown(int line, int shiftBy);
    void shiftAllLines(int above);
    void clearLine(int line);
    void findAndClearLines();
    void rebuildFrame();

public:
    int clearedLines = 0;
    SimulationField(int width, int height);
    bool isValidPosition(Piece &piece);
    void stampPiece(Piece piece);
};