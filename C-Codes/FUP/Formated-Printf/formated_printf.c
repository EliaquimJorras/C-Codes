#include <stdio.h>
#include <stdlib.h>

#define RESET_COLOR "\033[m"
#define BOLD_GREEN "\033[1;32m"

void BaseOctaFormates()
{
    printf("**************");
    printf(" %sFormates in base 8 to integers:%s ", BOLD_GREEN, RESET_COLOR);
    printf("**************\n");

    printf(" %%o = %o\n", 77);
    printf(" %%.5o = %.5o\n\n", 77);
}

void BaseTenFormates()
{
    printf("**************");
    printf(" %sFormates in base 10 to integers:%s ", BOLD_GREEN, RESET_COLOR);
    printf("**************\n");

    printf(" %%i = %i ; %%d = %d\n", 11, 22);
    printf(" %%.5i = %.5i ; %%.5d = %.5i\n", 13, 27);
    printf(" %%i = %i ; %%+i = %+i ; %%d = %d ; %%+d = %+d\n", 6, 6, 7, 7);
    printf(" %%i = %i ; %%d = %d\n\n", -5, -8); // must add the signal '-' before the value to print negatives
}

void BaseSixteenFormates()
{
    printf("**************");
    printf(" %sFormates in base 16 to integers:%s ", BOLD_GREEN, RESET_COLOR);
    printf("**************\n");

    printf(" %%x = %x ; %%X = %X\n", 27, 27);
    printf(" %%.4x = %.4x ; %%.4X = %.4X\n", 27, 27);
    printf(" %%.4x = %.4x ; %%.4X = %.4X\n\n", -27, -27); // must add the signal '-' before the value to print negatives
    printf("      Variations: \n");
    printf(" %%10x    = |%10x|\n", 256);
    printf(" %%010x   = |%010x|\n", 256)  ;
    printf(" %%#010x  = |%#010x|\n", 256)  ; 
    printf(" %%10.8x  = |%10.8x|\n", 256)  ;
    printf(" %%#10.8x = |%#10.8x|\n\n", 256)  ; // recommended
    printf("      Same to zero: \n");
    printf(" 0x%%.8x  = |0x%.8x|\n", 256)   ;
    printf(" %%10x    = |%10x|\n", 0)      ; 
    printf(" %%010x   = |%010x|\n", 0)      ;
    printf(" %%#010x  = |%#010x|\n", 0)    ;
    printf(" %%10.8x  = |%10.8x|\n", 0)  ;
    printf(" %%#10.8x = |%#10.8x|\n", 0)  ;
    printf(" 0x%%.8x  = |0x%.8x|\n\n", 0)      ; // recommended
}

int main(void)
{
    const char* str1 = "fabulae mirabiles";

    BaseTenFormates();
    BaseSixteenFormates();
    BaseOctaFormates();

    printf("%.6s.\n", str1);
    printf("%.*s. \n", 6, str1);

    exit(EXIT_SUCCESS);
}