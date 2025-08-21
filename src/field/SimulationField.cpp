#include "SimulationField.hpp"
#include <iostream>

SimulationField::SimulationField(int width, int height)
    : QuadrominoField(width, height) {
    };

bool SimulationField::isValidPosition(Piece &piece) {
    QuadrominoShape shape = piece.getCurrentRotation();
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

void SimulationField::stampPiece(Piece piece) {
    QuadrominoField::stampPiece(piece);
    findAndClearLines();
}

void SimulationField::findAndClearLines() {
    std::vector<std::vector<DrawableBlock>> newField = field;
    int shiftCount = 0;

    for (int j = height - 2; j > 0; j--) {
        bool fullLine = true;
        for (int i = 0; i < width; i++) {
            if (!newField.at(i).at(j).isForeground) {
                fullLine = false;
                break;
            }
        }
        if (fullLine) {
            shiftAllLines(j + shiftCount);
            shiftCount++;
            clearedLines++;
        }
    }
}

void SimulationField::shiftAllLines(int above) {
    for (int j = above; j > 0; j--) {
        shiftLineDown(j, 1);
        // break;
    }
}

void SimulationField::clearLine(int line) {
    for (int i = 0; i < width; i++) {
        if (field.at(i).at(line).color != GRAY) {
            field.at(i).at(line) = DrawableBlock(i == 0 || i == width - 1, GRAY);
        }
    }
}

void SimulationField::pasteLineDown(int line, int shiftBy) {
    for (int i = 0; i < width; i++) {
        if (field.at(i).at(line).color != GRAY || !field.at(i).at(line).isForeground) {
            DrawableBlock d = field.at(i).at(line);
            field.at(i).at(line + shiftBy) = DrawableBlock(d.isForeground, d.color);
        }
    }
}

void SimulationField::shiftLineDown(int line, int shiftBy) {
    pasteLineDown(line - 1, shiftBy);
}