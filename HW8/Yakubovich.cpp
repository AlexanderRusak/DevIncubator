#include <iostream>
#include <cstdlib>

int strLength(char string[]);
void strCopy(char s1[], char s2[]);
void strCat(char s1[], char s2[]);
bool isWord(char array[]);

void fieldOfMiracle(char *str, char *hide);
void setOpenLetters(char *str, char *hide, char letter);
void setOpenLetters(char *str, char *hide, char *letter);
void showField(char *str);
bool isAlpha(char symbol);
void initHideField(char *str, int size);
bool isOpenWord(char *hide);
void showMessage(char *message);

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    char secretWord[] = "aaavtomobil";
    int size = strLength(secretWord);
    char hideLetters[] = "0";
    fieldOfMiracle(secretWord, hideLetters);
    return 0;
}

void fieldOfMiracle(char *str, char *hide)
{

    char input[128];
    char letter;
    char *word;

    initHideField(hide, strLength(str));
    showField(hide);

    cout << endl;
    while (!isOpenWord(hide))
    {

        cout << "Enter a letter or full word: ";
        cin >> input;
        if (isAlpha(input[0]) && strLength(input) == 1)
        {
            letter = input[0];
        }
        if (isWord(input) && strLength(input) > 1)
        {
            word = input;
        }

        while (!cin || !isAlpha(input[0]) || !isWord(input))
        {
            cout << "Error!" << endl;
            cout << "Input letter or full word: : ";
            cin >> input;
            if (isAlpha(input[0]) && strLength(input) == 1)
            {
                letter = input[0];
            }
            if (isWord(input) && strLength(input) > 1)
            {
                word = input;
            }
            cin.clear();
            fflush(stdin);
        }
        if (strLength(input) > 1)
        {
            setOpenLetters(str, hide, word);
        }
        else
        {
            setOpenLetters(str, hide, letter);
        }

        cout << endl;
        showField(hide);
        cout << endl;
    }
}

void initHideField(char *str, int size)
{
    for (int i = 0; i < size; i++)
    {
        str[i] = '#';
    }
}

void setOpenLetters(char *str, char *hide, char letter)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == letter)
        {
            hide[i] = letter;
        }
    }
}
void setOpenLetters(char *str, char *hide, char *letter)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == letter[i])
        {
            hide[i] = letter[i];
        }
        if (str[i] != letter[i])
        {
            cout << endl;
            showMessage("You lose");
            cout << endl;
            fieldOfMiracle(str, hide);
        }
    }
}
void showField(char *str)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << str[i];
    }
}
bool isOpenWord(char *hide)
{
    for (int i = 0; hide[i] != '\0'; i++)
    {
        if (hide[i] == '#')
        {
            return false;
        }
    }
    showMessage("И перед нами победитель капитал шоу Поле Чудес цветы и подарки в студию");
    return true;
}
bool isAlpha(char symbol)
{

    if ((symbol < 'a' || symbol > 'z') && (symbol < 'A' || symbol > 'Z'))
    {
        return false;
    }

    return true;
}

int strLength(char string[])
{
    int counter = 0;

    while (string[counter] != '\0')
        counter++;

    return counter;
}

void strCopy(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] != '0')
    {
        s2[i] = s1[i];
        i++;
    }
}

void strCat(char s1[], char s2[])
{
    int size1 = strLength(s1);
    int size2 = strLength(s2);

    for (int i = 0; i < size1 + size2; i++)
    {
        s1[size1 + i] = s2[i];
    }
}
bool isWord(char array[])
{
    for (int i = 0; i < array[i] != '\0'; i++)
    {
        if ((array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z'))
        {
            return false;
        }
    }
    return true;
}
void showMessage(char *message)
{
    cout << message;
}
