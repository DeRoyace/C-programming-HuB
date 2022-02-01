#include<stdio.h>

int main()
{
    int arr[10],brr[10],i;
    printf("\nEnter array elements: \n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nReversed Array elemets: \n");
    for(i=0;i<10;i++)
    {
        brr[i]=arr[9-i];
        printf("%d, ", brr[i]);
    }
    printf("\n");
    return 0;
}