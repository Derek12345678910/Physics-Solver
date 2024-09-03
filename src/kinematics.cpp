#include "../files.h"

using namespace std;

string canSolve(map<string, tuple<char, double>> &values)
{
    string type;
    // see if its a 1D or a 2D question by seeing if there is at least one in X or Y
    for (const auto &[dimension, vectors] : values)
    {
        // grab the actual value type and amount
        const auto &[value, amount] = vectors;
        // check if is a number
        if (!isnan(amount))
        {
            // add it to type so we can count how many there are
            type += dimension[0]; // [0] because its always first letter
        }
    }

    int X = 0, Y = 0;
    // count how many
    for (int i = 0; i < type.size(); i++)
    {
        if (type[i] == 'x')
        {
            X++;
        }
        else
        {
            Y++;
        }
    }
    // it is a 2D Question
    if (X >= 3 && Y >= 3)
    {
        cout << "Is a 2D Kinematics Question" << endl;
        return "xy";
    }
    // is a 1D Question
    else if (X >= 3 || Y >= 3)
    {
        cout << "Is a 1D Kinematics Question" << endl;
        return (X > Y) ? "x" : "y";
    }
    // not possible
    else
    {
        cout << "Not enough values" << endl;
        return "";
    }
}

bool calculate(map<char, double> &given)
{
    bool changed = true;

    while (changed)
    {
        changed = false;

        // Calculate acceleration (a)
        if (isnan(given['a']))
        {
            if (!isnan(given['u']) && !isnan(given['v']) && !isnan(given['t']))
            {
                given['a'] = (given['v'] - given['u']) / given['t'];
                changed = true;
            }
            else if (!isnan(given['u']) && !isnan(given['v']) && !isnan(given['d']))
            {
                given['a'] = (given['v'] * given['v'] - given['u'] * given['u']) / (2 * given['d']);
                changed = true;
            }
            else if (!isnan(given['d']) && !isnan(given['u']) && !isnan(given['t']))
            {
                given['a'] = 2 * (given['d'] - given['u'] * given['t']) / (given['t'] * given['t']);
                changed = true;
            }
        }

        // Calculate initial velocity (u)
        if (isnan(given['u']))
        {
            if (!isnan(given['v']) && !isnan(given['a']) && !isnan(given['t']))
            {
                given['u'] = given['v'] - given['a'] * given['t'];
                changed = true;
            }
            else if (!isnan(given['v']) && !isnan(given['a']) && !isnan(given['d']))
            {
                double discriminant = given['v'] * given['v'] - 2 * given['a'] * given['d'];
                if (discriminant >= 0)
                {
                    given['u'] = sqrt(discriminant);
                    changed = true;
                }
                else
                {
                    // Impossible to solve for 'u' due to negative discriminant
                    return false;
                }
            }
            else if (!isnan(given['d']) && !isnan(given['a']) && !isnan(given['t']))
            {
                given['u'] = (given['d'] - 0.5 * given['a'] * given['t'] * given['t']) / given['t'];
                changed = true;
            }
            else if (!isnan(given['v']) && !isnan(given['d']) && !isnan(given['t']))
            {
                given['u'] = (2 * given['d'] / given['t']) - given['v'];
                changed = true;
            }
        }

        // Calculate final velocity (v)
        if (isnan(given['v']))
        {
            if (!isnan(given['u']) && !isnan(given['a']) && !isnan(given['t']))
            {
                given['v'] = given['u'] + given['a'] * given['t'];
                changed = true;
            }
            else if (!isnan(given['u']) && !isnan(given['a']) && !isnan(given['d']))
            {
                double discriminant = given['u'] * given['u'] + 2 * given['a'] * given['d'];
                if (discriminant >= 0)
                {
                    given['v'] = sqrt(discriminant);
                    changed = true;
                }
                else
                {
                    // Impossible to solve for 'v' due to negative discriminant
                    return false;
                }
            }
            else if (!isnan(given['u']) && !isnan(given['d']) && !isnan(given['t']))
            {
                given['v'] = (2 * given['d'] / given['t']) - given['u'];
                changed = true;
            }
        }

        // Calculate displacement (d)
        if (isnan(given['d']))
        {
            if (!isnan(given['u']) && !isnan(given['v']) && !isnan(given['t']))
            {
                given['d'] = ((given['u'] + given['v']) / 2) * given['t'];
                changed = true;
            }
            else if (!isnan(given['u']) && !isnan(given['a']) && !isnan(given['t']))
            {
                given['d'] = given['u'] * given['t'] + 0.5 * given['a'] * given['t'] * given['t'];
                changed = true;
            }
            else if (!isnan(given['v']) && !isnan(given['a']) && !isnan(given['t']))
            {
                given['d'] = given['v'] * given['t'] - 0.5 * given['a'] * given['t'] * given['t'];
                changed = true;
            }
            else if (!isnan(given['u']) && !isnan(given['v']) && !isnan(given['a']))
            {
                given['d'] = (given['v'] * given['v'] - given['u'] * given['u']) / (2 * given['a']);
                changed = true;
            }
        }

        // Calculate time (t)
        if (isnan(given['t']))
        {
            if (!isnan(given['u']) && !isnan(given['v']) && !isnan(given['a']))
            {
                given['t'] = (given['v'] - given['u']) / given['a'];
                changed = true;
            }
            else if (!isnan(given['u']) && !isnan(given['v']) && !isnan(given['d']))
            {
                given['t'] = (2 * given['d']) / (given['u'] + given['v']);
                changed = true;
            }
            else if (!isnan(given['u']) && !isnan(given['a']) && !isnan(given['d']))
            {
                double discriminant = given['u'] * given['u'] + 2 * given['a'] * given['d'];
                if (discriminant >= 0)
                {
                    given['t'] = (-given['u'] + sqrt(discriminant)) / given['a'];
                    changed = true;
                }
                else
                {
                    // Impossible to solve for 't' due to negative discriminant
                    return false;
                }
            }
            else if (!isnan(given['v']) && !isnan(given['a']) && !isnan(given['d']))
            {
                double discriminant = given['v'] * given['v'] - 2 * given['a'] * given['d'];
                if (discriminant >= 0)
                {
                    given['t'] = (given['v'] - sqrt(discriminant)) / given['a'];
                    changed = true;
                }
                else
                {
                    // Impossible to solve for 't' due to negative discriminant
                    return false;
                }
            }
        }
    }
    
    return true;
}

void lookFor(string key, map<char, double> &lookingFor, map<string, tuple<char, double>> &values)
{
    // see which values are missing
    int i;
    key == "x" ? i = 1 : i = -4;
    for (const auto &[direction, vectors] : values)
    {
        auto &[value, amount] = vectors;
        // assign values
        if (direction == key + to_string(i))
        {
            lookingFor[value] = amount;
        }
        i++;
    }
}

void assignValues(string key, map<string, tuple<char, double>> &values, map<char, double> &found)
{
    int i;
    key == "x" ? i = 1 : i = -4;
    // loop the main value map
    for (auto &[direction, vectors] : values)
    {
        // main one
        auto &[value, amount] = vectors;
        // look for the value inside the found map
        if (found.find(value) != found.end())
        {
            if (direction == key + to_string(i))
            {
                amount = found[value];
            }
        }
        i++;
    }
}

bool solve(string key, map<string, tuple<char, double>> &values)
{
    // do a solve for both sides
    if (key == "xy")
    {
        // create sub map
        map<char, double> lookingFor;
        // set the map to the values we are looking for
        lookFor("x", lookingFor, values);
        // calculate for missing ones
        if (!calculate(lookingFor)){
            return false;
        }
        // assign them to the original values map
        assignValues("x", values, lookingFor);

        // clear and redo with Y
        lookingFor.clear();

        // set the map to the values we are looking for
        lookFor("y", lookingFor, values);
        // calculate for missing ones
        if (!calculate(lookingFor)){
            return false;
        }
        // assign them to the original values map
        assignValues("y", values, lookingFor);
    }
    // only one
    else
    {
        // create sub map
        map<char, double> lookingFor;
        // set map to values we are looking for
        lookFor(key, lookingFor, values);
        // calculate for missing ones
        if (!calculate(lookingFor)){
            return false;
        }
        // assign them to the original values map
        assignValues(key, values, lookingFor);
    }

    return true;
}