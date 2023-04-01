#include <stdio.h>

void PrintArray(int *array, int sizeArray)
{
    if (sizeArray == 0)
        printf("There are no values in this array.");
    else
        for (int i = 0; i < sizeArray; i++)
            (i + 1 == sizeArray) ? printf("%d.", array[i]) : printf("%d, ", array[i]);
}

int main()
{
    int sizeArray = 0;

    printf("Enter a non-zero positive number: ");
    scanf("%d", &sizeArray);

    if (sizeArray > 0)
    {
        int array[sizeArray];

        for (int i = 0; i < sizeArray; i++)
        {
            printf("Number %d: ", i + 1);
            scanf("%d", &array[i]);
        }

        int evenNumbers[sizeArray], oddNumbers[sizeArray];
        int evenQuantity = 0, oddQuantity = 0;

        for (int i = 0; i < sizeArray; i++)
        {
            if (array[i] % 2 == 0)
                evenNumbers[evenQuantity++] = array[i];
            else
                oddNumbers[oddQuantity++] = array[i];
        }

        printf("\nEven Numbers: ");
        PrintArray(evenNumbers, evenQuantity);

        printf("\nOdd Numbers: ");
        PrintArray(oddNumbers, oddQuantity);
    }
    else
        printf("I said: \"Enter a non-zero positive number\". Try again.\n\n");

    return 0;
}