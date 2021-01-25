#include <iostream>
#include <cstdlib>



int strLength(char string[]);
void strCopy(char s1[] , char s2[]);
void strCat(char s1[], char s2[]);
void swapNumbers(char* str);

bool isNumber(char symbol);
char* setRest(char str[], int index);
bool isOdd(char number);
char* changeNumberToSymbol(char number, bool isOdd);

using namespace std;


int main()
{
    char* string="a3bcaaa";
    swapNumbers(string);
    
  
    return 0;
}



void swapNumbers(char* str){
   char* newString=new char[255];
   int length=strLength(str);
   int count = 0;
   int index=0;
   int totalCount=0;

   for(int i = 0; i < length ;i++){
   	cout<<length<<endl;
   	     if(isNumber(str[i])){
   	     	 count=str[i]-'0';
   	     	 length+=count-1;
   	     	 index+=count;
   	     	 cout<<count<<" "<<length<<" "<<index<<endl; 
   	     	for(int j = 0; j < count; j++){
   	     		if(isOdd(count)){
   	     			newString[i+j]='+';
   	     		}else{
   	     			newString[i+j]='-';
   	     		}
   	     	
   	     	}
   	     }else{
   	     	newString[i+index]=str[i];
   	     	cout<<str[i]<<endl;
   	     }
   }
totalCount=length;
cout<<totalCount<<endl;
char resultString[totalCount];
	for(int i=0; i<totalCount; i++){
		
		resultString[i]=newString[i];
		cout<<resultString[i];
	}
 
}
bool isNumber(char symbol){
	if(symbol>='0' && symbol<='9'){
		return true;
	}
	return false;
}
bool isOdd(char number){
	
	if(number%2==0){
		return true;
	}
	return false;
}

char* setRest(char str[], int index){
	char r[strLength(str)-index+1];
	for(int i=0; i < index; i++){
		r[i]=str[i];
		
	}
	cout<<"";
	return r;
}
char* changeNumberToSymbol(char number, bool isOdd){
	int num=number-'0';
	char* result;
		for(int i=0;i<num;i++){
			if(isOdd){
 				result[i]='+';
			
			}else{
				result[i]='-';	
			}
		}	
	cout<<endl;				
	return result;
}






int strLength(char string[]) {
    int counter = 0;

    while (string[counter] != '\0') counter++;

    return counter;
}

void strCopy(char s1[] ,char s2[]){
    int i = 0;
    while(s1[i] != '0'){
    		s2[i] = s1[i];
    		i++;
	}

}

void strCat(char s1[], char s2[])
{
    int size1 = strLength(s1);
    int size2 = strLength(s2);

    for(int i = 0; i < size1+size2; i++){
        s1[size1+i] = s2[i];
    }
}

