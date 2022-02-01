#include <stdio.h>

int isprime(int n)
{
    int f=0;
    for (int j = 1; j <= n; j++)
    {
        if (n % j == 0)
            f++;
    }
    if (f == 2)
    return 1;
    else
    return 0;
}

void main()
{
    int M, N;
    printf("\nEnter the lower limit : ");
    scanf("%d", &M);

    printf("Enter the upper limit : ");
    scanf("%d", &N);

    if (M > N || M == N || M < 1 || M >= 1000 || N < 1 || N >= 1000)
    {
        printf("\nInvalid input. Enter the inputs again -->");
        main();
    }
    else
    {
        printf("The prime numbers are : ");
        for (int i = M; i <= N; i++)
        {
            if(isprime(i))
            printf("%d, ", i);
        }
    }
}