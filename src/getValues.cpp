#include "../files.h"

using namespace std;

void testValues(map <string, tuple <char, double>> &values){
    values["x1"] = make_tuple('v', 20);
    values["x2"] = make_tuple('a', 2);
    values["x3"] = make_tuple('d', 100);
    values["x4"] = make_tuple('u', numeric_limits<double>::quiet_NaN());
    values["x5"] = make_tuple('t', numeric_limits<double>::quiet_NaN());

    values["y1"] = make_tuple('v', 2.5);
    values["y2"] = make_tuple('a', -1.5);
    values["y3"] = make_tuple('d', 2.3);
    values["y4"] = make_tuple('u', numeric_limits<double>::quiet_NaN());
    values["y5"] = make_tuple('t', numeric_limits<double>::quiet_NaN());
}