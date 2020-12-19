#include <iostream>
#include <cmath>
#include <typeinfo>
#include <string>

using namespace std;

void bishops();
void createChessBoard(char **chessboard, int sz);
void showBoard(char **chessboard, int sz);

bool isNumber(string str);
int isCorrectInput(int value);
int isCorrectType();

int main()
{
    bishops();
    return 0;
}

void bishops()
{
    int size = 9;
    int min = 1;
    int x1, y1, x2, y2;
    char *taken = "NOPE!";
    char **chessBoard = new char *[size];

    for (int i = 0; i < size; i++)
    {
        chessBoard[i] = new char[size];
    }

    createChessBoard(chessBoard, size);
    cout << "Input value x1 form 1 to 8:";
    x1 = isCorrectInput(isCorrectType());
    cout << "Input value y1 form 1 to 8:";
    y1 = isCorrectInput(isCorrectType());
    cout << "Input value x2 form 1 to 8:";
    x2 = isCorrectInput(isCorrectType());
    cout << "Input value y2 form 1 to 8:";
    y2 = isCorrectInput(isCorrectType());
    chessBoard[x1][y1] = 'F';
    chessBoard[x2][y2] = 'S';

    if (x1 == x2 and y1 == y2)
    {
        cout << "You can't set second bishop on first bishop\n"
             << "Try again!\n";
        bishops();
    }

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
            taken = "To take!!!";
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
            taken = "To take!!!";
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
            taken = "To take!!!";
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
            taken = "To take!!!";
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
    cout << taken << endl;
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

int isCorrectType()
{
    string num;
    int value;
    string msg;
    while (!(cin >> num) || !isNumber(num))
    {
        msg = isNumber(num) ? "Chessdesc has 8 ceils" : "Incorrect value";
        cout << "Error" << endl;
        cout << msg << endl;
        cout << "Input value from 1 to 8:";
        cin.clear();
        fflush(stdin);
    }
    value = atof(num.c_str());
    return value;
}
int isCorrectInput(int value)
{

    while (value < 1 || value > 8)
    {

        cin.clear();
        fflush(stdin);
        cout << "Error" << endl;
        cout << "Chessdesc has 8 ceils" << endl;
        cout << "Input value from 1 to 8:";
        cin >> value;
    }
    return value;
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

