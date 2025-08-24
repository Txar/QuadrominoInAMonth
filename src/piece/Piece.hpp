#pragma once
#include "Color.hpp"
#include <vector>

typedef std::vector<std::vector<bool>> QuadrominoShape;

class Piece {
    public:
        ColorIndex color;

        std::vector<QuadrominoShape> rotations;
        int rotationIndex;
        int x, y;
    
        Piece(const Piece &piece);
        Piece(ColorIndex color, std::vector<QuadrominoShape> rotations);

        static const Piece I;
        static const Piece O;
        static const Piece T;
        static const Piece J;
        static const Piece L;
        static const Piece S;
        static const Piece Z;

        void summon(int x, int y);

        QuadrominoShape getCurrentRotation();
        QuadrominoShape getRotationRight();
        QuadrominoShape getRotationLeft();

        void rotateRight();
        void rotateLeft();
};