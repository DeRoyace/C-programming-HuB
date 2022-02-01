#include<stdio.h>

int sod(int x)
{
    if(x<10)
    return x;
    else
    return x%10 + sod(x/10);
}
int main()
{
    int arr[100],n,i;
    printf("\nEnter size of araay : ");
    scanf("%d",&n);
    printf("Enter array elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray elemets whose sum of digits are odd: ");
    for(i=0;i<n;i++)
    {
        if(sod(arr[i])%2!=0)
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}