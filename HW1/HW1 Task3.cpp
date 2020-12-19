#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>
#include <limits>

using namespace std;
int mutants();
bool isNumber(string str);
bool isPercent(string str);
int isCorrectType(string errMsg, bool isDouble);
int main()
{
    cout << mutants();
    return 0;
}

int mutants()
{
    double nights = 0;
    double p, m, n, mutants_rest;
    double infinity = numeric_limits<double>::infinity();
    cout << "Input counts of matants: ";
    m = isCorrectType("Counts should be positive integer! ", false);
    cout << "Input percent of mutants reproduction: ";
    p = isCorrectType("Percent should be from 0.00% to 100.00%!", true);
    cout << "Input counts of mutants destroyed  per night: ";
    n = isCorrectType("Counts should be positive integer! ", false);

    if ((m - n) > 0)
    {
        mutants_rest = m;
        while (mutants_rest > 0)
        {
            if (mutants_rest == infinity)
            {
                cout << "They have failed!" << endl;
                return nights++;
            }
            nights++;
            mutants_rest -= n;
            if (mutants_rest <= 0)
            {
                return nights;
            }
            cout << "After destruction left: " << mutants_rest << endl;
            mutants_rest = floor(mutants_rest + (mutants_rest != 1 ? (mutants_rest * (p / 100.00)) : (p == 100.00) ? 1 : 0));
            cout << "After reproduction: " << mutants_rest << endl;
        }
    }
    else
    {
        return 1;
    }

    cout << nights;
}

bool isNumber(string str)
{
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
bool isPercent(string str)
{
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            if (str[i] != '.')
            {
                return false;
            }
        }
    }
    if (atof(str.c_str()) > 100 || atof(str.c_str()) < 0)
    {
        return false;
    }
    return true;
}

int isCorrectType(string errMsg, bool isDouble)
{
    string num;
    int value;
    string msg;

    while (!(cin >> num) || (isDouble ? !isPercent(num) : !isNumber(num)))
    {
        msg = "Incorrect value";
        cout << "Error" << endl;
        cout << msg << endl;
        cout << errMsg << endl;
        cout << "Input again!: ";
        cin.clear();
        fflush(stdin);
    }
    value = atof(num.c_str());
    return value;
}

