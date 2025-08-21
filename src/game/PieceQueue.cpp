#include "PieceQueue.hpp"
#include <iostream>
#include <random>
#include <ctime>

Piece PieceQueue::getNextPiece()
{
    if (pieces.empty())
    {
        shuffleAndFillPieceQueue();
    }
    Piece nextPiece = pieces.front();
    pieces.pop_front();
    return nextPiece;
}

void PieceQueue::setShuffleMode(ShuffleMode mode)
{
    shuffleMode = mode;
}

void PieceQueue::shuffleAndFillPieceQueue()
{
    switch (shuffleMode)
    {
    case ShuffleMode::_7Bag:
    default:
    {
        std::vector<Piece> allPieces = {
            Piece(Piece::I),
            Piece(Piece::O),
            Piece(Piece::T),
            Piece(Piece::J),
            Piece(Piece::L),
            Piece(Piece::S),
            Piece(Piece::Z)};
        
        for (int i = 7; i > 0; i--)
        {
            int index = std::rand() % i;
            pieces.push_back(allPieces.at(index));
            allPieces.erase(allPieces.begin() + index);
        }
        break;
    }
    }
}

PieceQueue::PieceQueue()
{
    std::srand(std::time(0));
    shuffleAndFillPieceQueue();
}