#include <iostream>
#include <math.h>
using namespace std;

int getSmllestIndexOfArr(int num[],int sz);
void selectionSort(int arr[],int sz);

int main(){
	const int SZ=7;
    int numbers[SZ]={7,0,-4,3,1,-2,5};
    getSmllestIndexOfArr(numbers,SZ);
    //selectionSort(numbers,SZ);
    return 0;
}


int getSmllestIndexOfArr(int num[],int sz){
	int smallest;
	int smallestIndex;
	for(int i=0;i<sz; i++){
		smallest=num[i];
		smallestIndex=i;
		for(int j=i+1; j < sz; j++){
			if(num[j]<smallest){
				smallest=num[j];
				smallestIndex=j;
				}	
		}
		num[smallestIndex]=num[i];
		num[i]=smallest;
	}
   
  for(int i=0;i<sz;i++){
   	cout<<num[i]<<endl;
   }

	
	return smallest;
}  


