#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>

using namespace std;

void setNormalizeText(char *text);
bool isCapitalLetter(char letter);
void showString(char *str);
void splitString(char *string, int startWordPosition, int count);
bool isMatchString(char *str1, char *str2);
void getResult(char *fragment, char *text, int matchCount, double& unique);
void strCopy(char s1[], char s2[]);
int strLength(char string[]);
double getUniquePercent(double match,double iterations);

int main()
{
	double percent=0;
    char str[] = "The Java Tutorials are practical guides for programmers who want to use the Java programming language to create applications. They include hundreds of complete, working examples, and dozens of lessons. Groups of related lessons are organized into trails.";
    char fragment[] = "The Java programming language are practical guides for programmers. The Java Tutorials are organized into trails. Create applications include hundreds of complete. Groups of dozens of lessons.";
    getResult(fragment, str, 6, percent);
    cout<<"Text has unique "<<percent<<" percent"<<endl;

    return 0;
}

void setNormalizeText(char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] > 96 && text[i] < 123) || (text[i] >= 65 && text[i] <= 90))
        {
            if (text[i] < 97 || text[i] > 123)
            {

                if (isCapitalLetter(text[i]))
                {
                    count++;

                    text[i] += 32;
                }
            }
        }
        else
        {
            text[i] = ' ';
        }
    }
}
bool isCapitalLetter(char letter)
{
    if (letter >= 65 && letter <= 90)
    {
        return true;
    }
    return false;
}
void showString(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << str[i];
    }
    cout << endl;
}

void getResult(char *fragment, char *text, int matchCount, double& unique)
{
    double result = 0;
    double iterationCount = 0;
    setNormalizeText(text);
    setNormalizeText(fragment);
    
    char copyFragment         [256];
    char copyFragmentIteration[256];
    char copyText			  [256];
    char copyTextIteration    [256];

    strCopy(fragment, copyFragment);
    strCopy(fragment, copyFragmentIteration);
    strCopy(text, copyText);
    strCopy(text, copyTextIteration);

    int i=0;
	int j=0;
	
    splitString(copyTextIteration,0,1);
    
    while(strLength(copyTextIteration)>0)
    {
    	iterationCount++;
    	splitString(copyText, i, matchCount);
  	    strCopy(fragment, copyFragmentIteration);
        splitString(copyFragmentIteration,0,1);
    	while(strLength(copyFragmentIteration)>0){
    		
    		splitString(copyFragment, j, matchCount);
			if (isMatchString(copyText, copyFragment))
        	{
        		iterationCount++;
            	result++;
        	}
        	strCopy(fragment, copyFragment);
        	strCopy(fragment, copyFragmentIteration);
        	j++;
        	splitString(copyFragmentIteration,j,1);
        	
    	}
        
       
        strCopy(text, copyText);
        strCopy(text, copyTextIteration);
        i++;
        j=0;
        splitString(copyTextIteration,i,1);
    }
    unique=getUniquePercent(result,iterationCount);
}

void splitString(char *string, int startWordPosition, int count)
{
    char buf[256];
    int length = 0;
    int words = 0;
    bool flag = false;
    int i = 0, j = 0;
    count += startWordPosition;
    while (string[i] != '\0')
    {
        if (startWordPosition >= count)
        {
            break;
        }
        while (string[i] == ' ')
        {
            if (!flag)
            {
                words++;
            }
            flag = true;
            i++;
        }
        flag = false;
        if (count == words)
        {
            break;
        }
        if (startWordPosition <= words)
        {

            buf[j] = string[i];
            length++;
            j++;
        }

        i++;
    }
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (i < length)
        {
            string[i] = buf[i];
        }
        else
        {
            string[i] = '\0';
        }
    }
}
bool isMatchString(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

void strCopy(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] != '\0')
    {
        s2[i] = s1[i];
        i++;
    }
}
int strLength(char string[])
{
    int counter = 0;

    while (string[counter] != '\0')
        counter++;

    return counter;
}
double getUniquePercent(double match,double iterations){
	double result;
	if(!match){
		return 100;
	}
	result=(iterations-match)/iterations*100;
	return result;
}


