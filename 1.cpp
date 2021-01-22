#include <iostream>
#include <cstdlib>

#define N 10

int strLength(char string[]);
void strCopy(char s1[] , char s2[]);
char* strCat(char* s1, char* s2);
using namespace std;


int main()
{
    char str1[]="12345";
    char str2[]="6789";
    //strCopy(str1, str2);
    strCat(str1, str2);
    cout << str1;
    return 0;
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

char *strCat(char *s1, char *s2){
    while (*s1){
        s1++;
    }
    
    while(*s2){
        *s1 = *s2;
        s1++;
        s2++;
    }
    
    *s1 = '\0';
    
    return s1;
}
