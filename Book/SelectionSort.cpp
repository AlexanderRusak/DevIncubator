#include <iostream>
#include <math.h>
using namespace std;

int getSmllestIndexOfArr(int num[],int sz);
void selectionSort(int arr[],int sz);

int main(){
	const int SZ=7;
    int numbers[SZ]={7,0,-4,3,1,-2,5};
    //cout<<getSmllestIndexOfArr(numbers,SZ);
    selectionSort(numbers,SZ);
    return 0;
}


int getSmllestIndexOfArr(int num[],int sz){
	int smallest=num[1];
	for(int i=1; i < sz; i++){
		if(num[i]<smallest){
			smallest=num[i];
		}
	}
	return smallest;
}  

void selectionSort(int arr[],int sz){
	
	int prev;
	int buf;
	int bufIndex;
	int compareNumber;
    for(int i=1;i<sz;i++){
    	for(int j=1; j<sz; j++){
    		if(arr[j-1]>arr[j]){  
    			buf=arr[j];          
    			bufIndex=j;         
    		}
    		cout<<buf<<"<-buf bufIndex->"<<bufIndex<<endl;
    		cout<<"next "<<i<<endl;
    		arr[bufIndex]=arr[j-1];
    		arr[j-1]=buf;
    		cout<<buf<<"<-buf bufIndex->"<<bufIndex<<endl;
    	}

    	
    }
    for(int i=0;i<sz;i++){
    	cout<<arr[i]<<endl;
    }
}  

