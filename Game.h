//
//  Game.hpp
//  TicTacToe
//
//  Created by Collin Scribner on 1/9/19.
//  Copyright © 2019 Collin Scribner. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Board.h"
#include "TicTacToe.h"
using namespace std;

class Game {
    
    int turn;
    
public:
    
    Game();
    ~Game();
    
    void startPvP();
    void startPvAI();
    
private:
    
    void printWin(int player);
    void printNoWin();
    
};

#endif /* Game_hpp */
