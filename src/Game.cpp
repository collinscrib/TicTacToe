//
//  Game.cpp
//  TicTacToe
//
//  Created by Collin Scribner on 1/9/19.
//  Copyright © 2019 Collin Scribner. All rights reserved.
//

#include <iostream>
#include "Game.h"
#include "Tests.h"
using namespace std;

/*
 // Game() initializes everything needed for a TicTacToe game to begin upon instantiation
 */
Game::Game() {}

/*
 // ~Game() is the general deconstructor for the Game object, invoked upon destruction
 */
Game::~Game() {}

/*
 // startPvP() starts a new game of Player vs Player that can be played in the command terminal
 */
void Game::startPvP() {
    
    Board* b = new Board();
    b->print();
    
    int r = 0, c = 0;
    for (int i = 1; i <= 9; ++i) { // maximum of 9 turns
        for (int i = 1; i <= 2; ++i) { // player 1, then player 2
            if (i == X_SPACE) {
                cout << "X";
            } else if (i == O_SPACE) {
                cout << "O";
            }
            cout << "'s turn." << endl;
            cout << "Enter two numbers, the first one being for the row and the second for column of your entry in the grid." << endl;
            cin >> r >> c;
            
            while(b->setSquare(r, c, i) == false) {
                cout << "Invalid move! Try again." << endl;
                cin >> r >> c;
            }
            
            b->print();
            
            if (b->checkWin()) {
                printWin(i);
                delete b;
                return;
            }
        }
    }
    
    printNoWin();
    delete b;
}

/*
 // startPvAI() starts a new game of Player vs Computer
 */
void Game::startPvAI() {
    //TODO: Add AI logic here
}

/*
 // printWin() outputs the win message
 // winner - The enum value of whichever player one, for printing purposes
 */
void Game::printWin(int winner) {
    if (winner == X_SPACE) {
        cout << "X";
    }
    if (winner == O_SPACE) {
        cout << "O";
    }
    cout << "'s Win! " << endl;
}

/*
 // printNoWin() outputs the tie game / No win message
 */
void Game::printNoWin() {
    cout << "Nobody wins, tie game! ";
}
