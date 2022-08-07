// Implementing Insertion Sort:
#include <stdio.h>
#define SIZE 30

int arr[SIZE], N;
void sort() // function to sort array elements in ascending order
{
	// code for insertion sort:
	int i, j, temp;
	for(i = 1; i < N; i++)
	{
		temp = arr[i];
		for(j = i-1; j >= 0 && temp < arr[j]; j--)
		{
			arr[j+1] = arr[j];
		} // end of inner for-loop
		arr[j+1] = temp;
	} // end of outer for-loop
} // end of sort()

void input()
{
	int i;
	printf("\nEnter size of an array between 5 to 30: ");
	scanf("%d", &N);
	if(N >=3 && N <= 30)
	{
	printf("\nEnter array elements:\n");
	for(i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	}
	else
	{
		printf("\nOut of range!\nEnter again...");
		input();
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
	printf("Sorted array:  ");
	display();
} // end of main()
