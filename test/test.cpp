#include <iostream>
#include <cmath>
using namespace std;
int isCorrectInput(int value, char message[], char errorMessage[]);
void electricityCounter();
void elephants();
int mutants(int m, int p, int n);
void createChessBoard(char **chessboard, int sz);
void showBoard(char **chessboard, int sz);

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    //electricityCounter();
    elephants();
    //cout<<mutants(6,100,5);

    return 0;
}

int isCorrectInput(int value)
{

    while (value < 1 || value > 8)
    {
        cin.clear();
        fflush(stdin);
        cout << "Îøèáêà" << endl;
        cout << "Øàõìàòíàÿ äîñêà èìååò 8 êëåòîê" << endl;
        cout << "Ââåäèòå çíà÷åíèå îò 1 äî 8:";
        cin >> value;
    }
    return value;
}

void electricityCounter()
{
    double value;
    cout << "Ââåäèòå êîëè÷åñâî êÂò*÷:";
    while (!(cin >> value))
    {
        cout << "Íåêîðåêòíûå äàííûå" << endl;
        cout << "Ââåäèòå êîëè÷åñâî êÂò*÷:";
        cin.clear();
        fflush(stdin);
    }
    const double ELECTRICITY_COST = 0.25935;
    cout << "Ñîèìîñòü: " << ELECTRICITY_COST * value << " áåë. ðóáëè" << endl;
}
void elephants()
{
    int size = 9;
    int min = 1;
    int x1, y1, x2, y2;
    char **chessBoard = new char *[size];
    for (int i = 0; i < size; i++)
        chessBoard[i] = new char[size];
    createChessBoard(chessBoard, size);
    cout << "Ââåäèòå çíà÷åíèå õ1 îò 1 äî 8:";
    cin >> x1;
    x1 = isCorrectInput(x1);
    cout << "Ââåäèòå çíà÷åíèå y2 îò 1 äî 8:";
    cin >> y1;
    y1 = isCorrectInput(y1);
    cout << "Ââåäèòå çíà÷åíèå õ2 îò 1 äî 8:";
    cin >> x2;
    x2 = isCorrectInput(x2);
    cout << "Ââåäèòå çíà÷åíèå y2 îò 1 äî 8:";
    cin >> y2;
    y2 = isCorrectInput(y2);
    chessBoard[x1][y1] = 'F';
    chessBoard[x2][y2] = 'S';
    showBoard(chessBoard, size);
    for (int i = x1, j = y1; i < size, j < size; i++, j++)
    {
        if (i == size or j == size)
        {
            break;
        }
        if (chessBoard[i][j] == 'S')
        {
            chessBoard[i][j] = 'S';
            cout << "Goal!";
        }
        else
        {
            chessBoard[i][j] = 'F';
        }
    }
    for (int i = x1, j = y1; i >= 1, j >= 1; i--, j--)
    {

        if (chessBoard[i][j] == 'S')
        {
            chessBoard[i][j] = 'S';
            cout << "Goal!";
        }
        else
        {
            chessBoard[i][j] = 'F';
        }
        if (i == 1 or j == 1)
        {
            break;
        }
    }
    for (int i = x1, j = y1; i < size, j >= 1; i++, j--)
    {
        if (i == size)
        {
            break;
        }
        if (chessBoard[i][j] == 'S')
        {
            chessBoard[i][j] = 'S';
            cout << "Goal!";
        }
        else
        {
            chessBoard[i][j] = 'F';
        }
        if (j == 1)
        {
            break;
        }
    }
    for (int i = x1, j = y1; j < size, i >= 1; i--, j++)
    {
        if (j == size)
        {
            break;
        }
        if (chessBoard[i][j] == 'S')
        {
            chessBoard[i][j] = 'S';
            cout << "Goal!";
        }
        else
        {
            chessBoard[i][j] = 'F';
        }
        if (i == 1)
        {
            break;
        }
    }
    cout << endl;
    showBoard(chessBoard, size);
}

int mutants(int m, int p, int n)
{
    int nights = 0;
    int mutants_rest;
    p = (double)p / 100;
    double mutants_increment;
    if ((m - n) > 0)
    {
        mutants_rest = m;
        while (mutants_rest > 0)
        {
            nights++;
            mutants_rest -= n;
            if (mutants_rest <= 0)
            {
                return nights;
            }
            mutants_increment = ceil(mutants_rest + (mutants_rest * p));
            cout << "Ïîñëå óíè÷òîæåíèÿ îñòàëîñü: " << mutants_rest << ","
                 << "Ïîñëå ðàçìíîæåíèÿ: " << mutants_increment << endl;
        }
    }
    else
    {
        return 1;
    }

    return nights;
}
void createChessBoard(char **chessboard, int sz)
{

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {

            if ((j % 2 == 1 and i % 2 == 0) or (j % 2 == 0 and i % 2 == 1))
            {
                chessboard[i][j] = '#';
            }
            else if ((j % 2 == 0 and i % 2 == 0) or (j % 2 == 1 and i % 2 == 1))
            {
                chessboard[i][j] = ' ';
            }
            if (j == 0)
            {
                chessboard[i][j] = (i) + '0';
            }
            else if (i == 0)
            {
                chessboard[i][j] = (j) + '0';
            }
            if (j == 0 and i == 0)
            {
                chessboard[i][j] = ' ';
            }
        }
    }
}
void showBoard(char **chessboard, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            cout << chessboard[i][j];
        }
        cout << endl;
    }
}