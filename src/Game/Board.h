#pragma once
#include "Square.h"
#include "util.h"
class Board {
    SINGLETON(Board);
    void init();

   private:
    Pieces::Square** squares;
};