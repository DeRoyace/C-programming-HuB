#include <stdio.h>
#include<stdlib.h>
int isprime(int x)
{
    int f = 0;
    for (int j = 1; j <= x; j++)
    {
        if (x % j == 0)
            f++;
    }
    return (f == 2);
}

int main()
{
    int i, *arr, n, count=0;
    printf("\nEnter size of matrix: ");
    scanf("%d", &n);
    arr = (int *)calloc( sizeof(int), n);
    printf("\nEnter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
        if (isprime(*(arr + i)) == 1)
            count++;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\nNo. of primes = %d\n", count);
    return 0;
}