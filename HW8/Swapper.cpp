#include <iostream>
using namespace std;
#define SIZE 128


bool isDigit(char symbol);
int strLength(char str[]);
void swapNumber(char text[], int i, int number, int size, char symbol);

int main()
{
    char string[SIZE];
	char symbol;
	int number; int size;
	
    cout << "Input text: ";
    cin.getline(string, SIZE);

    for (int i = 0; string[i] != '\0'; i++) 
	{
        if (isDigit(string[i])) 
		{
			number = string[i]-'0';
			size = strLength(string);
			
			if(number % 2 == 0 && number != 0)
			{
				swapNumber(string, i, number, size, '+');			
			}

			if(number % 2 == 1)
			{
				swapNumber(string, i, number, size, '-');										
			}	
			
			if(number == 0)
			{				
				for(int j = i; j < size-1; j++)
				{
					string[j] = string[j+1];	
				}
			    		    
			    string[size-1] = 0;
				i--;												
			}																		
        }
    }
    
    cout << "Converted in: " << string;

    return 0;
}

bool isDigit(char symbol)
{
  	if(symbol>='0' && symbol<='9'){
		return true;
	}
	return false;
}

int strLength(char str[])
{
	int i = 0;
	
	while(str[i] != '\0')
	{
		i++;
	}

	return i;
}

void swapNumber(char text[], int i, int number, int size, char symbol)
{
	for(int k = size-1, l = k+number-1; k > i; k--, l--)
	{
		text[l] = text[k];		
	}	
				
	for(int j = 0; j < number; j++)
	{	    			    		
		text[i] = symbol;
		i++;		
	}
}
