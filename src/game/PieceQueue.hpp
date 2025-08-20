#pragma once

#include <deque>
#include "../piece/Piece.hpp"

enum class ShuffleMode {
    _7Bag,    // 7 unique pieces in a bag
    _14Bag,   // 2x7 of each piece in the bag
    _7_1_Bag, // 7 unique pieces, then 1 random piece
    _7_2_Bag, // 7 unique pieces, then 2 random pieces
    simple,   // Random selection, reroll once on repetition
    chaos,    // Completely random selection
};

class PieceQueue
{
private:
    std::deque<Piece> pieces;
    ShuffleMode shuffleMode = ShuffleMode::_7Bag;
    void shuffleAndFillPieceQueue();

public:
    void setShuffleMode(ShuffleMode mode);
    Piece getNextPiece();
    PieceQueue();
};