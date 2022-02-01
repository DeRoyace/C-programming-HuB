#include<stdio.h>

int digits(int x) // function to count total no. of digits
{
    int c=0;
    while (x>0)
    {
        x=x/10;
        c++;
    }
    return c;
}

int sumofdigits(int x) // function to compute sum of digits
{
    int sum=0;
    while(x>0)
    {
        sum+=x%10;
        x=x/10;
    }
    return sum;
}

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
        printf("Total digits : %d\n", digits(n));

        printf("Sum of digits = %d\n", sumofdigits(n));
        

    }
} // end of main()