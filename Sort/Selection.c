// Implementing Selection Sort:
#include <stdio.h>
#define SIZE 50

int arr[SIZE], N;
void sort() // function to sort array elements in ascending order
{
	// code for selection sort:
	int i, j, temp;
	for(i = 0; i < N-1; i++)
	{
		for(j = i+1; j < N; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		} // end of inner for-loop
	} // end of outer for-loop
} // end of sort()

void input()
{
	int i;
	printf("\nEnter size of an array: ");
	scanf("%d", &N);
	printf("\nEnter array elements:\n");
	for(i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
} // end of input()

void display()
{
	int i;
	for(i = 0; i < N; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
} // end of display()

int main()
{
	// defining methods:
	void input();
	void display();
	void sort();

	// invoking methods:
	input();
	printf("\nArray elements are:  ");
	display();
	sort();
	printf("\nSorted array:  ");
	display();
} // end of main()
