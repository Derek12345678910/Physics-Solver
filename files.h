#ifndef files_h
#define files_h

#include <iostream>

// libraries
#include <map>
#include <string>
#include <tuple>

// functions

// check if the inputted values are solvable
bool canSolve(map <char, tuple <char, double>> values);

// solve given values
double solve(char key, map <char, tuple <char, double>> values);

#endif