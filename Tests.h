//
//  Tests.hpp
//  TicTacToe
//
//  Created by Collin Scribner on 1/12/19.
//  Copyright © 2019 Collin Scribner. All rights reserved.
//

#ifndef Tests_h
#define Tests_h

#include <stdio.h>
#include "Board.h"

const int NUM_RANDOM_TESTS = 30;

void runTests();

bool CERTIFY_TRUE(bool result);
bool CERTIFY_FALSE(bool result);
bool CERTIFY_VALUE_INTEGER(int result, int expected);
/* Depending on the complexity of the program being tested, more functions could be created such as...
 * CERTIFY_RANGE(int x, int lower, int upper)
 * CERTIFY_THRESHOLD(double actual, double exact, double threshold)
 */

#endif /* Tests_h */
