//
//  main.cpp
//  TicTacToe
//
//  Created by Collin Scribner on 1/9/19.
//  Copyright © 2019 Collin Scribner. All rights reserved.
//

#include <iostream>
#include "Game.h"
#include "Board.h"
using namespace std;

int main(int argc, const char* argv[]) {
    bool ai = false;
    bool testing = false;
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == 'a') {
                ai = true;
            }
            if (argv[i][1] == 't') {
                testing = true;
            }
        }
    }
    
    Game* game = new Game();
    if (testing) {
        //TODO: Add testing logic here
    } else if (ai) {
        game->startPvAI();
    } else {
        game->startPvP();
    }
    delete game;
}
