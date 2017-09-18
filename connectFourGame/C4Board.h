// Interface for C4Board class. will be used to implement a connect 4 game.
// Note that it cincludes a previously made class, C4Col
// Date: 1/30/2017
// Autor: Will Fritz

#ifndef C4BOARD_H
#define C4BOARD_H
//header of C4Col class which makes up the columns of the board
#include "C4Col.h"

class C4Board {
    public:
        C4Board();
        ~C4Board();
        void display();
        void play();
    private:
        int numCols;
        C4Col * board;
        bool checkWin(C4Col [], char);
};

#endif
