#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// lista de puntos, se corresponde en posicion con el abecedario INGLÉS:'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
// por lo que la 'a' vale un punto. La 'b' vale 3...
const int POINT_LIST[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int calculate_points(string word);
int obtain_position(char c);
void result(int player1_points, int player2_points);

int main(void)
{
    string player1_word = get_string("Enter player 1 word: ");
    string player2_word = get_string("Enter player 2 word: ");

    result(calculate_points(player1_word),calculate_points(player2_word));
}

int calculate_points(string word)
{
    int points = 0, letter_position;

    // recorremos los caracteres en la palabra
    for (int i = 0, j = strlen(word); i < j; i++)
    {
        letter_position = obtain_position(word[i]);
        points = points + POINT_LIST[letter_position];
    }

    return points;
}

int obtain_position(char c)
{
    // si el caracter es minuscula
    if(c >= 97 && c <= 122)
    {
        // la miga del asunto está aqui, en obtener la posicion de la letra por ejemplo 's' en el abecedario. La posicion de 's' es la 19, para obtener 19 y
        // asi hacer POINT_LIST[19] para que devuelva los puntos que vale 's' hacemos char c - 'a' porque los valores de las letras en ASCII son contiguos al alfabeto
        // por lo que 's' - 'a' es lo mismo que 115 - 97, dando 18 (contando el indice 0 pues 19)
        return c - 'a';
    }
    // si el caracter es mayus lo mismo, pero se resta 'A' que es 60.
    else if (c >= 65 && c <= 90)
    {
        return c - 'A';
    }
    // si el caracter es CUALQUIER otra letra fuera del abecedario (,.!?¡-)
    else
    {
        return -1;
    }
}

void result(int player1_points, int player2_points)
{
    if (player1_points > player2_points)
    {
        printf("Player 1 wins!\n");
    }
    else if(player1_points < player2_points)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
