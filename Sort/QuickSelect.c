#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

int arr[SIZE], N, k;

void input()
{
    int i;
    printf("\nEnter the size of array (<=%d): ", SIZE);
    scanf("%d", &N);
    printf("\nEnter array elements (integers):\n");
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);
check_k:
    printf("\nEnter the position of k-th smallest element: ");
    scanf("%d", &k);
    if(k>N)
    {
        printf("\nInvalid input");
        goto check_k;
    }
}

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[], int low, int high) // Hoare Partition
{
    int pivot_index = low;
    int pivot_element = a[pivot_index];
    int l = low, h = high, temp;
    while (l < h)
    {
        while (pivot_element >= a[l] && l <= N - 1)
            l++;

        while (pivot_element < a[h])
            h--;

        if (l < h)
            swap(a, l, h);
    }
    swap(a, pivot_index, h);
    return h;
}

void quickSelect(int a[], int low, int high) // finding the k-th smallest element
{
    int pivot_index = partition(a, low, high);
    if (pivot_index == k-1)
        printf("\nk-th smallest element is %d.\n", a[pivot_index]);
    else if (pivot_index < k-1)
        quickSelect(a, pivot_index+1, high);
    else
        quickSelect(a, low, pivot_index-1);
}

int main()
{
    input();
    quickSelect(arr, 0, N-1);
    return 0;
}