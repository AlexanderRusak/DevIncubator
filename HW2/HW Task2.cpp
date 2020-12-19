#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <typeinfo>

using namespace std;

int convertToBinaryThenDecimal();

int main()
{
    convertToBinaryThenDecimal();
    return 0;
}

int convertToBinaryThenDecimal(){
	int num, inputNumber, length, resDecimal;
	string resultBinary, result, str;
	
	cout << "Enter your number to convert from decimal to binary number then decimal: ";
	cin >> num;
	while(!cin >> num || num < 0){
		cout << "Invalid type of input" << endl;
		cout << "Enter your number to convert from decimal to binary number then deciml: ";
	    cin.clear();
        fflush(stdin);
        cin >> num;
	}

	inputNumber=num;
	while( num!=0 ){

		result += num%2 + '0'; 
		num = num/2;      
	}
	for(int i = result.length() - 1;i >= 0;i--){
		resultBinary += result[i];
	}
	length=resultBinary.length();
	
	str=resultBinary;
	
	for(int i=0;i<resultBinary.length();i++){
		
	 str[i]= (int)str[i] - 48;  //refact
	 
	 resDecimal+=str[i]*pow(2,length-1);
	 
	 length--;
	 
	}
	cout<<inputNumber<<"<=>"<<resultBinary<<endl;
	cout<<resultBinary<<"<=>"<<resDecimal<<endl;
}


