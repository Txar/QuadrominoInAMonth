#include "SimulationField.hpp"

SimulationField::SimulationField(int width, int height)
    : TetrominoField(width, height) {};

bool SimulationField::isValidPosition(Piece &piece) {
    TetrominoShape shape = piece.getCurrentRotation();
    for (int i = 0; i < (int) shape.size(); i++) {
        for (int j = 0; j < (int) shape.at(i).size(); j++) {
            if (shape.at(i).at(j)) {
                if (piece.x + i < 0 || piece.x + i >= width ||
                    piece.y + j < 0 || piece.y + j >= height ||
                    field.at(piece.x + i).at(piece.y + j).isForeground) {
                    return false;
                }
            }
        }
    }
    return true;
}