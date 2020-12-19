#include <iostream>
#include <math.h>
using namespace std;

int getSmllestIndexOfArr(int num[],int sz);
void bubbleSort(int arr[],int sz);

int main(){
	const int SZ=10;
    int numbers[SZ]={50,3,4,1,7,10,15,8,9,25};
    //cout<<getSmllestIndexOfArr(numbers,SZ);
    bubbleSort(numbers,SZ);
    return 0;
}


int getSmllestIndexOfArr(int num[],int sz){
	int smallest=num[1];
	for(int i=1; i < sz; i++){
		if(num[i]<smallest){
			smallest=i;
		}
	}
	return smallest;
}  

void bubbleSort(int arr[],int sz){
	
	int buf;
	for(int i = 1; i < sz; i++){
           for(int j=1; j < sz; j++){
        		if(arr[j-1]>arr[j]){
        			buf=arr[j];
        			arr[j]=arr[j-1];
        			arr[j-1]=buf;
        		}
           }
	}
	for(int i=0;i<sz;i++){
		cout<<arr[i]<<endl;
	}
}  

