#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <time.h>
#include "windows.h"
#define SIDE 3

using namespace std;

void createPlayField(char *array[][4]);
void showPlayField(char *array[][4]);
void makeMove(char *array[][4]);
void showMessage(char *message);
bool isEmptyField(char *array[][4], int move);
bool moveAI(char *array[][4]);
bool isWin(char *array[][4]);
bool isMatchHorizontal(char *array[][4]);
bool isMatchVertical(char *array[][4]);
bool isMatchDiagonal(char *array[][4]);

int getVerticaLine(char *array[][4]);
int getHorizontalLine(char *array[][4]);
int getDiagonal(char *array[][4]);
void setMoveH(char *array[][4], int line);
void setMoveV(char *array[][4], int line);
void setMoveD(char *array[][4], int line);
bool setMoveImportantPlace(char *array[][4]);
void moveAIRest(char *array[][4]);
int game();
int main()
{

    while (true)
    {
        system("cls");

        game();

        cout << endl;

        showMessage("Press any key to start new game");

        cout << endl;

        system("pause");
    }

    return 0;
}

void createPlayField(char *array[][4])
{
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (i == SIDE - 1)
            {
                array[i][j] = "| |";
            }
            else
            {
                array[i][j] = "|_|";
            }
        }
    }
}

void showPlayField(char *array[][4])
{
    cout << endl;

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            cout << array[i][j];
        }

        cout << endl;
    }
}
void makeMove(char *array[][4])
{
    int move = 0;
    int moveCounter = 0;
    char *cross = "|X|";

    showMessage("Please make your move: ");

    cin >> move;

    while (move < 1 || move > (SIDE * SIDE))
    {
        cin.clear();
        fflush(stdin);

        showMessage("Error!");

        cout << endl;

        showMessage("Please make your move: ");

        cin >> move;
    }
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            moveCounter++;

            if (moveCounter == move && isEmptyField(array, move))
            {
                array[i][j] = cross;
            }
            else if (moveCounter == move && !isEmptyField(array, move))
            {
                showMessage("Error! Already taken! ");

                cout << endl;

                showPlayField(array);

                makeMove(array);
            }
        }
    }
}

bool moveAI(char *array[][4])
{
    int line;

    if (getVerticaLine(array) != -1)
    {
        line = getVerticaLine(array);
        setMoveV(array, line);
        return true;
    }
    if (getHorizontalLine(array) != -1)
    {
        line = getHorizontalLine(array);
        setMoveH(array, line);
        return true;
    }
    if (getDiagonal(array) != -1)
    {
        line = getDiagonal(array);
        setMoveD(array, line);
        return true;
    }
    if (!setMoveImportantPlace(array))
    {
        moveAIRest(array);
        return true;
    }
    else
    {
    }
}

void showMessage(char *message)
{
    cout << message;
}
bool isEmptyField(char *array[][4], int move)
{
    int moveCounter = 0;

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            moveCounter++;
            if (moveCounter == move && (array[i][j] == "|X|" || array[i][j] == "|0|"))
            {
                return false;
            }
        }
    }
    return true;
}
bool isWin(char *array[][4])
{

    if (isMatchHorizontal(array) || isMatchVertical(array) || isMatchDiagonal(array))
        return true;
    return false;
}
bool isMatchHorizontal(char *array[][4])
{
    int counterX = 0;
    int counter0 = 0;

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (array[i][j] == "|X|")
            {
                counterX++;
            }
            if (array[i][j] == "|0|")
            {
                counter0++;
            }
        }

        if (counterX == 3 || counter0 == 3)
        {
            return true;
        }
        counterX = 0;
        counter0 = 0;
    }
}
bool isMatchVertical(char *array[][4])
{
    int counterX = 0;
    int counter0 = 0;

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (array[j][i] == "|X|")
            {
                counterX++;
            }
            if (array[j][i] == "|0|")
            {
                counter0++;
            }
        }

        if (counterX == 3 || counter0 == 3)
        {
            return true;
        }
        counterX = 0;
        counter0 = 0;
    }
    return false;
}
bool isMatchDiagonal(char *array[][4])
{
    int counterX = 0;
    int counter0 = 0;

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (array[j][j] == "|X|")
            {
                counterX++;
            }
            if (array[j][j] == "|0|")
            {
                counter0++;
            }
        }

        if (counterX == 3 || counter0 == 3)
        {
            return true;
        }
        counterX = 0;
        counter0 = 0;
    }
    for (int i = 0; i < SIDE;)
    {
        for (int j = SIDE - 1; j >= 0; j--, i++)
        {
            if (array[i][j] == "|X|")
            {
                counterX++;
            }
            if (array[i][j] == "|0|")
            {
                counter0++;
            }
        }

        if (counterX == 3 || counter0 == 3)
        {
            return true;
        }
        counterX = 0;

        counter0 = 0;
    }
    return false;
}
int game()
{

    char *field[SIDE][4];
    int moves = SIDE * SIDE;

    createPlayField(field);
    showPlayField(field);

    while (moves != 0)
    {

        makeMove(field);

        system("cls");

        moves--;

        showPlayField(field);

        if (isWin(field))
        {
            showMessage("You win!");
            return 1;
        }
        if (moves == 0)
        {
            break;
        }
        showMessage("AI is making move");

        moveAI(field);

        system("cls");

        showPlayField(field);

        moves--;

        if (isWin(field))
        {
            showMessage("AI win!");
            return 1;
        }
    }
    showMessage("Draw game");
}

int getVerticaLine(char *array[][4])
{
    int counterX = 0;
    int counter0 = 0;
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (array[j][i] == "|X|")
            {
                counterX++;
            }
            if (array[j][i] == "|0|")
            {
                counter0++;
            }
        }

        if (counterX == 2 && counter0 == 0)
        {
            return i;
        }
        counterX = 0;
        counter0 = 0;
    }
    return -1;
}
int getHorizontalLine(char *array[][4])
{
    int counterX = 0;
    int counter0 = 0;

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (array[i][j] == "|X|")
            {
                counterX++;
            }
            if (array[j][i] == "|0|")
            {
                counter0++;
            }
        }

        if (counterX == 2 && counter0 == 0)
        {
            return i;
        }
        counterX = 0;
        counter0 = 0;
    }
    return -1;
}
int getDiagonal(char *array[][4])
{
    int counterX = 0;
    int counter0 = 0;

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (array[j][j] == "|X|")
            {
                counterX++;
            }
            if (array[j][i] == "|0|")
            {
                counter0++;
            }
        }

        if (counterX == 2 && counter0 == 1)
        {
            return i;
        }
        counterX = 0;
        counter0 = 0;
    }
    for (int i = 0; i < SIDE;)
    {
        for (int j = SIDE - 1; j >= 0; j--, i++)
        {
            if (array[i][j] == "|X|")
            {
                counterX++;
            }
            if (array[j][i] == "|0|")
            {
                counter0++;
            }
        }

        if (counterX == 2 && counter0 == 1)
        {
            return i - 1;
        }
        counterX = 0;
    }
    return -1;
}
void setMoveH(char *array[][4], int line)
{

    for (int j = 0; j < SIDE; j++)
    {

        if (array[line][j] != "|X|")

        {
            array[line][j] = "|0|";
        }
    }
}
void setMoveV(char *array[][4], int line)
{

    for (int j = 0; j < SIDE; j++)
    {

        if (array[j][line] != "|X|")

        {
            array[j][line] = "|0|";
        }
    }
}
void setMoveD(char *array[][4], int line)
{
    int counterX = 0;

    if (line == 0)
    {
        int i = 0;
        for (int j = 0; j < SIDE; j++, i++)
        {
            if (array[i][j] != "|X|")
            {
                array[i][j] = "|0|";
            }
        }
    }

    if (line == 2)
    {
        int i = 0;
        for (int j = SIDE - 1; j >= 0; j--, i++)
        {
            if (array[i][j] != "|X|")
            {
                array[i][j] = "|0|";
            }
        }
    }
}

bool setMoveImportantPlace(char *array[][4])
{
    char *zero = "|0|";

    if (isEmptyField(array, 1))
    {
        array[0][0] = zero;
        return true;
    }
    if (isEmptyField(array, 3))
    {
        array[0][2] = zero;

        return true;
    }
    if (isEmptyField(array, 7))
    {
        array[2][0] = zero;
        return true;
    }

    if (isEmptyField(array, 5))
    {
        array[1][1] = zero;
        return true;
    }
    if (isEmptyField(array, SIDE * SIDE))
    {
        array[2][2] = zero;
        return true;
    }
    else
    {
        return false;
    }
}
void moveAIRest(char *array[][4])
{

    Sleep(1500);
    srand(time(NULL));

    int move = rand() % (SIDE * SIDE) + 1;
    int moveCounter = 0;
    char *zero = "|0|";

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            moveCounter++;

            if (moveCounter == move && isEmptyField(array, move))
            {
                cout << move << endl;
                array[i][j] = zero;
            }
            else if (moveCounter == move && !isEmptyField(array, move) || move == 0)
            {
                cout << move << endl;
                moveAI(array);
            }
        }
    }
}
