#ifndef UTILITY_H
#define UTILITY_H

void NamesDynamicAlloc(char **firstPersonName, char **secondPersonName);

void ConcatenateNames(char *firstPersonName, char *secondPersonName, char **concatentedNames);

char *DifferentLetters(char *concatentedNames, int sizeConcatentedNames);

int *CountRepetitionEachLetter(char *differentLetters, char *concatentedNames, int sizeDifferenteLetters, int sizeConcatentedNames);

int PrintArray(int *array, int sizeArray);

void CalculateCompatibility(int *array, int sizeArray);

void ReturnAnswerCompatibility(int *array, int sizeArray, char *firstPersonName, char *secondPersonName);

#endif /* UTILITY_H */