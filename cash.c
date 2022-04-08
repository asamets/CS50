#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float money;
    int coins = 0;
    do
    {
        money = get_float("Change owed: ");
    }
    while (money < 0); 
    
    int cents = round(money * 100);
    
    while (cents >= 25)
    {
        coins = (coins + 1);
        cents = (cents - 25);
    }
    while (cents >= 10 && cents < 25)
    {
        coins = (coins + 1);
        cents = (cents - 10);
    }
    while (cents >= 5 && cents < 10)
    {
        coins = (coins + 1);
        cents = (cents - 5);
    }
    while (cents >= 1 && cents < 5)
    {
        coins = (coins + 1);
        cents = (cents - 1);
    }
    
    printf("%i\n", coins);
}