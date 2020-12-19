#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>

using namespace std;

void electricityCounter();
bool isNumber(string str);

int main()
{
    electricityCounter();
    return 0;
}

void electricityCounter()
{
    double value;
    const double ELECTRICITY_COST = 0.25935;
    string str;

    cout << "Input value of kW*h:";

    while (!(cin >> str) || !(isNumber(str)))
    {
        cout << "Incorrect value" << endl;
        cout << "Input value of kW*h:";
        cin.clear();
        fflush(stdin);
    }

    value = atof(str.c_str());
    
    cout.precision(3);
    cout << "Input:" << str << " kW*h"
         << " Total cost: " << ELECTRICITY_COST * value << " BYN" << endl;
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

