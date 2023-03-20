#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

char *Strip(char *str)
{
    int j = 0, helpSpace = 0;
    char *help = (char *)malloc(sizeof(char) * (strlen(str) + 1));

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (helpSpace == 0 && str[i] != ' ') helpSpace = 1;

        if (helpSpace == 0 && str[i] == ' ')   continue;
        if (str[i] == ' ' && str[i + 1] == ' ')  continue;
        if (str[i] == ' ' && str[i + 1] == '\0') continue;

        help[j] = str[i];
        j++;
    }

    help[j] = '\0';

    return help;
}

char **Split(char *str, char **list)
{
    static int help = -1;
    int qtd = 0, j = 0, k = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ') qtd++;

    list = (char **)malloc(sizeof(char *) * (qtd + 1));

    if (list == NULL)
    {
        printf("Error in the allocation of the list in the split function!\n");
        exit(0);
    }

    for (int i = 0; i < (qtd + 1); i++)
    {
        char *subList = (char *)malloc(sizeof(char) * (strlen(str) + 1));

        help++;

        if (help > 0) k = 0;

        for (j = j; str[j] != '\0'; j++)
        {
            if (str[j] == ' ') break;

            subList[k] = str[j];
            k++;
        }

        j++;
        list[i] = subList;
        list[i][k] = '\0';
    }

    return list;
}

char *ToUppercase(char *str)
{
    int i = 0;
    char *strHelp = (char*)malloc(sizeof(char) * (strlen(str) + 1));

    while ((strHelp[i] = str[i])) i++;

    for (int i = 0; strHelp[i] != '\0'; i++)
        if (strHelp[i] >= 'a' && strHelp[i] <= 'z')
            strHelp[i] = strHelp[i] - 'a' + 'A';

    return strHelp;
}

char *ToLowercase(char *str)
{
    int i = 0;
    char *strHelp = (char*)malloc(sizeof(char) * (strlen(str) + 1));

    while ((strHelp[i] = str[i])) i++;

    for (int i = 0; strHelp[i] != '\0'; i++)
        if (strHelp[i] >= 'A' && strHelp[i] <= 'Z')
            strHelp[i] = strHelp[i] - 'A' + 'a';

    return strHelp;
}

int LengthWithoutSpaces(char *str)
{
    int length = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ')  length++;

    return length;
}

int main()
{
    char *phrase = (char *)malloc(sizeof(char) * MAX);
    char **list = NULL;

    printf("Enter your full name: ");
    scanf("%50[^\n]s", phrase);

    phrase = Strip(phrase);     // remove the white spaces
    list = Split(phrase, list); // split the string into substrings and store in a string array

    printf("\n\033[1;35mProcessing...\033[m\n\n");
    printf("Name in uppercase letters   : %s\n", ToUppercase(phrase));
    printf("Name in lowercase letters   : %s\n", ToLowercase(phrase));
    printf("Name size without whitespace: %d\n", LengthWithoutSpaces(phrase));
    printf("First name length without whitespace: %d\n\n", LengthWithoutSpaces(list[0]));

    return 0;
}