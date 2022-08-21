// Implemeting Binary Search:
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

int binSearch(int l, int u, int val) // recursive function to search element using Binary Search method.
{
	int mid = ( l + u ) / 2;
	if(arr[mid] == val)
		return mid;
	else if(l == u)
		return -1;
	else if(val > arr[mid])
		return binSearch( mid+1, u, val );
	else //val < arr[mid]
		return binSearch( l, mid-1, val );
} // end of binSearch()

int main()
{
	int search;
	input();
	display();
	printf("\nEnter element to be search: ");
	scanf("%d", &search);
	int pos = binSearch(0, N-1, search);
	if(pos == -1)
		printf("\nElement not found.\n");
	else
		printf("\nElement found at position %d.\n", pos+1);
	return 0;
}
