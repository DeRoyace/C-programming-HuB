#include<stdio.h>

void main()
{
    // %u => unsigned int i.e. taking only positive inputs and giving +ve outputs only
    int unsigned a,b;
    printf("\nDividend = ");
    scanf("%u", &a);
    
    printf("Divisor = ");
    scanf("%u", &b);
    
    printf("Result : %u\n", a/b);
    // printf("a-b = %u",a-b);
} // end of main()