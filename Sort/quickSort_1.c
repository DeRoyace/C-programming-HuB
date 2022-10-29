// Implementing Quick Sort:
#include <stdio.h>

int N;

void display(int arr[])
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
} // end of display(...)

int partition(int arr[], int l, int h)
{
    int pivot = arr[l], low = l, high = h, temp;
    while (low < high)
    {
        while (pivot >= arr[low])
            low++;
        // NOTE: the algorithm used here is not universal because...
        // ...the loop may run to infinity if the pivot is highest (i.e. worst case scenario) in the subarray;
        // e.g. inputed elements are in opposite order of the required sort order.
        // Although, C compiler can handle this situation, provided if the array size is dynamically allocated,
        // but it cannot in case: if array size is predefined in the code;
        // To avoid such situation we must provide another condition inside above while loop,
        // to keep 'low' value less than size of array. [see "quickSort_2.c"]

        while (pivot < arr[high])
            high--;
        if (low < high)
        {
            // swap(arr[low], arr[high]):
            temp = arr[high];
            arr[high] = arr[low];
            arr[low] = temp;
        }
    }
    // swap(arr[l], arr[high]):
    temp = arr[l];
    arr[l] = arr[high];
    arr[high] = temp;
    return high;
}   // end of partition(...)

void sort(int arr[], int l, int h) // function to sort array elements in ascending order
{
    int pvi;
    if (l < h)
    {
        pvi = partition(arr, l, h); // stores the pivot element index
        sort(arr, l, pvi - 1);
        sort(arr, pvi + 1, h);
    }
} // end of sort(...)

int main()
{
    // defining methods:
    void display();
    int partition(int[], int, int);
    void sort(int[], int, int);

    int i;
    printf("\nEnter size of an array between 3 to 30: ");
    scanf("%d", &N);
    int arr[N];
    if (N >= 3 && N <= 30)
    {
        printf("\nEnter array elements:\n");
        for (i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("\nArray elements are:  ");
        display(arr);
        sort(arr, 0, N - 1);
        printf("Sorted array:  ");
        display(arr);
    }
    else
    {
        printf("\nOut of range!\nEnter again...");
        main();
    }
} // end of main()