#include "Piece.hpp"

Piece::Piece(const Piece &piece) : color(piece.color), rotations(piece.rotations), rotationIndex(piece.rotationIndex), x(piece.x), y(piece.y) {}
Piece::Piece(TetrominoColor color, std::vector<TetrominoShape> rotations)
    : color(color), rotations(rotations), rotationIndex(0), x(0), y(0) {}

void Piece::summon(int x, int y)
{
    this->x = x;
    this->y = y;
}

TetrominoShape Piece::getCurrentRotation()
{
    return rotations.at(rotationIndex % rotations.size());
}

TetrominoShape Piece::getRotationRight()
{
    return rotations.at((rotationIndex + 1) % rotations.size());
}

TetrominoShape Piece::getRotationLeft()
{
    return rotations.at((rotationIndex - 1 + rotations.size()) % rotations.size());
}

void Piece::rotateRight()
{
    rotationIndex = (rotationIndex - 1 + rotations.size()) % rotations.size();
}

void Piece::rotateLeft()
{
    rotationIndex = (rotationIndex + 1) % rotations.size();
}

const Piece Piece::O = Piece(YELLOW, {{{1, 1},
                                       {1, 1}}});

const Piece Piece::I = Piece(LIGHT_BLUE, {
                                             {
                                                 {0, 0, 0, 0},
                                                 {1, 1, 1, 1},
                                                 {0, 0, 0, 0},
                                                 {0, 0, 0, 0},
                                             },
                                             {
                                                 {0, 0, 1, 0},
                                                 {0, 0, 1, 0},
                                                 {0, 0, 1, 0},
                                                 {0, 0, 1, 0},
                                             },
                                             {
                                                 {0, 0, 0, 0},
                                                 {0, 0, 0, 0},
                                                 {1, 1, 1, 1},
                                                 {0, 0, 0, 0},
                                             },
                                             {
                                                 {0, 1, 0, 0},
                                                 {0, 1, 0, 0},
                                                 {0, 1, 0, 0},
                                                 {0, 1, 0, 0},
                                             },
                                         });

const Piece Piece::T = Piece(PINK, {
                                       {
                                           {0, 1, 0},
                                           {1, 1, 1},
                                           {0, 0, 0},
                                       },
                                       {
                                           {0, 1, 0},
                                           {0, 1, 1},
                                           {0, 1, 0},
                                       },
                                       {
                                           {0, 0, 0},
                                           {1, 1, 1},
                                           {0, 1, 0},
                                       },
                                       {
                                           {0, 1, 0},
                                           {1, 1, 0},
                                           {0, 1, 0},
                                       },
                                   });

const Piece Piece::J = Piece(NAVY_BLUE, {
                                            {
                                                {1, 0, 0},
                                                {1, 1, 1},
                                                {0, 0, 0},
                                            },
                                            {
                                                {0, 1, 1},
                                                {0, 1, 0},
                                                {0, 1, 0},
                                            },
                                            {
                                                {0, 0, 0},
                                                {1, 1, 1},
                                                {0, 0, 1},
                                            },
                                            {
                                                {0, 1, 0},
                                                {0, 1, 0},
                                                {1, 1, 0},
                                            },
                                        });

const Piece Piece::L = Piece(ORANGE, {
                                         {
                                             {0, 0, 1},
                                             {1, 1, 1},
                                             {0, 0, 0},
                                         },
                                         {
                                             {0, 1, 0},
                                             {0, 1, 0},
                                             {0, 1, 1},
                                         },
                                         {
                                             {0, 0, 0},
                                             {1, 1, 1},
                                             {1, 0, 0},
                                         },
                                         {
                                             {1, 1, 0},
                                             {0, 1, 0},
                                             {0, 1, 0},
                                         },
                                     });

const Piece Piece::S = Piece(GREEN, {
                                        {
                                            {0, 1, 1},
                                            {1, 1, 0},
                                            {0, 0, 0},
                                        },
                                        {
                                            {0, 1, 0},
                                            {0, 1, 1},
                                            {0, 0, 1},
                                        },
                                        {
                                            {0, 0, 0},
                                            {0, 1, 1},
                                            {1, 1, 0},
                                        },
                                        {
                                            {1, 0, 0},
                                            {1, 1, 0},
                                            {0, 1, 0},
                                        },
                                    });

const Piece Piece::Z = Piece(RED, {
                                      {
                                          {1, 1, 0},
                                          {0, 1, 1},
                                          {0, 0, 0},
                                      },
                                      {
                                          {0, 0, 1},
                                          {0, 1, 1},
                                          {0, 1, 0},
                                      },
                                      {
                                          {0, 0, 0},
                                          {1, 1, 0},
                                          {0, 1, 1},
                                      },
                                      {
                                          {0, 1, 0},
                                          {1, 1, 0},
                                          {1, 0, 0},
                                      },
                                  });