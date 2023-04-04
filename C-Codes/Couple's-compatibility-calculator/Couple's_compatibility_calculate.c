#include <string.h>
#include "utility.h"

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
    
    CalculateCompatibility(numberRepeats, sizeDifferenteLetters);
    
    ReturnAnswerCompatibility(numberRepeats, sizeDifferenteLetters, firstPersonName, secondPersonName);
}