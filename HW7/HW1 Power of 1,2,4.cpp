#include <iostream>
#include <math.h>
#include <cstdlib>
#define LIMIT 10000
#define SIZE 10
using namespace std;
  
bool isPowerNumber(int number, int comparingNumber);
void showNumbers(int array[],int numbers);
int exponintationInPositivePower(int number,int power);
int main(){
    int numbers[SIZE]={2,4,8,1,5,16,32,64,2,-5};
    showNumbers(numbers,2);
    
	return 0;
}



bool isPowerNumber(int number,int comparingNumber){
	bool result=false;
	for(int i = 0; i<=LIMIT; i++){
		if(comparingNumber==pow(number,i)){
		
			return !result;
		}
	}
	return result;
	
}
void showNumbers(int array[],int numbers){
	for(int i=0; i < SIZE; i++){
		if(isPowerNumber(numbers,array[i])){
			cout<<array[i]<<" ";
		}
	}
}

int exponintationInPositivePower(int number,int power){
	int result=1;
	if(power==0){
		return 1;
	}
	for(int i=0; i<power ;i++){
		result*=number;
	}
	return result;
}
