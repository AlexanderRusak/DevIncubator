#include <iostream>

using namespace std;

int getPositiveNumber(int number);
void showNumbersOfBinaryUnits(int num);
void showConvertToBinary(int decimalNumber);

int main()
{
    int number;
    number = getPositiveNumber(number);
    showNumbersOfBinaryUnits(number);
    return 0;
}

int getPositiveNumber(int number)
{
    cout << "Input number: ";
    cin >> number;
    
    while (!cin >> number || number <= 0)
    {
        cout << "Input error!" << endl;
        cout << "Input number > 0: ";
        cin >> number;
        cin.clear();
        fflush(stdin);
    }

    return number;
}

void showConvertToBinary(int decimalNumber)
{
    string resultBinary, result;
    
    while (decimalNumber != 0)
    {

        result += decimalNumber % 2 + '0';
        decimalNumber = decimalNumber / 2;
    }

    for (int i = result.length() - 1; i >= 0; i--)
    {
        resultBinary += result[i];
    }
    cout << resultBinary << endl;
}

void showNumbersOfBinaryUnits(int num)
{
    int previousNumber = 0;
    
    while (true)
    {
        if (2 * previousNumber + 1 <= num)
        {
            previousNumber = 2 * previousNumber + 1;
        }
        else
        {
            break;
        }
        cout << previousNumber << "<->";
        
        showConvertToBinary(previousNumber);
    }
}

