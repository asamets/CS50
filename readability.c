#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_words(string text)
{
    int n = strlen(text);
    int words = 1;
    for (int i = 0; i < n; i++)
    {
        char c = tolower(text[i]);
        if (c == ' ' && c != '\'')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int n = strlen(text);
    int sentences = 0;
    for (int i = 0; i < n; i++)
    {
        char c = tolower(text[i]);
        char c0 = text[i + 1];
        if (c == '.' || c == '?' || c == '!')
        {
            while (text[i] == '.' || text[i] == '?' || text[i] == '!')
            {
                i++;
            }
            if (text[i + 1] != '.' && text[i + 1] != '?' && text[i + 1] != '!')
            {
                sentences++;
            }
            else if (i == n)
            {
                sentences++;
            }
        }
    }
    return sentences;
}

int count_letters(string text)
{
    int n = strlen(text);
    int letters = 0;
    for (int i = 0; i < n; i++)
    {
        char c = tolower(text[i]);
        if (c >= 'a' && c <= 'z')
        {
            letters++;
        }
    }
    return letters;
}

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int L = 0;
    int S  = 0;
    L = ((float)letters / words) * 100;
    S = ((float)sentences / words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}