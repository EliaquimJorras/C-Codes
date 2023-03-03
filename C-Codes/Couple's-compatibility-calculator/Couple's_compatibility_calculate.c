#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 30
#define MESSAGE_ALLOC_ERROR "Error on dynamic alloc!"

void NamesDynamicAlloc(char **firstPersonName, char **secondPersonName);
void ConcatenateNames(char *firstPersonName, char *secondPersonName, char **concatentedNames);

int main()
{
    char *firstPersonName = NULL, *secondPersonName = NULL;

    NamesDynamicAlloc(&firstPersonName, &secondPersonName);

    char *concatentedNames = NULL;

    ConcatenateNames(firstPersonName, secondPersonName, &concatentedNames);

    printf("\n\nFinal - %s.\n", concatentedNames);

    return 0;
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
}
