#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

void initCube(int array[][SIZE][SIZE]);
void showMessage(char msg[]);
void showPlain(int array[][SIZE][SIZE]);
void checkClearance(int array[][SIZE][SIZE]);

using namespace std;

int main()
{

    int arr[SIZE][SIZE][SIZE];

    initCube(arr);
    checkClearance(arr);
    showPlain(arr);

    return 0;
}

void showMessage(char msg[])
{
    cout << msg << endl;
}

void showPlain(int array[][SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                cout << (array[i][j][k]);
            }
            cout << endl;
        }
        cout << endl;
    }
}
void initCube(int array[][SIZE][SIZE])
{
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                array[i][j][k] = rand() % 2;
            }
        }
    }
}

void checkClearance(int array[][SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {

        for (int x = 0; x < SIZE; x++)
        {
            for (int y = 0; y < SIZE; y++)
            {
                if (array[i][y][x] == 0)
                    break;
                if (y == SIZE - 1)
                    showMessage("you can see the light");
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {

        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                if (array[i][j][k] == 0)
                    break;
                if (k == SIZE - 1)
                    showMessage("you can see the light");
            }
        }
    }
}
