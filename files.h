#ifndef files_h
#define files_h

#include <iostream>

// STD libraries
#include <cmath>
#include <map>
#include <string>
#include <tuple>
#include <limits>

using namespace std;

// solving functions
bool kinematics();

// functions

// Input values
void testValues(map <string, tuple <char, double>> &values);

// check if the inputted values are solvable
string canSolve(map <string, tuple <char, double>> &values);

// solve given values
bool solve(string key, map <string, tuple <char, double>> &values);

#endif