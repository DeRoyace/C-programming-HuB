//Implementing Circular Queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
int front = -1, rear = -1, arr[SIZE];
void choice()
{
	int ch, val;
	void insert(int);
	void deleteQ();
	void display();
	void linear(int);
	
	printf("\n1: Insert");
	printf("\n2: Delete");
	printf("\n3: Display");
	printf("\n4: Search an element");
	printf("\n5: Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
        printf("\nEnter element to be insert: ");
		scanf("%d", &val);
		insert(val);
		break;
			
		case 2:
		deleteQ();
		break;
		
		case 3:
		display();
		break;
		
		case 4:
        printf("\nEnter element to be search: ");
        scanf("%d", &val);
        linear(val);
        break;
		
		case 5:
		exit(1);
		
		default:
		printf("Invalid choice. Enter again...");		
	}
}

void insert(int e)
{
	if((front == 0 && rear == SIZE-1) || front == rear+1)
	{
		printf("\nQueue is full!!");
		return;
	}
	if(front == -1)
		front = 0;
	rear = (rear+1)%SIZE;
	arr[rear] = e;
	printf("\nElemenet %d inserted in the queue", e);
}

void deleteQ()
{
	if(front == -1)
	{
		printf("\nQueue is empty!!");
		return;
	}
	printf("\nElement %d is deleted from the queue", arr[front]);
	if(front == rear)
		front = rear = -1;
	else	
		front = (front+1)%SIZE;
}

void display()
{
	int i;
	if(front == -1)
	{
		printf("\nQueue is empty!!");
		return;
	}
	printf("\nQueue elements are: ");
	for(i = front; i != rear; i = ( (i+1) % SIZE ) )
	{
		printf("%d  ", arr[i]);
	}
	printf("%d  ", arr[rear]);
}

void linear(int e)
{
	int i, flag = 0;
	if(front == -1)
	{
		printf("\nQueue is empty!!");
		return;
	}
	
	// code for linear search:
	for(i = front; i != rear; i = ((i+1) % SIZE) )
	{
		if(e == arr[i])
		flag = 1;
		break;
	}
	if(e == arr[rear])
		flag = 1;
	
	if(flag == 1)	
		printf("\nElement found");
	else
		printf("\nElement not found");
}

int main()
{
	while(1)
	{
		choice();
		printf("\n-------------------------------------------------------------------");
	}
}
