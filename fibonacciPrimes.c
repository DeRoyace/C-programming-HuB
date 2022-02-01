// List all the numbers within a given range which are parts of the fibonacci series and a prime.
#include <stdio.h>
int m, n;

int isprime(int x)
{
    int c = 0;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
            c++;
    }
    return (c == 2);
}

void fiboPrime()
{
    printf("\nPrime fibonacci numbers are :\n");
    int i, a = 0, b = 1, c = a + b;
    for (i = 0; i <= n; i++)
    {
        a=b;
        b=c;
        c=a+b;
        if(c>=m && c<=n && isprime(c)==1)
        {
            printf("%d, ", c);
        }
    }
    printf("\n");
}

int main()
{
    printf("\nEnter lower limit : ");
    scanf("%d", &m);
    printf("Enter upper limit : ");
    scanf("%d", &n);
    fiboPrime();
    return 0;
}