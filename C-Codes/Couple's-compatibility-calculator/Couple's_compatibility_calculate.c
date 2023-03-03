#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STRING 30
#define MESSAGE_ALLOC_ERROR "Error on dynamic alloc!"

void NamesDynamicAlloc(char **firstPersonName, char **secondPersonName);
void ConcatenateNames(char *firstPersonName, char *secondPersonName, char **concatentedNames);
bool AlreadyVerified(char **lettersVerified, char letter);

void main()
{
    char *firstPersonName = NULL, *secondPersonName = NULL;

    NamesDynamicAlloc(&firstPersonName, &secondPersonName);

    char *concatentedNames = NULL;

    ConcatenateNames(firstPersonName, secondPersonName, &concatentedNames);

    int count;
    bool wasVerified = false;
    int sizeConcatentedNames = strlen(concatentedNames);
    int *occorrencesLetters = (int *)malloc(sizeof(int) * sizeConcatentedNames);
    char *lettersVerified = (char *)malloc(sizeof(char) * 1);
    int sizeLettersRemaning = sizeConcatentedNames;
    
    if(occorrencesLetters == NULL || lettersVerified == NULL)
    {
        printf("%s", MESSAGE_ALLOC_ERROR);
        exit(1);
    }
    
    for(int i = 0; i < sizeLettersRemaning; i++) //eliaquimlarissa
    {
        wasVerified = AlreadyVerified(&lettersVerified, concatentedNames[i]);
        
        if(wasVerified)
        {
            sizeLettersRemaning--;
            continue;
        }
        else{
            count = 0;
            
            for(int j = i; j < sizeLettersRemaning; j++)
            {
                if(concatentedNames[j] == concatentedNames[i])
                    count++;
            }
            
            lettersVerified[i] = concatentedNames[i];
            occorrencesLetters[i] = count;
        }
    }
    
    printf("\n\nFinal - %s.\n", concatentedNames);
    
    for(int i = 0; i < strlen(concatentedNames); i++)
        printf("%d ", occorrencesLetters[i]); 
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

bool AlreadyVerified(char **lettersVerified, char letter)
{
    int sizeLettersVerified = strlen(*lettersVerified);
    
    for(int i = 0; i < sizeLettersVerified; i++)
        if(letter == (*lettersVerified)[i]) return true;

    *lettersVerified = (char *)realloc(*lettersVerified, sizeof(char) * (sizeLettersVerified + 1));
    
    return false;
}

