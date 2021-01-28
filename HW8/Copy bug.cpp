#include <iostream>
using namespace std;
#define N 128
bool isSeparator(char c);
int strLength(char string[]);
bool isEqual(char *word, char *next);
void strCopy(char s1[], char s2[]);

int main()
{
    char text[N], word[N], prevWord[N];
    int i, iw = 0, wordCount = 0;

    cout << "Input text: ";
    cin.getline(text, N);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (!isSeparator(text[i]))
        {
            word[iw] = text[i];

            iw++;
            if (isSeparator(text[i + 1]) or text[i + 1] == '\0')
            {
                word[iw] = '\0';
                if (!isEqual(prevWord, word))
                {

                    cout << word << endl;
                }

                strCopy(word, prevWord);
                iw = 0;
            }
        }
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
int strLength(char string[])
{
    int counter = 0;

    while (string[counter] != '\0')
        counter++;

    return counter;
}
bool isEqual(char *word, char *next)
{
    if (strLength(word) != strLength(next))
    {
        return false;
    }
    else
    {
        for (int i = 0; word[i] != '\0'; i++)
        {
            if (word[i] != next[i])
            {
                return false;
            }
        }
    }
    return true;
}
void strCopy(char s1[], char s2[])
{
    for (int i = 0; s2[i] != '\0'; i++)
    {
        s2[i] = '\0';
    }
    int i = 0;
    while (s1[i] != '\0')
    {
        s2[i] = s1[i];
        i++;
    }
}
