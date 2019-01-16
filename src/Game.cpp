//
//  Game.cpp
//  TicTacToe
//
//  Created by Collin Scribner on 1/9/19.
//  Copyright © 2019 Collin Scribner. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "Game.h"
#include "Tests.h"
using namespace std;

#define PI 3.14159265

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
    
    int r = 0, c = 0, player = 0;
    int randomStart = rand() % 2;

    for (int i = 1 + randomStart; i <= 9 + randomStart; ++i) { // maximum of 9 turns, starting with either X's or O's randomly
        if (i > 2) {
            player = (i % 2 == 0 ? O_SPACE : X_SPACE); // even numbers are O's, odd numbers are X's
        } else {
            player = i;
        }
        
        if (player == X_SPACE) {
            cout << "X";
        } else if (player == O_SPACE) {
            cout << "O";
        }
        cout << "'s turn." << endl;
        cout << "Enter two numbers, the first one being for the row and the second for column of your entry in the grid. (0-2)" << endl;
        cin >> r >> c;
            
        while(b->setSquare(r, c, player) == false) {
            cout << "Invalid move! Try again." << endl;
            cin >> r >> c;
        }
        
        b->print();
        
        if (b->checkWin()) {
            printWin(player);
            delete b;
            return;
        }
    }
    
    printNoWin();
    delete b;
}

/*
 // startPvAI() starts a new game of Player vs Computer
 */
void Game::startPvAI() {
    
    Board* b = new Board();
    b->print();
    
    int player = 0;
    int human = 0;
    int computer = 0;
    
    cout << "Do you want to be X's or O's? " << endl << "Enter 1 for X, 2 for O." << endl;
    while (!(player == 1 || player == 2)) {
        cin >> player;
    }
    
    if (player == X_SPACE) {
        human = X_SPACE;
        computer = O_SPACE;
    } else {
        human = O_SPACE;
        computer = X_SPACE;
    }
    
    int r = 0, c = 0;
    for (int i = 1; i <= 9; ++i) {
        if (i > 2) {
            player = i % 2;
        } else {
            player = i;
        }
        
        if (player == human) {
            cout << "Enter two numbers, the first one being for the row and the second for column of your entry in the grid. (0-2)" << endl;
            cin >> r >> c;
            
            while (b->setSquare(r, c, player) == false) {
                cout << "Invalid move! Try again." << endl;
                cin >> r >> c;
            }
        } else {
            while (b->setSquare(r, c, player) == false) {
                r = rand() % 3;
                c = rand() % 3;
            }
        }
        
        b->print();
        cout << endl;
        
        if (b->checkWin()) {
            printWin(player);
            delete b;
            return;
        }
    }
    
//    Board* b = new Board();
//    b->print();
//
//    int input = 0;
//    cout << "Do you want to be X's or O's? " << endl << "Enter 1 for X, 2 for O." << endl;
//    while (input != 1 && input != 2) {
//        cin >> input;
//    }
//
//    const int firstPlayerConst = rand() % 2; // between 0 and 1
//
//    int r = 0, c = 0;
//    for (int i = 1; i <= 9; ++i) { // maximum of 9 turns between the computer and player
//        int player = i % 2 + firstPlayerConst;
//        player = cos(PI * i);
//        if (player == -1) { player = 2; }
//
//        if (player == input) { // human move
//            cout << "Enter two numbers, the first one being for the row and the second for column of your entry in the grid. (0-2)" << endl;
//            cin >> r >> c;
//
//            while(b->setSquare(r, c, player) == false) {
//                cout << "Invalid move! Try again." << endl;
//                cin >> r >> c;
//            }
//        } else { // computer move
//            cout << "[Computer is moving...]" << endl;
//            while(b->setSquare(r, c, player) == false) {
//                r = rand() % 3;
//                c = rand() % 3;
//            }
//        }
//
//        b->print();
//        cout << endl;
//
//        if (b->checkWin()) {
//            printWin(player);
//            delete b;
//            return;
//        }
//    }
    
    printNoWin();
    delete b;
}

/*
 // printWin() outputs the win message
 // winner - The enum value of whichever player won, for printing purposes
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
    cout << "Nobody wins, tie game! " << endl;
}
