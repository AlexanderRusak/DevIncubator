#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>
#define SIZE 10

using namespace std;

void showUnvisiblePoints( double array[]);
void showAllCoordinates(double array[]);
void generateCoordinates( double array[]);
double getTanAlpha( int height, int widht);

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
	  double topAlpha;
	  bool flag=false;
	  
	for(int i=1 ;i<SIZE; i++){
	  	if(array[i]>watcher){
	  		int height=array[i]-array[0];
	  		topAlpha=getTanAlpha(height, i);
	  		i=SIZE;
	  	}
	  }
	  
	  cout<<"Unvisible points are: ";
	  

	for(int i=1;i<SIZE;i++){
	  	if( array[i]>watcher && topAlpha>getTanAlpha(array[i]-array[0],i)){
	  		cout<<array[i]<<", ";
	  	} else if( array[i]>=watcher && flag==false  && top==watcher){
	  		top=array[i];
	  		flag=true;
	  		
	  	}else if( array[i]<watcher && flag==true){
	  		cout<<array[i]<<", ";
	  		
	  	}

	  }
}
void generateCoordinates( double array[]){
	srand(time(NULL));
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

double getTanAlpha( int height, int width){
	double alpha;
	alpha=height/width;
	return alpha;
}
