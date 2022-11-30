// Creating a Heap tree using given set of integer elements.
#include <stdio.h>

void input(int N, int arr[])
{
	int i;
	printf("Enter array elements:\n");
	for(i=0; i<N; i++)
	{
		scanf("%d", &arr[i]);
	}
}

void display(int N, int arr[])
{
	int i;
	for(i=0; i<N; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

void minHeap(int N, int arr[])
{
	int i, temp, parent_pos, child_pos;
	for(i=1; i<N; i++)
	{
		temp = arr[i];
		child_pos = i;
		parent_pos = ( child_pos - 1 ) / 2;
		while (arr[parent_pos] > temp)
		{
			arr[child_pos] = arr[parent_pos];
			arr[parent_pos] = temp;
			temp = arr[parent_pos];
			child_pos = parent_pos;
			parent_pos = (parent_pos-1) / 2;
		}
	}
}

void maxHeap(int N, int arr[])
{
	int i, temp, parent_pos, child_pos;
	for(i=1; i<N; i++)
	{
		temp = arr[i];
		child_pos = i;
		parent_pos = (i-1) / 2;
		while(child_pos > 0  && arr[parent_pos] < temp)
		{
			arr[child_pos] = arr[parent_pos];
			child_pos = parent_pos;
			parent_pos = (parent_pos-1) / temp;
		}
		arr[child_pos] = temp;
	}
}

int main()
{
	int size, ch;
	printf("\nEnter size of tree: ");
	scanf("%d", &size);
	int binary_tree[size];
	input(size, binary_tree);
	printf("\nOriginal binary tree: ");
	display(size, binary_tree);
	printf("\n1: Max heap\n2: Min heap\nEnter your choice: ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
			maxHeap(size, binary_tree);
			printf("\nYou max heap tree is: ");
			display(size, binary_tree);
			break;

		case 2:
			minHeap(size, binary_tree);
			printf("\nYou max heap tree is: ");
			display(size, binary_tree);
			break;

		default:
			printf("\nInvalid Choice\n");
	}
	return 0;
}