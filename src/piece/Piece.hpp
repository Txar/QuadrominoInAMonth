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

        static const Piece I;
        static const Piece O;
        static const Piece T;
        static const Piece J;
        static const Piece L;
        static const Piece S;
        static const Piece Z;

        void summon(int x, int y);

        TetrominoShape getCurrentRotation();
        TetrominoShape getRotationRight();
        TetrominoShape getRotationLeft();

        void rotateRight();
        void rotateLeft();
};