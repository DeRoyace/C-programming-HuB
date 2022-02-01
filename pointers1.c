#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a,i,n;
    printf("\nEnter the size of the array :");
    scanf("%d",&n);

    a=(int *)malloc(sizeof(int)*n); // allocating memory for n number of integers

    printf("\nEnter the elements of the array :\n");
    for(i=0;i<n;i++)
        scanf("%d",(a+i));  // scanf("%d", &arr[i])  accepting array elemets

    for(i=0;i<n;i++)
        printf("%d, ",*(a+i));  // printf("%d", arr[i]) displaying array elements
    printf("\n");
    return 0;
}