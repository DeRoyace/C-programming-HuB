#include <stdio.h>
#define SIZE 30

int arr[SIZE], N;

void bubbleSort()
{
	int flag = 1, i, j, temp;
	for(i = 0; i < N - 1 && flag; i++)
	{
		flag = 0;
		for(j = 0; j < N - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
		} // end of inner for-loop
	} // end of outer for-loop
} // end of bubbleSort()

void input()
{
	int i;
	printf("\nEnter size of array (upto 30): ");
	scanf("%d", &N);
	printf("\nEnter array elements:\n");
	for(i = 0; i < N; i++)
	{
		scanf("\n%d", &arr[i]);
	}
}

void display()
{
	int i;
	for(i = 0; i < N; i++)
		printf("%d  ", arr[i]);
	printf("\n");
}

int main()
{
	void bubbleSort();
	void input();
	void display();

	input();
	printf("\nArray elements are:  ");
	display();
	bubbleSort();
	printf("\nSorted array:  ");
	display();
	return 0;
}
