#include <stdio.h>
#include<stdlib.h>
int isprime(int x)
{
    int c=0;
    for(int i=1;i<=x;i++)
    {
        if(x%i==0)
        c++;
    }
    return (c==2);
}

int main()
{
    int *arr,i,n,c=0;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    printf("\nEnter array elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", (arr+i));
    }
    for (i = 0; i < n; i++)
    {
        if(isprime(*(arr+i))==1)
        {
            printf("%d, ", *(arr+i));
            c++;
        }
    }
    printf("\nTotal no. of primes: %d\n",c);
    return 0;
}