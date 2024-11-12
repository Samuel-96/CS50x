#include <cs50.h>
#include <stdio.h>

void print_row(int height, int i)
{
    for (int j = 1; j <= (height - i); j++)
    {
        printf(" ");
    }

    for (int j = 1; j <= i; j++)
    {
        printf("#");
    }

    printf("\n");
}

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    for (int i = 1; i <= n; i++)
    {
        print_row(n, i);
    }
}
