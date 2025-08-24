#include "Piece.hpp"
#include <iostream>

Piece::Piece(const Piece &piece) : color(piece.color), rotations(piece.rotations), rotationIndex(piece.rotationIndex), x(piece.x), y(piece.y)
{
}

Piece::Piece(ColorIndex color, std::vector<QuadrominoShape> rotations)
    : color(color), rotations(rotations), rotationIndex(0), x(0), y(0)
{
}

void Piece::summon(int x, int y)
{
    this->x = x;
    this->y = y;
}

QuadrominoShape Piece::getCurrentRotation()
{
    return rotations.at(rotationIndex % rotations.size());
}

QuadrominoShape Piece::getRotationRight()
{
    return rotations.at((rotationIndex + 1) % rotations.size());
}

QuadrominoShape Piece::getRotationLeft()
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

const Piece Piece::O = Piece(0, {{{1, 1},
                                       {1, 1}}});

const Piece Piece::I = Piece(0, {
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

const Piece Piece::T = Piece(0, {
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

const Piece Piece::J = Piece(0, {
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

const Piece Piece::L = Piece(0, {
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

const Piece Piece::S = Piece(0, {
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

const Piece Piece::Z = Piece(0, {
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