#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>
#include "windows.h"
 
#define SIZE 10
#define LEFT 60
#define RIGHT 62

using namespace std;
void generateSoldiers(char array[]);
void showAllRow(char array[]);
void goRound( char array[],bool fl);


int main(){
    int a;
    char soldiers[SIZE]={0};
    bool flag=false;
    generateSoldiers(soldiers);
    showAllRow(soldiers);
    goRound(soldiers, flag);
	return 0;
}

void showAllRow(char array[]){
	  
	  for(int i=0; i<SIZE ; i++){	  	
	  	cout<<array[i]<<" " ;
	  }
	  
}
void generateSoldiers(char array[]){
	 
	 srand(time (NULL));
	  for(int i=0; i<SIZE ; i++){
	  	if(rand()%2){
	  		array[i]=RIGHT;
	  	}else{
	  		array[i]=LEFT;
	  	}
	  	
	  }	  
}
void goRound( char array[], bool fl){
	Sleep(1000);
	fl=true;
	for(int i=1;i<SIZE;i++){
		if(array[i-1]==RIGHT && array[i]==LEFT){
			array[i-1]=LEFT;
			array[i]=RIGHT;
			fl=false;
		}
	}
    cout<<endl;
    if(!fl){
     showAllRow(array);
     goRound(array,fl);	
    }

}
