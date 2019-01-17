//
//  Board.h
//  TicTacToe
//
//  Created by Collin Scribner on 1/9/19.
//  Copyright © 2019 Collin Scribner. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include <stdio.h>
#include "TicTacToe.h"
using namespace std;

const int BOARD_SIZE = 3;

class Board {
    
    int gameBoard[BOARD_SIZE][BOARD_SIZE];
    
public:
    
    Board();
    Board(int arr[]); // used for making custom test sets efficiently
    ~Board();
    
    int getSquare(int row, int col);
    
    bool setSquare(int row, int col, int val);
    bool checkWin();
    
    void print();
    void clear();

};

#endif /* Board_h */
