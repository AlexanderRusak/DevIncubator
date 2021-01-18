#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <time.h>
#include "windows.h"
#define SIDE 3

using namespace std;

void createPlayField(char* array[][4]);
void showPlayField(char*  array[][4]);
void makeMove(char*  array[][4]);
void showMessage(char* message);
bool isEmptyField(char*  array[][4], int move);
void moveAI(char*  array[][4]);
bool isWin(char*  array[][4]);
bool isMatchHorizontal(char*  array[][4]);
bool isMatchVertical(char*  array[][4]);
bool isMatchDiagonal(char*  array[][4]);
int game();
int main()
{

    while(true){
    	system("cls");
    	
    	game();
    	
    	cout<<endl;
    	
    	showMessage("Press any key to start new game");
    	
    	cout<<endl;
    	
    	system("pause");
    }
    
  
	return 0;
}

void createPlayField(char*  array[][4])
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

void showPlayField(char*  array[][4])
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
void makeMove(char*  array[][4])
{
	int move = 0;
	int moveCounter = 0;
	char* cross = "|X|";
	
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

void moveAI(char*  array[][4])
{

	Sleep(1500);
	
   	srand(time(NULL));
	
	int move = rand() % (SIDE * SIDE) + 1;
	int moveCounter = 0;
	char* zero = "|0|";
	
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

void showMessage(char* message)
{
	cout << message;
}
bool isEmptyField(char*  array[][4], int move)
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
bool isWin(char* array[][4])
{

	if (isMatchHorizontal(array) || isMatchVertical(array) || isMatchDiagonal(array))
		return true;
	return false;
}
bool isMatchHorizontal(char*  array[][4])
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
bool isMatchVertical(char*  array[][4])
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
bool isMatchDiagonal(char*  array[][4])
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
int game(){
	
	char* field[SIDE][4];
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
