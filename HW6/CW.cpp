#include <iostream>
#include <math.h>
#include <cstdlib>
#include <math.h>  


using namespace std;

bool isNumber(char array[]);
bool isAlpha(char symbol); 
bool isWord(char array[]);
int stringToInt(char array[]);

int main(){
    char number[]="qwqwqwq";
    cout<< isNumber(number);
    char alpha='{';
    cout<< isAlpha(alpha); 
    char word[]="WQWQWQWQWSXCdddd";
    cout<<isWord(word);
    cout<<stringToInt(number);
	return 0;
}



bool isNumber(char array[]){
	for(int i = 0; i < array[i] != '\0'; i++){
		if(array[i] < 48 || array[i] > 58){
			return false;
		}
	}
	return true;
}

bool isAlpha(char symbol){
	
	if(  (symbol < 'a' || symbol > 'z') && (symbol < 'A' || symbol > 'Z')  )
	{
		 return false;
	}
		
	return true;
}

bool isWord(char array[]){
	for ( int i = 0; i < array[i] != '\0'; i++ ) {
		if(  (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z')  ){
			return false;	
		}
	}
	return true;
}
int stringToInt(char array[]){
    int result = 0;
    if(!isNumber(array)) return -1;
    for(int i=0 ;array[i]!='\0';i++){
       result*=10;
       result+=array[i]-'0';
    }
    return result;
}
