#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsAlreadyRead(char *string, char letter, int sizeAlreadyRead)
{
    for (int i = 0; i < sizeAlreadyRead; i++)
    {
        if (string[i] < 97 || string[i] > 122) return 1;
        if (letter == string[i]) return 1;
    }

    return 0;
}

void InsertOnAlreadyReady(char **alreadyRead, char letter, int sizeAlreadyRead)
{
    *alreadyRead = (char *)realloc(*alreadyRead, sizeof(char) * (sizeAlreadyRead + 2));

    if (*alreadyRead == NULL)
    {
        puts("Error to realloc memory!");
        exit(1);
    }

    (*alreadyRead)[sizeAlreadyRead] = letter;
    (*alreadyRead)[sizeAlreadyRead + 1] = '\0';
}

int QuantityDifferentLetters(char *concatentedNames, int sizeConcatentedNames)
{
    int sizeAlreadyRead = 0, isAlreadyRead = 0;
    char *alreadyRead = (char *)malloc(sizeof(char) * 2);

    for (int i = 0; i < sizeConcatentedNames; i++)
    {
        isAlreadyRead = IsAlreadyRead(alreadyRead, concatentedNames[i], sizeAlreadyRead);

        if (!isAlreadyRead)
        {
            InsertOnAlreadyReady(&alreadyRead, concatentedNames[i], sizeAlreadyRead);
            sizeAlreadyRead++;
        }
    }

    free(alreadyRead);

    return sizeAlreadyRead;
}

int main()
{
    int sizeDifferentLetters = 0;
    char string1[] = "mary"; // mary eliaquim rodrigo livia
    char string2[] = "karl";  // karl larissa emanuel carla

    int sizeStrings = strlen(string1) + strlen(string2);
    char stringsConcatented[sizeStrings];

    memcpy(stringsConcatented, string1, strlen(string1));
    memcpy(&stringsConcatented[strlen(string1)], string2, strlen(string2));

    sizeDifferentLetters = QuantityDifferentLetters(stringsConcatented, sizeStrings);

    printf("Putting the strings together, there are %d different letters", sizeDifferentLetters);

    return 0;
}