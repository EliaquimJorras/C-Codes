#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING 30
#define MESSAGE_ALLOC_ERROR "Error on dynamic alloc!"
#define MESSAGE_REALLOC_ERROR "Error to realloc memory!"

void NamesDynamicAlloc(char **firstPersonName, char **secondPersonName);
void ConcatenateNames(char *firstPersonName, char *secondPersonName, char **concatentedNames);
char *DifferentLetters(char *concatentedNames, int sizeConcatentedNames);
int *CountRepetitionEachLetter(char *differentLetters, char *concatentedNames, int sizeDifferenteLetters, int sizeConcatentedNames);

void main()
{
    char *firstPersonName = NULL, *secondPersonName = NULL;

    NamesDynamicAlloc(&firstPersonName, &secondPersonName);

    int sizeDifferenteLetters = 0, sizeConcatentedNames = 0;
    char *concatentedNames = NULL, *differentLetters = NULL;

    ConcatenateNames(firstPersonName, secondPersonName, &concatentedNames);
    sizeConcatentedNames = strlen(concatentedNames);

    differentLetters = DifferentLetters(concatentedNames, sizeConcatentedNames);
    sizeDifferenteLetters = strlen(differentLetters);

    int *numberRepeats = CountRepetitionEachLetter(differentLetters, concatentedNames, sizeDifferenteLetters, sizeConcatentedNames);
    

    for(int i = 0; i < sizeDifferenteLetters; i++)
    {
        if(sizeDifferenteLetters % 2 == 0)
        {
            if(i < sizeDifferenteLetters/ 2)
                numberRepeats[i] += numberRepeats[sizeDifferenteLetters - (i + 1)];
                
            else numberRepeats[i] = 0;

        }else if(sizeDifferenteLetters % 2 == 1)
        {
            if( i < sizeDifferenteLetters/ 2)
                numberRepeats[i] += numberRepeats[sizeDifferenteLetters - (i + 1)];
                
            if(i >= sizeDifferenteLetters/ 2 + 1)
                numberRepeats[i] = 0;
        }
    }
    
    puts("\n\n\n");
    for(int i = 0; i < sizeDifferenteLetters; i++)
        printf("%d ", numberRepeats[i]);
    puts("\n\n\n");
    
    printf("\n\nStrOrig(%s.) - SizeDifferenteLetters(%d).\n", concatentedNames, sizeDifferenteLetters);
}

void NamesDynamicAlloc(char **firstPersonName, char **secondPersonName)
{
    *firstPersonName = (char *)malloc(sizeof(char) * MAX_STRING);
    *secondPersonName = (char *)malloc(sizeof(char) * MAX_STRING);

    if (*firstPersonName == NULL || *secondPersonName == NULL)
    {
        printf("%s\n", MESSAGE_ALLOC_ERROR);
        exit(1);
    }

    printf("Enter the first person name: ");
    fgets(*firstPersonName, MAX_STRING - 1, stdin);

    printf("Enter the second person name: ");
    fgets(*secondPersonName, MAX_STRING - 1, stdin);

    int sizeHelper_1 = strlen(*firstPersonName);
    int sizeHelper_2 = strlen(*secondPersonName);

    *firstPersonName = (char *)realloc(*firstPersonName, sizeof(char) * sizeHelper_1);
    *secondPersonName = (char *)realloc(*secondPersonName, sizeof(char) * sizeHelper_2);

    if (*firstPersonName == NULL || *secondPersonName == NULL)
    {
        printf("%s\n", MESSAGE_REALLOC_ERROR);
        exit(1);
    }
    
    (*firstPersonName)[sizeHelper_1 - 1] = '\0';
    (*secondPersonName)[sizeHelper_2 - 1] = '\0';
}

void ConcatenateNames(char *firstPersonName, char *secondPersonName, char **concatentedNames)
{
    int sizeFirstPersonName = strlen(firstPersonName);
    int sizeSecondPersonName = strlen(secondPersonName);
    int sizeConcatentedNames = sizeFirstPersonName + sizeSecondPersonName;

    *concatentedNames = (char *)malloc(sizeof(char) * sizeConcatentedNames);

    if (*concatentedNames == NULL)
    {
        printf("%s", MESSAGE_ALLOC_ERROR);
        exit(1);
    }

    memcpy(*concatentedNames, firstPersonName, sizeFirstPersonName);
    memcpy(&(*concatentedNames)[sizeFirstPersonName], secondPersonName, sizeSecondPersonName);

    for (int i = 0; (*concatentedNames)[i] != '\0'; i++)
        (*concatentedNames)[i] = tolower((*concatentedNames)[i]);
}

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

char *DifferentLetters(char *concatentedNames, int sizeConcatentedNames)
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
    
    return alreadyRead;
}

int *CountRepetitionEachLetter(char *differentLetters, char *concatentedNames, int sizeDifferenteLetters, int sizeConcatentedNames)
{
    int countRepetitions = 0;
    int *numberRepeats = (int *)malloc(sizeof(int) * sizeDifferenteLetters);
    
    for(int i = 0; i < sizeDifferenteLetters; i++)
    {
        for(int j = 0; j < sizeConcatentedNames; j++)
            if(differentLetters[i] == concatentedNames[j])
                countRepetitions++;
                
        numberRepeats[i] = countRepetitions;
        countRepetitions = 0;
    }
    
    return numberRepeats;
}


















