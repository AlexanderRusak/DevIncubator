#include <iostream>
#include <math.h>
#include <cstdlib>
#define LIMIT 100000
#define SIZE 5
using namespace std;
  
void showNumbers(int limit);
int main(){
    showNumbers(numbers);
	return 0;
}



bool isPowerNumber(int number){
	bool result=false;
	for(int i = 0; i<=LIMIT; i++){
		if(number==i*i){
			return !result;
		}
	}
	return result;
	
}
void showNumbers(int array[]){
	for(int i=0; i < SIZE; i++){
		if(isPowerNumber(array[i])){
			cout<<array[i]<<" ";
		}
	}
}
