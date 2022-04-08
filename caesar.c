#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

string change_key(string plaintext, int key)
{
    string cyphertext = plaintext;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = tolower(plaintext[i]);
        if (c >= 'a' && c <= 'z')
        {
            c -= 'a';
            c += key;
            c %= 26;
            c += 'a';
            if (plaintext[i] != tolower(plaintext[i]))
            {
                c = toupper(c);
            }
        }
        cyphertext[i] = c;
    }
    return cyphertext;
}

int main(int argc, string argv[])
{
    int k = 0;
    if (argc == 2)
    {
        k = atoi(argv[argc - 1]);
        for (int i = 0; i < strlen(argv[argc - 1]); i++)
        {
            char c = argv[argc - 1][i];
            if (!(c >= '0' && c <= '9'))
            {
                printf("Usage: ./caesar key \n");
                return 1;
            }
        }
        if (k == 0)
        {
            if (strcmp(argv[argc - 1], "0") != 0)
            {
                printf("Usage: ./caesar key \n");
                return 1;
            }
        }
        if (k < 0)
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    string cyphertext = change_key(plaintext, k);
    printf("ciphertext: %s\n", cyphertext);
    return 0;
}