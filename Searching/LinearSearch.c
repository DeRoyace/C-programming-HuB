// Implemeting Linear Search:
#include <stdio.h>
#define SIZE 30

int N, arr[SIZE];
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
	printf("\nArray elements are: ");
	for(i = 0; i < N; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
} // end of display()

int linearSearch(int i, int val) // recursive function to search element using Linear Search method.
{
	if(arr[i] == val)
		return i;
	else if(i == N-1)
		return -1;
	else
		return linearSearch(i+1, val);
} // end of linearSearch()

int main()
{
	int search;
	input();
	display();
	printf("\nEnter element to be search: ");
	scanf("%d", &search);
	int pos = linearSearch(0, search);
	if(pos == -1)
		printf("\nElement not found.\n");
	else
		printf("\nElement found at position %d\n", pos+1);
	return 0;
}
