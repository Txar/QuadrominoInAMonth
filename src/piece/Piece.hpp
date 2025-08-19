#pragma once
#include "Color.hpp"
#include <vector>

typedef std::vector<std::vector<bool>> TetrominoShape;

class Piece {
    public:
        TetrominoColor color;

        std::vector<TetrominoShape> rotations;
        int rotationIndex;
        int x, y;
    
        Piece(const Piece &piece);
        Piece(TetrominoColor color, std::vector<TetrominoShape> rotations);

        void summon(int x, int y);

        TetrominoShape getCurrentRotation();
        TetrominoShape getRotationRight();
        TetrominoShape getRotationLeft();

        void rotateRight();
        void rotateLeft();
};

namespace PredefinedPiece {
    extern Piece I;
    extern Piece O;
    extern Piece T;
    extern Piece J;
    extern Piece L;
    extern Piece S;
    extern Piece Z;
};