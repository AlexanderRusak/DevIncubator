#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <time.h>
#include "windows.h"
#define SIDE 3

using namespace std;

void createPlayField(string array[][SIDE]);
void showPlayField(string array[][SIDE]);
void makeMove(string array[][SIDE]);
void showMessage(string message);
bool isEmptyField(string array[][SIDE], int move);
void moveAI(string array[][SIDE]);
bool isWin(string array[][SIDE]);
bool isMatchHorizontal(string array[][SIDE]);
bool isMatchVertical(string array[][SIDE]);
bool isMatchDiagonal(string array[][SIDE]);
int game();
int main()
{

    while(true){
    	system("cls");
    	game();
    	cout<<endl;
    	showMessage("Press any key to strat new game");
    	cout<<endl;
    	system("pause");
    }
    
  
	return 0;
}

void createPlayField(string array[][SIDE])
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

void showPlayField(string array[][SIDE])
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
void makeMove(string array[][SIDE])
{
	int move = 0;
	int moveCounter = 0;
	string cross = "|X|";
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
				showMessage("\n");
				showPlayField(array);
				makeMove(array);
			}
		}
	}
}

void moveAI(string array[][SIDE])
{

	Sleep(1500);
	srand(time(NULL));
	
	int move = rand() % (SIDE * SIDE) + 1;
	int moveCounter = 0;
	string zero = "|0|";
	
	for (int i = 0; i < SIDE; i++)
	{
		for (int j = 0; j < SIDE; j++)
		{
			moveCounter++;
			if (moveCounter == move && isEmptyField(array, move))
			{
				array[i][j] = zero;
			}
			else if (moveCounter == move && !isEmptyField(array, move) || move == 0)
			{
				moveAI(array);
			}
		}
	}
}

void showMessage(string message)
{
	cout << message;
}
bool isEmptyField(string array[][SIDE], int move)
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
bool isWin(string array[][SIDE])
{

	if (isMatchHorizontal(array) || isMatchVertical(array) || isMatchDiagonal(array))
		return true;
	return false;
}
bool isMatchHorizontal(string array[][SIDE])
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
			else if (array[i][j] == "|0|")
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
bool isMatchVertical(string array[][SIDE])
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
			else if (array[j][i] == "|0|")
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
bool isMatchDiagonal(string array[][SIDE])
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
			else if (array[j][j] == "|0|")
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
			else if (array[i][j] == "|0|")
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
int game(){
	
	string field[SIDE][SIDE];
	int moves = SIDE * SIDE;
	
	createPlayField(field);
	showPlayField(field);
	
	while (moves != 0)
	{

		makeMove(field);
		system ("cls");
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
		system ("cls");
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
