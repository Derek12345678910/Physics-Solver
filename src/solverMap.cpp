#include "../files.h"

using namespace std;

bool kinematics(){

    // for now we use this map of values
    map <string, tuple<char, double>> values;

    values["x1"] = make_tuple('v', numeric_limits<double>::quiet_NaN());
    values["x2"] = make_tuple('a', numeric_limits<double>::quiet_NaN());
    values["x3"] = make_tuple('d', numeric_limits<double>::quiet_NaN());
    values["x4"] = make_tuple('u', numeric_limits<double>::quiet_NaN());
    values["x5"] = make_tuple('t', numeric_limits<double>::quiet_NaN());
    values["y1"] = make_tuple('v', numeric_limits<double>::quiet_NaN());
    values["y2"] = make_tuple('a', numeric_limits<double>::quiet_NaN());
    values["y3"] = make_tuple('d', numeric_limits<double>::quiet_NaN());
    values["y4"] = make_tuple('u', numeric_limits<double>::quiet_NaN());
    values["y5"] = make_tuple('t', numeric_limits<double>::quiet_NaN());

    string input;

    cout << "Enter nan if you do not have the value" << endl;

    for (auto& [direction, vectors] : values){
        auto& [type, amount] = vectors;
        cout << "Enter the value for " << type << " in the " << direction[0] << " direction: " << endl;
        cin >> input;
        // nan
        if (input == "nan"){
            values[direction] = make_tuple(type, numeric_limits<double>::quiet_NaN());
        } else {
            values[direction] = make_tuple(type, stod(input));
        }
    }

    /* TESTING
    for (const auto& [key, tuples] : values){
        auto& [type, number] = tuples;
        cout << key << " " << type << " " << number << "\n";
    }
    */
    string key = canSolve(values);
    // Not solvable
    if (key == ""){
        cerr << "Cannot solve this question with these inputted values" << endl;
        return false;
    }
    // solve the question
    if (!solve(key, values)){
        cerr << "Cannot Solve" << endl;
        return false;
    }

    return true;
}   