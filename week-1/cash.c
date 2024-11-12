#include <cs50.h>
#include <stdio.h>

void change(int money)
{
    int quarter = 25, dime = 10, nickel = 5, penny = 1, count = 0;

    // mientras el dinero no sea 0, es decir, aún queda por devolver, hacemos lo siguiente
    do
    {
        // mientras el dinero sea mayor o igual a 25 es que podemos dividirlo por 25, lo hacemos y vamos contando las monedas que hemos ido usando y le quitamos al dinero las monedas de 25 usadas
        do
        {
            if (money / quarter > 0)
            {
                count++;
                money = money - quarter;
            }
        }
        while (money >= quarter);

        do
        {
            if (money / dime > 0)
            {
                count++;
                money = money - dime;
            }
        }
        while (money >= dime);

        do
        {
            if (money / nickel > 0)
            {
                count++;
                money = money - nickel;
            }
        }
        while (money >= nickel);

        do
        {
            if (money / penny > 0)
            {
                count++;
                money = money - penny;
            }
        }
        while (money >= penny);
    }
    while (money > 0);

    printf("%i \n", count);
}

int main(void)
{

    int cash;

    do
    {
        cash = get_int("Change owed: ");
    }
    while (cash < 1);

    change(cash);
}
