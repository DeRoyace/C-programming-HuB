// Implementing Merge Sort in Iterative way.
#include <stdio.h>
#define SIZE 30

void display(int arr[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
} // end of display()

void mergeSort(int arr[], int N)  // sorting in ascending order
{
    int i, j, k, l1, l2, u1, u2, size;
    int temp[N]; // temporary array to keep the elements of two sorted arrays in an order.
    size = 1;    // initial size of sub-array
    while (size < N)
    {
        k = 0;
        l1 = 0; // lower index of 1st sub-array
        while (l1 + size < N)
        {
            l2 = l1 + size;   // low index of 2nd sub-array
            u1 = l2 - 1;      // upper index of 1st sub-array
            u2 = (u1 + size) < N ? (u1 + size) : N - 1;  // upper index of 2nd sub-array
            // code below: merging two sorted arrays
            for (i = l1, j = l2; i <= u1 && j <= u2; k++)
            {
                if (arr[i] < arr[j])
                    temp[k] = arr[i++];
                else
                    temp[k] = arr[j++];
            }
            while (i <= u1)
		        temp[k++] = arr[i++]; 

	        while (j <= u2)
		        temp[k++] = arr[j++];
            // end of merging sorted arrays

            l1 = u2 + 1;    // index changed for merging next sub-arrays
        }  // end of inner while loop
        for(i=l1; i<N; i++)
			temp[k++] = arr[i];  // copying the left-over array elements if the number of elements is not in power of 2.
		
		for(i=0; i<N; i++)
			arr[i] = temp[i];

        size *=2;   // incrementing the sub-array size by power of 2.
    }  // end of outer while loop

    printf("\nSorte array:  ");
    display(arr, N);
}

int main()
{
    int i, N;
    printf("\nEnter size of an array between 3 to 30: ");
    scanf("%d", &N);
    if (N >= 3 && N <= 30)
    {
        int arr[N];
        printf("\nEnter array elements:\n");
        for (i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("\nOriginal array: ");
        display(arr, N);
        mergeSort(arr, N);
    }
    else
    {
        printf("\nOut of range!\nEnter again...");
        main();
    }
} // end of main()