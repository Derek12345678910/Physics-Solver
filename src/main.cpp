#include "../files.h"

using namespace std;

// entry point
int main(){

    // for now we use this map of values
    map <string, tuple<char, double>> values;

    testValues(values);

    string key = canSolve(values);
    // Not solvable
    if (key == ""){
        cerr << "Cannot solve this question with these inputted values" << endl;
        return -1;
    }
    
    if (!solve(key, values)){
        cerr << "Cannot Solve" << endl;
        return -2;
    }

    /* test
    for (const auto& [key, tuples] : values){
        auto& [type, number] = tuples;
        cout << key << " " << type << " " << number << "\n";
    }
    */
   
    return 0;
}