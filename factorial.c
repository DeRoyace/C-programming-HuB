#include<stdio.h>

void main()
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
        int fact=1;
        for(int i=1; i<=n; i++)
        {
            fact=fact*i;
        }
        printf("Factorial is %d\n", fact);
    }
} // end of main()