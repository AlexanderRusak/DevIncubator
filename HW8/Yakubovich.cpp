#include <iostream>
#include <cstdlib>



int strLength(char string[]);
void strCopy(char s1[] , char s2[]);
void strCat(char s1[], char s2[]);

void fieldOfMiracle( char *str, char *hide);
void setOpenLetters(char* str, char* hide, char letter);
void showField(char* str);
bool isAlpha(char symbol); 
void initHideField(char* str, int size);
bool isOpenWord(char* hide);

using namespace std;


int main()
{
    char secretWord[]="aaavtomobil";
    int size=strLength(secretWord);
    char hideLetters[]="0";
    fieldOfMiracle(secretWord,hideLetters);
    return 0;
}

void fieldOfMiracle( char *str, char* hide){

	char letter;
	
	initHideField(hide, strLength(str));
	showField(hide);
	
	cout<<endl;
	while(!isOpenWord(hide)){
		
	

	cout<<"Enter a letter: ";
	cin>>letter;


	while(!cin || !isAlpha(letter)){
		cout << "Error!" << endl;
        cout << "Input letter: ";
        cin >> letter;
        cin.clear();
        fflush(stdin);
	}
	setOpenLetters(str,hide,letter);
	cout<<endl;
	showField(hide);
	cout<<endl;
}
}

void initHideField(char* str, int size){
	for(int i = 0; i < size; i++){
		str[i] = '#';
	}
}

void setOpenLetters(char* str, char* hide, char letter){
	for(int i = 0; str[i]!='\0'; i++){
		if(str[i]==letter){
			hide[i]=letter;
			
		}
	}
}
void showField(char* str){
	
	for(int i=0; str[i] != '\0'; i++){
		cout<<str[i];
	}
}
bool isOpenWord(char* hide){
	for(int i = 0; hide[i] != '\0'; i++){
		if(hide[i]=='#'){
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
