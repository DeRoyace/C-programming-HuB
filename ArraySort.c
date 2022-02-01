//Write a program to accept any n integers in an array and arrange the first n/2 elements in descending order and the remaining elements in ascending order.
#include <stdio.h>

int main()
{
    int arr[100],n,i,j,temp;
    printf("\nEnter size of araay : ");
    scanf("%d",&n);
    printf("Enter array elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<(n/2)-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    temp=0;
    for(i=n/2;i<n;i++)
    {
        for(j=n/2;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\nRearranged array : ");
    for(i=0;i<n;i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}