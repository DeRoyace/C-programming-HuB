// Linear Queue implementation using Singly Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct items
{
	int key;
	struct items *next;
}node;

node *head = NULL;

void enque(int val)	// insertion of queue elements from rear end
{
	node *n = (node *) malloc(sizeof(node)), *p = head;
	n->key = val;
	n->next = NULL;
	if(!head)
	{
		head = n;
		return;
	}
	while(p->next)
		p = p->next;
	p->next = n;
	printf("\n%d is inserted", val);
}

int deque()	// deletion of queue from front end 
{
	if( !head )
	{
		printf("\nQueue is empty");
		return -1;
	}
	node *p = head;
	int val = p->key;
	head = p->next;
	p->next = NULL;
	free(p);
	return val;
}

void display()
{
	if(!head)
	{
		printf("\nQueue is empty!");
		return;
	}
	node *p = head;
	while(p)
	{
		printf("%d  ", p->key);
		p = p->next;
	}
}

void choice()
{
    int ch, val;
	printf("\n1: Insert elements");
	printf("\n2: Delete elements");
	printf("\n3: Display elements");
	printf("\n4: Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &ch);
	switch (ch)
	{
		case 1:
			printf("\nEnter element to be inserted in the Queue: ");
			scanf("%d", &val);
			enque(val);
			break;

		case 2:
			val = deque();
			if( val != -1 )
				printf("\n%d is deleted from the queue", val );
			break;

		case 3:
			display();
			break;

		case 4:
			exit(0);

		default:
			printf("\nInvalid choice entered.");
	}
}

int main()
{
    while (1)
    {
        choice();
        printf("\n---------------------------------------------------------");
    }
}
