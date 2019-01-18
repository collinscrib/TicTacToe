//
//  Game.hpp
//  TicTacToe
//
//  Created by Collin Scribner on 1/9/19.
//  Copyright © 2019 Collin Scribner. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "Board.h"
#include "Tests.h"
#include "TicTacToe.h"
using namespace std;

class Game {
    
    Board* board;
    
public:
    
    Game();
    ~Game();
    
    void startPvP();
    void startPvAI();
    void startTests();
    
private:
    
    void printWin(int player);
    void printNoWin();
    
};

#endif /* Game_h */
