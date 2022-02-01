#include<stdio.h>
#include<math.h> // to import math functions e.g. pow, sqrt, etc.
void main()
{
    int a,b;
    printf("\nEnter first number, a = ");
    scanf("%d",&a);printf("Enter second number, b = ");
    scanf("%d",&b);

    printf("\nYour numbers are :\n");
    printf("a = %d and ", a);
    printf("b = %d\n", b);

    if (a>b)
    {
        printf("%d is greater\n",a);
    }
    else if(b>a)
    {
        printf("%d is greater\n",b);
    }
    else
        printf("Numbers are equal.\n");

    printf("\nSummation is %d\n", a+b);
    printf("a - b = %d\n", a-b);
    printf("a x b = %d\n",a*b);

    printf("\nNow we will divide a by b, we get\n");
    printf("    Quotient = %d and ",a/b);
    printf("remainder = %d\n", a%b);

    printf("\nSquare root of a = %f\n", sqrt(a));
    printf("Square root of b = %f\n", sqrt(b));
    
} // end of main()