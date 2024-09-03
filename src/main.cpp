#include "../files.h"

using namespace std;

map <string, function<bool()>> solverMap;

bool askQuestion(){

    string answer;

    cout << "What type of question do you want solved?" << endl;

   
    for (auto& [question, solveFunc] : solverMap){
        cout << question << endl;
    }

    cin >> answer;

    // check if it actually exists
    bool found = false;

    // match question with the key to the fucntion map
    for (auto& [question, solveFunc] : solverMap){
        if (question == answer){
            found = true;
            solveFunc();
        }
    }
    return found;
}

bool solverMapInitialize(){
    solverMap["Kinematics"] = kinematics;

    return true;
}

// entry point
int main(){

    if (!solverMapInitialize()){
        cout << "Couldn't intialize solver Map" << endl;
        return -1;
    }

    if (!askQuestion()){
        cout << "Is not a valid question type" << endl;
        return -2;
    }

    return 0;
}