#include <stdio.h>

int factorial(int x) // function to return factorial of the number
{
    int f = 1;
    for (int i = 1; i <= x; i++)
    {
        f = f * i;
    }
    return f;
}

void main()
{
    int n,sum,x;
    printf("\nEnter any positive number : ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("\nInvalid input! Enter the value again -->");
        main(); // calls the main() function again
    }
    else
    {
        x=n;
        sum = 0;
        while (x > 0)
        {
            sum += factorial(x % 10);
            x = x / 10;
        }

        if(sum == n)
            printf("%d is a Special Number\n",n);
        else
            printf("%d Not a special number\n",n);
    }
} // end of main()