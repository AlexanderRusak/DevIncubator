#include <iostream>
using namespace std;
#define N 128
bool isSeparator(char c);

int main()
{
    char text[N], word[N], maxWord[N];
    int i, iw = 0, wordAmmount=0, wordLength=0, maxLength=0, startIndex=0;

    cout << "Input text: ";
    cin.getline(text, N);

    for (i = 0; text[i] != '\0'; i++) {
        if (!isSeparator(text[i])) {
            word[iw] = text[i];
            iw++;

            
            if (isSeparator(text[i+1]) or text[i+1] == '\0') {
            	wordLength=iw;
            	if(maxLength < wordLength){
            		maxLength = wordLength;  
					startIndex=i+1-maxLength;        		
            	}
                word[iw] = '\0';
                cout << word << endl;
                iw = 0;
                wordAmmount++;
                wordLength=0;
            }
        }
    }
    cout<<wordAmmount<<endl;
    
    for(int i = startIndex; i < maxLength+startIndex; i++){
    	cout << text[i];
    }
    return 0;
}

bool isSeparator(char c)
{
    char s[] = ",.! ?";
    for (int i = 0; s[i] != '\0'; i++) 
        if (c == s[i])
            return true;
    return false;
}


