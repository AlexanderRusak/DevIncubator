#include <iostream>
using namespace std;

#define USD_RATE 2.548
#define EUR_RATE 3.103
#define RUB_RATE 3.385

void showMenu();
double inputBYN(double byn);
double convertToUSD(double byn);
double convertToEUR(double byn);
double convertToRUB(double byn);

void showBalance(double byn, double rub, double usd, double eur);
void showErrorMessage(double current);
int main()
{
    int userChoise = 0; // user choice
    double byn = 0.0;   // áåë âàëþòà
    double usd = 0.0;
    double eur = 0.0;
    double rub = 0.0;
    double exchanging = 0.0;

    while (true)
    {
        showMenu();
        cout << "Your choice? ";
        cin >> userChoise;
        if (userChoise == 1)
        {
            byn = inputBYN(byn);
            cout << "Ok, " << byn << " BYN is receved." << endl;
            showBalance(byn, rub, usd, eur);
        }
        else if (userChoise == 2)
        {
            exchanging = 0.0;
            exchanging = convertToUSD(byn);
            cout << "Ok, take your " << exchanging << " USD." << endl;
            usd += exchanging;
            byn -= exchanging * USD_RATE;
            showBalance(byn, rub, usd, eur);
            exchanging = 0.0;
        }
        else if (userChoise == 3)
        {
            exchanging = 0.0;
            exchanging = convertToEUR(byn);
            cout << "Ok, take your " << exchanging << " EUR." << endl;
            eur += exchanging;
            byn -= exchanging * EUR_RATE;
            showBalance(byn, rub, usd, eur);
            exchanging = 0.0;
        }
        else if (userChoise == 4)
        {
            exchanging = 0.0;
            exchanging = convertToRUB(byn);
            cout << "Ok, take your " << exchanging << " RUB." << endl;
            rub += exchanging;
            byn -= exchanging * RUB_RATE / 100;
            showBalance(byn, rub, usd, eur);
            exchanging = 0.0;
        }
        else if (userChoise == 5)
            break;
        else
            cout << "Input [1..5], please" << endl
                 << endl;
    }

    return 0;
}

void showMenu()
{
    cout << "1) Input BYN" << endl;
    cout << "2) Convert to USD" << endl;
    cout << "3) Convert to EUR" << endl;
    cout << "4) Convert to RUB" << endl;
    cout << "5) Exit" << endl;
}

double inputBYN(double byn)
{
    double inputCountOfMoneyToChange;
    cout << "Input how much BYN do you want to exchange? or input 0 for return to main menu ";
    cin >> inputCountOfMoneyToChange;
    while (byn + inputCountOfMoneyToChange < 0)
    {
        showErrorMessage(byn);
        cin >> inputCountOfMoneyToChange;
    }
    return byn + inputCountOfMoneyToChange;
}

double convertToUSD(double byn)
{
    double inputCountOfMoneyToChange;
    cout << "How much BYN do you want to exchange to USD? ";
    cin >> inputCountOfMoneyToChange;
    while (byn < inputCountOfMoneyToChange || inputCountOfMoneyToChange < 0)
    {
        showErrorMessage(byn);
        cin >> inputCountOfMoneyToChange;
    }
    return inputCountOfMoneyToChange / USD_RATE;
}

double convertToEUR(double byn)
{
    double inputCountOfMoneyToChange;
    cout << "How much BYN do you want to exchange to EUR? ";
    cin >> inputCountOfMoneyToChange;
    while (byn < inputCountOfMoneyToChange || inputCountOfMoneyToChange < 0)
    {
        showErrorMessage(byn);
        cin >> inputCountOfMoneyToChange;
    }
    return inputCountOfMoneyToChange / EUR_RATE;
}

double convertToRUB(double byn)
{

    double inputCountOfMoneyToChange;
    cout << "How much BYN do you want to exchange to RUB? ";
    cin >> inputCountOfMoneyToChange;
    while (byn < inputCountOfMoneyToChange || inputCountOfMoneyToChange < 0)
    {
        showErrorMessage(byn);
        cin >> inputCountOfMoneyToChange;
    }
    return inputCountOfMoneyToChange * 100 / RUB_RATE;
}
void showBalance(double byn, double rub, double usd, double eur)
{
    cout << "Your balance are:" << endl;
    cout << "BYN: " << byn << endl;
    cout << "USD: " << usd << endl;
    cout << "EUR: " << eur << endl;
    cout << "RUB: " << rub << endl
         << endl;
}
void showErrorMessage(double current)
{
    cout << "Incorrect value!" << endl;
    cout << "Your current balance is " << current << " BYN" << endl;
    cout << "Input correct value or 0 for exit: ";
}