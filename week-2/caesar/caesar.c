#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

bool checkargc(int argc);
bool checkargv(string arg);
int convertnumber(string arg);
string promptuser();
void cipher(string text, int key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if(!checkargc(argc) || !checkargv(argv[1]))
    {
        return 1;
    }

    int key = convertnumber(argv[1]);
    string text = promptuser();

    printf("ciphertext: ");
    cipher(text, key);

    printf("\n");
    return 0;
}

void cipher(string text, int key)
{
    string cipheredtext = "";
    char c = 0;

    for(int i = 0, n = strlen(text); i < n; i++)
    {
        c = text[i];

        if(isalpha(c))
        {
            printf("%c", rotate(c, key));
        }
        else
        {
            printf("%c", c);
        }
    }
}

char rotate(char c, int key)
{
    char rotatedchar = 0;

    if(islower(c))
    {
        // supongamos que c es y, y key es 2.
        // 97 + (121 - 97 + 2) % 26 | 97 + (26 % 26) | 97 + 0 = 97('a')

        // supongamos que c es r, y key es 23.
        // 97 + (114 - 97 + 23) % 26 | 97 + (40 % 26) | 97 + 14 = 111('o')
        rotatedchar = 'a' + (c - 'a' + key) % 26;
    }
    else if(isupper(c))
    {
        rotatedchar = 'A' + (c - 'A' + key) % 26;
    }

    return rotatedchar;
}

string promptuser()
{
    int length = 0;
    string text = "";

    do
    {
        text = get_string("plaintext:  ");
        length = strlen(text);
    }
    while(length < 1 || isspace(text[length - 1]) || isspace(text[0]));

    return text;
}

bool checkargc(int argc)
{
    if(argc == 0 || argc == 1 || argc > 2)
    {
        printf("Error, wrong number of arguments passed. Terminating program...\n");
        return false;
    }

    return true;
}

bool checkargv(string arg)
{
    bool isnumber = false;

    for(int i = 0, n = strlen(arg); i < n; i++)
    {
        if(!isdigit(arg[i]))
        {
            isnumber = false;
        }
        else
        {
            isnumber = true;
        }
    }

    if(!isnumber)
    {
        printf("Usage: ./caesar key\n");
    }

    return isnumber;
}

int convertnumber(string arg)
{
    int n = atoi(arg);
    if(n < 0)
    {
        return n * -1;
    }
    else
    {
        return n;
    }
}
