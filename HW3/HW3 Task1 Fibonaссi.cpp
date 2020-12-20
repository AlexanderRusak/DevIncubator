#include <iostream>
#include <string>
using namespace std;

int getMemberOfFibonacciSeries(int n);
void showSumOfFibonacciSeries(int n);
int getPositiveNumber(int number);
void showSumMessage(int number, int sum);
void showMessage(int number, int value);

int main()
{

    int number;

    number = getPositiveNumber(number);
    showSumOfFibonacciSeries(number);
    return 0;
}

int getMemberOfFibonacciSeries(int n)
{
    int bufferNumber, fibonacciNmuber = 0, prevFibonacciNumber = 1;

    if (n <= 1)
    {
        showMessage(n, fibonacciNmuber);

        return fibonacciNmuber;
    }

    for (int i = 1; i < n; i++)
    {
        if (n == 2)
        {
            fibonacciNmuber++;
        }
        else
        {
            bufferNumber = fibonacciNmuber;
            fibonacciNmuber = fibonacciNmuber + prevFibonacciNumber;
            prevFibonacciNumber = bufferNumber;
        }
    }
    showMessage(n, fibonacciNmuber);

    return fibonacciNmuber;
}

int getPositiveNumber(int number) ///Refact
{
    cout << "Input number: ";
    cin >> number;

    while (!cin >> number || number <= 0) ////!!!!!!!!!
    {
        cout << "Input error!" << endl;
        cout << "Input number > 0: ";
        cin >> number;
        cin.clear();
        fflush(stdin);
    }

    return number;
}
void showSumOfFibonacciSeries(int n)
{
    int sumOfFibinacciSeries = 0;

    for (int i = 1; i <= n; i++)
    {
        sumOfFibinacciSeries += getMemberOfFibonacciSeries(i);
    }
    showSumMessage(n, sumOfFibinacciSeries);
}
void showSumMessage(int number, int sum)
{
    cout << "Sum of Fibanacci series F(" << number << ") = " << sum << endl;
}
void showMessage(int number, int value)
{
    cout << "Fibinacci F(" << number << ") = " << value << endl;
}
