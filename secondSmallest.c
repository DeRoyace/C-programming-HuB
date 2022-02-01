#include <stdio.h>

int arr[100][100], n, i, j;

void accept()
{
    printf("\nEnter size of matrix: ");
    scanf("%d", &n);
    printf("\nEnter array elements: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

int find2ndSmall()
{
    int sm1 = arr[0][0], sm2 = arr[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (sm1 > arr[i][j])
            {
                sm2 = sm1;
                sm1 = arr[i][j];
            }
        }
    }
    printf("\n Smallest : %d\n", sm1);
    return sm2;
}

void display()
{
    printf("\nThe MATRIX is :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    accept();
    display();
    printf("\nSecond smallest number in the array is %d\n", find2ndSmall());
    return 0;
}