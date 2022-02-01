/* Write a program to accept any 2 arrays and merge them in such a way as explained below:
List 1: 1,3,5,7,9
List 2: 2,4,6,8,10,12,14,16
Merged List : 1,2,3,4,5,6,7,8,9,10,12,14,16 */
#include <stdio.h>

int arr[100],brr[100],crr[100], s1, s2, i, j;

void accept(int size, int a[])
{
    printf("Enter array elements : \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display(int size, int a[])
{
    for(i=0;i< size; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

void sort(int size, int a[])
{
    int temp=0;
    for(i=0;i< size;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    printf("\nEnter size of array 1 : ");
    scanf("%d", &s1);
    accept(s1, arr);

    printf("\nEnter size of array 2 : ");
    scanf("%d", &s2);
    accept(s2, brr);

    j=0;
    for(i=0; i < s1+s2; i++)
    {
        if(i < s1)
        crr[i]=arr[i];
        else
        crr[i]=brr[j++];
    }
    printf("\nArray 1: ");
    display(s1,arr);
    printf("\nArray 2: ");
    display(s2,brr);

    sort(s1+s2, crr);
    printf("\nMerged and Sorted array : ");
    display(s1+s2, crr);

    return 0;
}