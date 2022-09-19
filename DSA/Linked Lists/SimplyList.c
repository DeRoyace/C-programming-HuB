// implementing Simply Linked List (SLL)
// Using integers as node values
#include <stdio.h>
#include <stdlib.h>

// Creating a structure below for making Nodes of a List:
// Each node consists of two elements:	1) Data	  2) Address
typedef struct List
{
	int key; 			// holds the data of the node
	struct List *next; 	// stores the address of next node in a sequence
} NODE; 				// name of the structure

NODE *head = NULL;	// creating a head pointer that initially points to NULL
// The head pointer is used to point to the first node of the list.

void insert_last(int val)	// function to insert new node at the end of the lsit
{
	NODE *n = (NODE *)malloc(sizeof(NODE)); // creating a pointer variable for new node
	NODE *p = head;
	n->key = val;	// assigning value/ data to the newly created node
	n->next = NULL;	// assigning the pointing address of the node as NULL
	if (!head)		// head == NULL
	{
		head = n;	// head now points to the first node
		return;
	}
	while (p->next != NULL)	// traversing the list until we reach the second last node
		p = p->next;
	p->next = n;	// making the last node point to the address of newly created node
}

void insert_first(int val)	// function to insert node at the beginning
{
	NODE *n = (NODE *)malloc(sizeof(NODE));
	n->key = val;
	n->next = head;	// making the new node point to the first node
	head = n; 		// now the new node becomes the first node of the list
}

void insert_pos(int val, int pos)	// inserts node at a given position
{
	NODE *n = (NODE *)malloc(sizeof(NODE));
	NODE *p = head;	// temporary pointer variable, used to traverse all the nodes of the lsit
	n->key = val;
	int i;
	for (i = 1; i < pos - 1; i++)
	{
		p = p->next;
	}
	n->next = p->next;	// making the newly inserted node point to the next node
	p->next = n;		// makingthe previous node of the newly inserted node point to the new node
}

int delete_first()	// deletes the first node from the lsit
{
	NODE *p = head;	// points to first node of the list
	int k = p->key;	// 'k' holds the value of the first node to be deleted
	head = p->next;	// making the head pointer point to second node
					// now the second node becomes the first node of the list
	p->next = NULL;	// breaking the link of the node from other nodes
	free(p);		// dynamically deallocating the deleted node from memory space
	return k;		// returns the value of deleted node
}

int delete_last()	// deletes the last node
{
	int k;
	NODE *p = head;
	if(p->next == NULL)
	{
		return delete_first();
	}
	while (p->next->next != NULL)
		p = p->next;	// traversing the list until we reach the second last node
	// Now we have,		p : second last node;	p->next : last node
	k = p->next->key;	// storing the value of last node
	free(p->next);	// deallocating the last node
	p->next = NULL;	// making the second last node point to nothing 
	return k;
}

int delete_pos(int pos)	// deletes node from the list at a given positin
{
	int i, k;
	NODE *p1 = head, *p2;
	if (pos == 1)
	{
		k = delete_first();
	}
	else
	{
		for (i = 1; i < pos - 1; i++)
			p1 = p1->next;	// travesing upto the node before the given position
		p2 = p1->next;	// p2 now holds the node to be deleted
		p1->next = p2->next;	// p1 now points to the next node of p2
		p2->next = NULL;
		k = p2->key;
		free(p2);
	}
	return k;
}

void display()	// function to display the values of all the nodes of the list
{
	if(!head)
	{
		printf("List is Empty");
		return;
	}
	NODE *p = head;
	while (p->next != NULL)
	{
		printf("%d  ", p->key);	// prints all the node values upto second last node
		p = p->next;
	}
	printf("%d\n", p->key);	// prints the value of last node
}

void reverseList()	// function to reverse the list
{
	if(!head)
	{
		printf("\nList is empty");
		return;
	}
	printf("\nOriginal list:  ");
	display();
	NODE *x, *y, *z;
	x = head;	// traverses all the nodes of the list
	y = NULL;	// holds the address of the node just before the current node pointed by x
				// z is used for reversal purpose
	while(x)
	{
		z = y;
		y = x;
		x = x->next;
		y->next = z;
	}
	head = y;
	printf("\nList after reversal:  ");
	display();
}

void sort()	// sorts the values of each nodes of the list using selection sorting technique
{
	NODE *i = head, *j;
	int temp;
	for( ;i->next ; i = i->next)
	{
		for(j = i->next; j; j = j->next)
		{
			if(j->key < i->key)
			{
				temp = i->key;
				i->key = j->key;
				j->key = temp;
			}
		}
	}
}

void choice()	// menu choice function to perform all operations on the SLL through user choice
{
	int ch;
	int opt, val, pos;
	printf("1: Insertion:");
	printf("\n2: Deletion:");
	printf("\n3: Display");
	printf("\n4: Reverse the list order");
	printf("\n5: Sort");
	printf("\n6: Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		printf("\nInsertion:");
		printf("\n	1: At beginning");
		printf("\n	2: At a given position");
		printf("\n	3: At the End");
		printf("\nEnter your option: ");
		scanf("%d", &opt);
		printf("\nEnter element to be inserted: ");
		scanf("%d", &val);
		switch (opt)
		{
		case 1:
			insert_first(val);
			break;

		case 2:
			printf("\nEnter position at which element to be inserted: ");
			scanf("%d", &pos);
			insert_pos(val, pos);
			break;

		case 3:
			insert_last(val);
			break;

		default:
			printf("\nInvalid Choice");
		}
		break;

	case 2:
		printf("\nDeletion:");
		printf("\n	1: At beginning");
		printf("\n	2: At a given position");
		printf("\n	3: At the End");
		printf("\nEnter your option: ");
		scanf("%d", &opt);
		if(!head)
		{
			printf("List is empty");
			return;
		}
		switch (opt)
		{
		case 1:
			val = delete_first();
			break;

		case 2:
			printf("\nEnter position at which element to be deleted: ");
			scanf("%d", &pos);
			val = delete_pos(pos);
			break;

		case 3:
			val = delete_last();
			break;

		default:
			printf("\nInvalid Choice");
		}
		printf("\nDeleted element is %d", val);
		break;

	case 3:
		printf("\nList elements are:  ");
		display();
		break;

	case 4:
		reverseList();
		break;
	
	case 5:
		sort();
		break;
	
	case 6:
		exit(1);

	default:
		printf("\nInvalid choice.\nEnter again...");
	}
}	// end of choice()

int main()
{
	while (1)
	{
		choice();
		printf("\n-------------------------------------------------------------------\n");
	}
}
