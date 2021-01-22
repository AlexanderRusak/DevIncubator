#include <iostream>
#include <math.h>
using namespace std;

int binary_search(int array_of_sorted_numbers[], int number, const int SZ);

int main(){
	const int SIZE=10;
    int numbers[SIZE]={1,2,3,4,5,6,7,8,9,10};
    cout<<binary_search(numbers,8,SIZE);
    return 0;
}


int binary_search(int array_of_sorted_numbers[], int number, const int SZ){
	
	int min=0;
	int max=SZ-1;  
	int mid;

    while(min<=max){
    	mid=ceil((min+max)/2);
    	if(array_of_sorted_numbers[mid]==number){
    		return number;
    	}
    	else if(number<array_of_sorted_numbers[mid]){
    		max=mid-1;
    	}
    	else if(number>array_of_sorted_numbers[mid]){
    		min=mid+1;
    	}
    }
	
	
}

