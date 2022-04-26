#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //ensuring argument count is 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //ensuring argv array has all 26 latters of the alphabet
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        if (l != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        if (!isalpha(argv[1][i]))
        {
            printf("key must contain only alphabets");
            printf("\n");
            return 1;
        }

        // ensuring argv has no repeated letter
        for (int j = i + 1; j < l; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("key must not contain repeated letters\n");
                return 1;
            }
        }
    }

    string text = get_string("plaintext: "); //get input from user

    printf("ciphertext: "); //print ciphertext with no new line

    //substitution
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", toupper(argv[1][text[i] - 65]));
        }
        else if (islower(text[i]))
        {
            printf("%c", tolower(argv[1][text[i] - 97]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}