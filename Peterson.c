#include<stdio.h>
#include "priyach.h"

int main()
{
    int n;   
    printf("\nEnter any positive number : ");
    scanf("%d", &n);

    if (n<0)
    {
        printf("\nInvalid input! Enter the value again -->");
        main(); // calls the main() function again
    }
    else
    {
        if(isSpecial(n)==1)
        printf("%d is a Peterson Number\n", n);
        else
        printf("Not a Peterson Number\n");
    }
    return 0;
}