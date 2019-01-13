//
//  Tests.cpp
//  TicTacToe
//
//  Created by Collin Scribner on 1/12/19.
//  Copyright © 2019 Collin Scribner. All rights reserved.
//

#include <iostream>
#include "Tests.h"
#include "Board.h"

using namespace std;

void runTests() {
    
    int arr[10][9] = {
        
        {   1, 1, 1,
            0, 2, 0,
            2, 0, 0  },
        
        {   0, 1, 0,
            0, 2, 0,
            2, 0, 1  },
        
        {   1, 0, 1,
            0, 2, 1,
            1, 1, 0  },
        
        {   1, 1, 2,
            0, 1, 2,
            2, 0, 2  },
        
        {   0, 0, 0,
            0, 1, 0,
            0, 0, 0  },
        
        {   0, 0, 0,
            0, 0, 0,
            0, 0, 0  },
        
        {   1, 1, 1,
            1, 1, 1,
            1, 1, 1  },
        
        {   2, 1, 1,
            1, 1, 2,
            2, 2, 1  },
        
        {   1, 2, 2,
            0, 1, 1,
            2, 0, 1  },
        
        {   0, 1, 1,
            2, 2, 0,
            2, 1, 2  },
        
    };
    
    cout << "[INFO] Running tests on predetermined test set : " << endl;
    for (int i = 0; i < 10; ++i) {
        Board t = arr[i];
        t.print();
        cout << "Winning board? --> " << (t.checkWin() ? "TRUE" : "FALSE" ) << endl << endl;
    }
    
    cout << endl << "[INFO] Running tests on randomly generated test set : " << endl;
    int rand_arr[9];
    for (int i = 0; i < NUM_RANDOM_TESTS; ++i) {
        for (int j = 0; j < 9; ++j) {
            rand_arr[j] = rand() % 3; // between 0 and 2, inclusive
        }
        Board t = rand_arr;
        t.print();
        cout << "Winning board? --> " << (t.checkWin() ? "TRUE" : "FALSE" ) << endl << endl;
    }
}

/*
 * CERTIFY_TRUE returns true if the passed in value, result, is true.
 */
bool CERTIFY_TRUE(bool result) {
    return result;
}

/*
 * CERTIFY_FALSE returns true if the passed in value, result, is false.
 */
bool CERTIFY_FALSE(bool result) {
    return !result;
}

/*
 * CERTIFY_VALUE_INTEGER returns true if the passed in value, result, is equal to expected
 */
bool CERTIFY_VALUE_INTEGER(int result, int expected) {
    return result == expected;
}
