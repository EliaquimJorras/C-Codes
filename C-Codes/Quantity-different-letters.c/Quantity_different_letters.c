#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsAlreadyRead(char *string, char letter)
{
    for (int i = 0; string[i] != '\0'; i++)
        if (letter == string[i])
            return 1;

    return 0;
}

void InsertOnAlreadyReady(char **alreadyRead, char letter, int sizeAlreadyRead)
{
    *alreadyRead = (char *)realloc(*alreadyRead, sizeof(char) * (sizeAlreadyRead + 2));

    if (*alreadyRead == NULL)
    {
        puts("Erro no realloc\n");
        exit(1);
    }

    (*alreadyRead)[sizeAlreadyRead] = letter;
    (*alreadyRead)[sizeAlreadyRead + 1] = '\0';
}

void QuantityDifferentLetters(char *concatentedNames)
{
    int sizeAlreadyRead = 0, isAlreadyRead = 0;

    char *alreadyRead = (char *)malloc(sizeof(char) * 2);
    alreadyRead[0] = '.';
    alreadyRead[1] = '\0';

    for (int i = 0; concatentedNames[i] != '\0'; i++)
    {
        isAlreadyRead = IsAlreadyRead(alreadyRead, concatentedNames[i]);

        if (!isAlreadyRead)
        {
            InsertOnAlreadyReady(&alreadyRead, concatentedNames[i], sizeAlreadyRead);
            sizeAlreadyRead++;
        }
    }

    printf("Differents: %s -- Quantity: %d", alreadyRead, sizeAlreadyRead);
    free(alreadyRead);
}

int main()
{
    char nome1[] = "mary"; // mary  eliaquim  rodrigo  livia
    char nome2[] = "karl"; //  karl  larissa   emanuel  carla
    int tamNomes = strlen(nome1) + strlen(nome2);
    char nomes[tamNomes];

    memcpy(nomes, nome1, strlen(nome1));
    memcpy(&nomes[strlen(nome1)], nome2, strlen(nome2));

    QuantityDifferentLetters(nomes);

    return 0;
}