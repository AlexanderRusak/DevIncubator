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




void bubbleSort(int arr[],int size){
	
	int buf;
	for(int i = 1; i < size; i++){
           for(int j=0; j < size; j++){
        		if(arr[j-1]>arr[j]){
        			buf=arr[j];
        			arr[j]=arr[j-1];
        			arr[j-1]=buf;
        		}
           }
	}
	for(int i=0;i<size;i++){
		cout<<arr[i]<<endl;
	}
}  

