#include<stdio.h>
int main()
{
    int *arr[5], i;
    printf("\nEnter array elements :\n");
    for(i=0; i<5; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements are :  ");
    for(i=0; i<5; i++)
    {
        printf("%d, ", arr[i]);
    }

    printf("\nMemory addres of the array elemets are: ");
    for(i=0; i<5; i++)
    {
        printf("%d, ", &arr[i]);
    }
    printf("\n\n");
    return 0;
}