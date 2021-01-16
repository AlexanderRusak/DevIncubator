#include <iostream>
#include <math.h>
#include <cstdlib>
#include <math.h>  
#include <string>  
#define SIDE 3

using namespace std;

void createPlayField(string array[][SIDE]);
void showPlayField(string array[][SIDE]);
void makeMove(string array[][SIDE]);
void showMessage(string message);
bool isDigit(char symbol);
  
int main(){
    string field[SIDE][SIDE];
    
    createPlayField(field);
    showPlayField(field);
    makeMove(field);
    showPlayField(field);
    

	return 0;
}

void createPlayField(string array[][SIDE]){
	for(int i=0;i<SIDE;i++){
		for(int j=0;j<SIDE;j++){
			if(i==SIDE-1){
			  array[i][j]="| |";	
			}
		    else{
			  array[i][j]="|_|";		
			}
		}
	}
}

void showPlayField(string array[][SIDE]){
	cout<<endl;
	for(int i=0;i<SIDE;i++){
		for(int j=0;j<SIDE;j++){
			cout<<array[i][j];
		}
		cout<<endl;
	}
}
void makeMove(string array[][SIDE]){
	int move=0;
	string cross="|X|";
	showMessage("Please make your move: ");
	cin>>move;

	while(move<1 || move>9 || !isDigit(move+'/0' ) ){
		cin.clear();
        fflush(stdin);
		showMessage("Error! Plese enter number form 1 to 9.");
		cout<<endl;
		showMessage("Please make your move: ");
		cin>>move;
	}
	switch(move){
		case 1:
			array[2][0]=cross;
			break;
		case 2:
			array[2][1]=cross;
			break;
		case 3:
			array[2][2]=cross;
			break;
		case 4:
			array[1][0]=cross;
			break;
		case 5:
			array[1][1]=cross;
			break;
		case 6:
			array[1][2]=cross;
			break;
		case 7:
			array[0][0]=cross;
			break;
		case 8:
			array[0][1]=cross;
			break;
		case 9:
			array[0][2]=cross;
			break;
			
	}
	
}

void showMessage(string message){
	cout<<message;
}
bool isDigit(char symbol){
	if(symbol < 47 || symbol > 58 ){
    	return false;
	}
	return true;
}

