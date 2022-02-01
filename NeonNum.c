#include<stdio.h>

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
        if(n== sumofdigits(n*n))
        printf("%d is a Neon Number\n", n);
        else
        printf("%d Not a Neon Number.\n", n);
    }
    return 0;
} // end of main()