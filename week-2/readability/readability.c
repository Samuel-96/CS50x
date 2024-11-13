#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*
    In a file called readability.c in a folder called readability, you’ll implement a program that calculates the approximate grade level needed to comprehend some text.
    Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer.
    If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+”
    instead of giving the exact index number. If the grade level is less than 1, your program should output “Before Grade 1”.
*/

string promptuser();
int countletters(string text);
int countwords(string text);
int countsentences(string text);
float  computegrade(int contsentences, int contwords, int contletters);
void show_grade(int grade);

int main(void)
{
    int letters = 0, words = 0, sentences = 0, grade = 0;
    string text = promptuser();

    sentences = countsentences(text);
    words = countwords(text);
    letters = countletters(text);

    grade = computegrade(sentences, words, letters);
    //printf("S: %i W: %i L: %i ", sentences, words, letters);
    show_grade(grade);
}

string promptuser()
{
    int length = 0;
    string text = "";

    do
    {
        text = get_string("Text: ");
        length = strlen(text);
    }
    while(length < 1 || isspace(text[length - 1]) || isspace(text[0])); // pedimos al usuario que introduzca el texto hasta que este no empiece por espacio, tenga al menos un caracter y no termine en espacio

    return text;
}

int countletters(string text)
{
    int contletters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if(isalpha(text[i]))
        {
            contletters++;
        }
    }

    return contletters;
}

int countwords(string text)
{
    int contwords = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if(isspace(text[i]))
        {
            contwords++;
        }
    }

    return contwords;
}

int countsentences(string text)
{
    int contsentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            contsentences++;
        }
    }

    return contsentences;
}

float computegrade(int contsentences, int contwords, int contletters)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    // L is the average number of letters per 100 words in the text
    // S is the average number of sentences per 100 words in the text.

    float l = ((float)contletters / contwords) * 100;
    float s = ((float)contsentences / contwords) * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    return round(index);
}

void show_grade(int grade)
{
    if(grade < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
