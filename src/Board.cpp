//
//  Board.cpp
//  TicTacToe
//
//  Created by Collin Scribner on 1/9/19.
//  Copyright © 2019 Collin Scribner. All rights reserved.
//

#include <iostream>
#include "Board.h"
using namespace std;

/*
 // Board() constructor; initializes the board by setting every space to BLANK_SPACE upon instantiation
 */
Board::Board() {
    clear();
}

/*
 // Board(int arr[]) assigns values of arr[] to gameBoard positions by linear index, useful for creating manual/predetermined gameBoards
 // arr[] - the input array, in integers; must be of length 9
 */
Board::Board(int arr[]) {
//    int size = 0;
//    for (int i = 0; i < 9; ++i) {
//        if (isalnum(arr[i])) {
//            size++;
//        }
//    }
//    if (size != 9) {
//        cout << "[ERROR] Size of arr[] in Board Constructor is not 9" << endl;
//        exit(1); // exit the program with exit code 1
//    }
    
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            gameBoard[i][j] = arr[i*3 + j];
        }
    }
}

/*
 // ~Board() is the default deconstructor for the Board class, invoked upon destruction
 */
Board::~Board() {}

/*
 // print() outputs the game board in a readable text format (3x3) to the console
 */
void Board::print() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << "| ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            string space = " ";
            if (gameBoard[i][j] == X_SPACE) {
                space = "X";
            } else if (gameBoard[i][j] == O_SPACE) {
                space = "O";
            }
            cout << space << " | ";
        }
        cout << endl;
    }
}

/*
 // setSquare() takes 3 parameters row, col, and val, and sets the appropriate square in the 3x3 grid to either an X (1) or an O (2), and returns false if the move is invalid (i.e. the space is occupied or out of bounds), otherwise true if the operation was successful.
 // row - the row of the insertion
 // col - the column of the insertion
 // val - the value of the insertion
 */
bool Board::setSquare(int row, int col, int val) {
    if ( row > 2 || col > 2) { // Can't exceed grid bounds
        return false;
    }
    
    if (gameBoard[row][col] == BLANK_SPACE) {
        gameBoard[row][col] = val;
    } else {
        return false;
    }
    return true;
}

/*
 // checkWin() returns true if the current state of the board is qualified as one player winning, otherwise false. Does not specify who won (X's or O's)
 */
bool Board::checkWin() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != BLANK_SPACE) { // row match
            return true;
        }
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != BLANK_SPACE) { // column match
            return true;
        }
    }
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != BLANK_SPACE) { // diagonal match
        return true;
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != BLANK_SPACE) { // diagonal match
        return true;
    }
    return false;
}

/*
 // clearBoard() changes every spot in the board in memory to BLANK_SPACE
 */
void Board::clear() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameBoard[i][j] = BLANK_SPACE;
        }
    }
}
