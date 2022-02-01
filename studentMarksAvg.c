#include<stdio.h>
int main()
{
    int arr[10],n,i,sum=0;
    printf("\nEnter number of subjects: ");
    scanf("%d", &n);

    printf("\nEnter marks for : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        sum+=arr[i];
    }
    printf("\nTotal Marks = %d", sum);
    printf("\nAverage Marks = %.2f\n", sum/(float)n);
    return 0;
}