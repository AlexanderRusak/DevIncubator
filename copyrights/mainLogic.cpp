#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>

using namespace std;

void setNormalizeText(char* text);
bool isCapitalLetter(char letter);
void showString(char* str);
void splitString(char* string, int startWordPosition, int count);
bool isMatchString(char* str1, char* str2);
void getResult(char* fragment, char* text, int matchCount);


int main(){
    char str[]="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt consectetur adipiscing elit";
	char fragment[]="consectetur adipiscing elit";				
    showString(str);
    setNormalizeText(str);
    setNormalizeText(fragment);
    getResult(fragment,str,3);
  
	return 0;
}



void setNormalizeText(char* text)
{
    int count=0;
    for(int i=0; text[i]!='\0';i++){
    if((text[i]>96 && text[i]<123) || (text[i]>=65 && text[i]<=90)){
    	if(text[i]<97 || text[i]>123 ){
    		
    		if(isCapitalLetter(text[i])){
    			count++;
    		    
    			text[i]+=32;
    			}
    		}
    	}else{
    		text[i]=' ';
    	}
	}
}
bool isCapitalLetter(char letter){
	if(letter>=65 && letter<=90){
		return true;
	}
	return false;
}
void showString(char* str){
	for(int i=0; str[i]!='\0' ;i++){
	  cout<<str[i];
	}
	cout<<endl;
}


void getResult(char* fragment, char* text, int matchCount){
	int result=0;
	for(int i=0; text[i]!='\0'; i++){
		splitString(text,i,matchCount);
		splitString(fragment,i,matchCount);
	if(	isMatchString( text ,fragment ))
	{
		result++;	
	}
}
	cout<<result;
	
}

void splitString(char* string, int startWordPosition, int count){
	char buf[256];
	int length=0;
	int words=0;
	bool flag=false;
	int i=0,j=0;
	count+=startWordPosition;
	while( string[i]!='\0'){
		if(startWordPosition>=count){
			break;
		}
		while(string[i]==' ' ){
			if(!flag){
				words++;
			}
			flag=true;
			i++;
		}
		flag=false;
		if(count==words){
			break;
		}
		if(startWordPosition<=words){
				
			buf[j]=string[i];	
			length++;
			j++;
		}

		i++;
	
	}
    for(int i=0; string[i]!='\0';i++){
    	if(i<length){
    		string[i]=buf[i];
    	}else{
    		string[i]='\0';
    	}
    	
    }
}
bool isMatchString(char* str1, char* str2){
	 for(int i=0; str1[i]!='\0';i++){
		if(str1[i]!=str2[i]){
			return false;
		}
	}
	return true;
}

