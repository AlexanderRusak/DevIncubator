#include <iostream>

using namespace std;

void quickSort(int array[] , int sz);

int main(){
	
	const int SZ=4;
	int array[SZ]= {10,5,2,3};
	
    quickSort(array,SZ);
	return 0;
}



void quickSort(int array[] , int sz){
	if(sz<2){
		for(int i=0;i<sz;i++){
			cout<<array[i]<<",";
		}
		cout<<endl;
	}
	int pivot=array[0];
	int lessNumbersCount=0,lessIndex=0;
	int greaterNumbersCount=0,greaterIndex=0;
	int *lessArray;
	int *greaterArray;
	for(int i=0;i<sz;i++){
		if(array[i]<pivot){
			lessNumbersCount++;
			lessArray=new int[lessNumbersCount];
		} else if(array[i]>pivot){
			greaterNumbersCount++;
			greaterArray=new int[greaterNumbersCount];
		}
	}
	for(int i=0;i<sz;i++){
		if(array[i]<pivot){
			lessArray[lessIndex]=array[i];
			lessIndex++;
		} else if(array[i]>pivot){
			greaterArray[greaterIndex]=array[i];
			greaterIndex++;
		}
	}
	
	
	for(int i=0;i<lessNumbersCount;i++){
		cout<<lessArray[i]<<endl;
	}
	cout<<pivot<<endl;
	for(int i=0;i<greaterNumbersCount;i++){
		cout<<greaterArray[i]<<endl;
	}
	cout<<"Next"<<endl;
	quickSort(lessArray , lessNumbersCount);
	cout<<pivot<<endl;
	quickSort(greaterArray , greaterNumbersCount);
	
	 
}




