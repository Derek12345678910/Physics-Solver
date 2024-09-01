#include "../files.h"

using namespace std;

bool canSolve(map <char, tuple <char, double>> values){
    string type;
    // see if its a 1D or a 2D question by seeing if there is at least one in X or Y
    for(const auto& [dimension, vectors] : values){
        // grab the actual value type and amount
        const auto& [value, amount] = vectors;
        // check if is a number
        if(!isnan(amount)){
            // add it to type so we can count how many there are
            type+=value;
        }
    }
    int X, Y;
    // count how many
    for (int i=0; i < type.length(); i++){
        if(type[i] == 'x'){
            X++;
        } else {
            Y++;
        }
    }
    // it is a 2D Question
    if(X >= 3 && Y >= 3){
        cout << "Is a 2D Kinematics Question" << endl;
        return true;
    }
    // is a 1D Question
    else if (X >= 3 || Y >= 3){
        cout << "Is a 1D Kinematics Question" << endl;
        return true;
    }
    // not possible
    else{
        cout << "Not enough values" << endl;
        return false;
    }
}

double solve(char key, map <char, tuple <char, double>> values){

    

}