#pragma once
#include "Color.h"
namespace Pieces {
typedef unsigned int uint;
class Square {
   public:
    static uint squareW;
    static uint squareH;
    inline Color getColor() { return this->clr; }

   private:
    Color clr;
};
#define SQUARE_SIZE 50
uint Square::squareW = SQUARE_SIZE;
uint Square::squareH = SQUARE_SIZE;

};  // namespace Pieces
