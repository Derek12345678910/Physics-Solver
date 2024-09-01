#include "../files.h"

using namespace std;

// entry point
int main(){

    // for now we use this map of values
    map <char, tuple<char, double>> values;

    if(!canSolve(values)){
        cerr << "Cannot solve this question with these inputted values" << endl;
        return -1;
    }

    return 0;
}