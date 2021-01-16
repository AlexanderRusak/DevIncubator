#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>
#define SIZE 10

using namespace std;

void showUnvisiblePoints( double array[]);
void showAllCoordinates(double array[]);
void generateCoordinates( double array[]);

int main(){
  
    double coordinates[SIZE]={0};
    
    generateCoordinates(coordinates);
    showAllCoordinates(coordinates);
    showUnvisiblePoints(coordinates);
    
	return 0;
}

void showUnvisiblePoints( double array[]){
	  double top = array[0];
	  double watcher=array[0];
	  bool flag=false;
	  cout<<"Unvisible points are: ";
	  for(int i=1;i<SIZE;i++){
	  	if(top>=watcher && array[i]<=top && flag==true){
	  		cout<<array[i]<<", ";
	  	}
	  	if(array[i] >= top){
	  		top = array[i];
	  		flag=true;
	  	}  
	  }
}
void generateCoordinates( double array[]){
	for(int i = 0; i < SIZE; i++){
		array[i]= rand() %100;
	}
}
void showAllCoordinates(double array[]){
	cout << "Coordinates: ";
	for(int i = 0; i < SIZE; i++){
		cout<<array[i]<<", ";
	}
	cout<<endl;
}
