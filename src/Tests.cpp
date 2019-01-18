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

/*
 * runTests() creates a number of Board classes and runs unit tests on them to verify that they work properly. This can be viewed/run from the console by using the command line argument flag '-t'
 */
void runTests() {
    
    bool passedAll = true;
    bool passes[10] = {true, false, false, true, false, false, true, false, true, false};
    
    int arr[10][9] = { // 10 predetermined tests, with 9 (3x3) squares each
        
        {   1, 1, 1,
            0, 2, 0,
            2, 0, 0  },
        
        {   0, 1, 0,
            0, 2, 0,
            2, 0, 1  },
        
        {   1, 0, 1,
            2, 2, 1,
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
        
        {   2, 1, 2,
            1, 1, 1,
            2, 1, 2  },
        
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
    
    cout << "[INFO] Running tests on predetermined test set... " << endl;
    for (int i = 0; i < 10; ++i) {
        Board t = arr[i];
        t.print();
        cout << "[TEST] Winning board? --> " << (t.checkWin() ? "TRUE" : "FALSE" ) << endl;
        cout << "[TEST] CERTIFY_TRUE, " << boolalpha << t.checkWin() << " is expected " << passes[i] << " -- " << (CERTIFY_TRUE(passes[i] == t.checkWin()) ? "Pass" : "Fail") << endl;
        if (passedAll == true) {
            passedAll = CERTIFY_TRUE(passes[i] == t.checkWin());
        }
    }

    if (passedAll) {
        cout << "[INFO] Program Passed all predetermined tests!" << endl;
    } else {
        cout << "[WARNING] At least one predetermined test failed." << endl;
    }
    
    cout << "[INFO] Running tests on randomly generated test set..." << endl;
    int rand_arr[9];
    for (int i = 0; i < NUM_RANDOM_TESTS; ++i) {
        for (int j = 0; j < 9; ++j) {
            rand_arr[j] = rand() % 3; // between 0 and 2, inclusive
        }
        Board t = rand_arr;
        t.print();
        cout << "[TEST] Winning board? --> " << (t.checkWin() ? "TRUE" : "FALSE" ) << endl;
    }
    
    cout << "[INFO] Running tests on Board class..." << endl;
    for (int i = 1; i <= 2; ++i) {
        Board* t = new Board();
        cout << "[INFO] Test " << i << " - set square " << rand() % 3 << " " << rand() % 3 << " to " << (i == 1 ? "X" : "O") << " - " << (t->setSquare(i, i, i) ? "Passed" : "FAIL" ) << endl;
        delete t;
        t = nullptr;
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
    return result == false;
}

/*
 * CERTIFY_VALUE_INTEGER returns true if the passed in value, result, is equal to expected
 */
bool CERTIFY_VALUE_INTEGER(int result, int expected) {
    return result == expected;
}
