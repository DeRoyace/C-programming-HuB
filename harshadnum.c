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

void main()
{
    int n, sod;
    printf("\nEnter any positive number : ");
    scanf("%d", &n);

    if (n<0)
    {
        printf("\nInvalid input! Enter the value again -->");
        main(); // calls the main() function again
    }
    else
    {
        sod=sumofdigits(n);
        if(n%sod == 0)
            printf("%d is a Harshad Number\n",n);
        else
            printf("%d Not a harshad number\n",n);
    }
} // end of main()