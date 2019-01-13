//
//  Board.h
//  TicTacToe
//
//  Created by Collin Scribner on 1/9/19.
//  Copyright © 2019 Collin Scribner. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include "TicTacToe.h"
using namespace std;

const int BOARD_SIZE = 3;

class Board {
    
    int gameBoard[BOARD_SIZE][BOARD_SIZE];
    
public:
    
    Board();
    ~Board();
    
    void print();
    
    bool setSquare(int row, int col, int val);
    bool checkWin();
    
private:
    
    void clearBoard();

};

#endif /* Board_hpp */
