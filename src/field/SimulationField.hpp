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
    Piece attemptPieceRotation(Piece &piece, bool clockwise);
    
    public:
    Piece attemptPieceRotationRight(Piece &piece);
    Piece attemptPieceRotationLeft(Piece &piece);
    int clearedLines = 0;
    SimulationField(int width, int height);
    bool isValidPosition(Piece &piece);
    void stampPiece(Piece piece);
};