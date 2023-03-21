#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Qtd_Digitos(int num, unsigned long long numPow, int *qtd_Digits)
{
    unsigned long long value = numPow;

    while (value > 0)
    {
        value /= 10;
        (*qtd_Digits) += 1;
    }
}

int Kaprekar(int num, int qtdDigits, char *str)
{
    long long int kaprekaValue = 0, kapVal_1 = 0, kapVal_2 = 0;
    int i = 0, j = 0, tam = qtdDigits / 2;
    char strPart1[tam + 1], strPart2[tam + 1];

    for (i = 0; i < tam; i++)
        strPart1[i] = str[i];
    strPart1[i] = '\0';

    for (i, j; i <= qtdDigits; i++, j++)
        strPart2[j] = str[i];

    kapVal_1 = atoi(strPart1);
    kapVal_2 = atoi(strPart2);
    kaprekaValue = kapVal_1 + kapVal_2;

    if (kaprekaValue == num) return 1;
    else                     return 0;
}

int main()
{
    int num = 0, qtdDigits = 0;
    unsigned long long numPow = 0;
    int IsKaprekarNumber = 0;
    char *str = NULL;

    while (1)
    {
        printf("Entre com um numero inteiro positivo: ");
        scanf("%d", &num);
        
        if (num >= 1) break;
    }

    numPow = (unsigned long long) num * num;
    Qtd_Digitos(num, numPow, &qtdDigits);
    str = (char *)malloc(sizeof(char) * (qtdDigits + 1));

    sprintf(str, "%llu", numPow);
    IsKaprekarNumber = Kaprekar(num, qtdDigits, str);

    if (IsKaprekarNumber)
        printf("\nO valor digitado EH um numero de Kaprekar!\n");
    else
        printf("\nO valor digitado NAO EH um numero de Kaprekar!\n");

    free(str);
    
    return 0;
}