// Implementing Quick Sort
#include <stdio.h>
#define SIZE 30

int arr[SIZE], N;

void input()
{
	int i;
	printf("\nEnter size of an array between 3 to 30: ");
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

int partition(int l, int h)
{
	int pivot = arr[l], low = l, high = h, temp;
	while(low < high)
	{
		while(pivot >= arr[low] && low < N-1)
			low++;

		while(pivot < arr[high])
			high--;
		if(low < high)
		{
			//swap(arr[low], arr[high]);
			temp = arr[high];
			arr[high] = arr[low];
			arr[low] = temp;
		}
	}
	//swap(arr[l], arr[high]);
	temp = arr[l];
	arr[l] = arr[high];
	arr[high] = temp;
	return high;
}

void sort(int l, int h) // function to sort array elements in ascending order
{
	int pvi;
	if(l<h)
	{
		pvi = partition(l, h); // stores the pivot element index
		sort(l,pvi-1);
		sort(pvi+1, h);
	}
} // end of sort()

int main()
{
	// defining methods:
	void input();
	void display();
	void sort(int, int);
	int partition(int, int);

	// invoking methods:
	input();
	printf("\nArray elements are:  ");
	display();
	sort(0, N-1);
	printf("Sorted array:  ");
	display();
} // end of main()