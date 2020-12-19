#include <iostream>

using namespace std;

int getMemberOfFibonacciSeries(int n);
void showSumOfFibonacciSeries(int n);
int getPositiveNumber(int number);

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
        cout << "Fibinacci F(" << n << ") = " << fibonacciNmuber << endl; ///!!!!!!!!!!
        
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
    cout << "Fibinacci F(" << n << ") = " << fibonacciNmuber << endl;   // !!!!!!
    
    return fibonacciNmuber;
}

int getPositiveNumber(int number)   ///Refact
{
    cout << "Input number: ";
    cin >> number;
    
    while (!cin >> number || number <= 0)   ////!!!!!!!!!
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
    
    cout << "Sum of Fibanacci series F(" << n << ") = " << sumOfFibinacciSeries << endl;   /// show  
}
