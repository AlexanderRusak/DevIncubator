#include <iostream>
#include <math.h>
#include <cstdlib>
#include <math.h>  
#define SIZE 5

using namespace std;
  
void showPowerOfTwo(double numbers[],int size);
  
int main(){
    double numbers[SIZE]={1,4,1,3,11};
    showPowerOfTwo(numbers,SIZE);
	return 0;
}

void showPowerOfTwo(double numbers[],int size){
	bool flag=false;
	for(int i=0 ;i<SIZE;i++){
		if(sqrt(numbers[i])-(int)(sqrt(numbers[i]))==0 && numbers[i]>1){
			cout<<numbers[i]<<endl;
			flag=true;
		}
	}
	if(!flag){
		cout<<"Not found!";
	}
}
