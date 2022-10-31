// implementing Circular Linked List
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
// NOTE: The head pointer is used to get the first & last node of the list.

void insert_last(int val)	// function to insert new node at the end of the lsit
{
	NODE *n = (NODE *)malloc(sizeof(NODE)); // creating a pointer variable for new node
	NODE *p = head;
	n->key = val;	// assigning value/ data to the newly created node
	if (!head)		// head == NULL
	{
		head = n;		// head now points to the first node
		n->next = n;	// node points to itself as it is the only node present in the list
		return;
	}
	while (p->next != head)	// traversing the list until we reach the second last node
		p = p->next;
	p->next = n;	// making the last node point to the address of newly created node
	n->next = head;
}

void insert_first(int val)	// function to insert node at the beginning
{
	NODE *n = (NODE *)malloc(sizeof(NODE)), *p = head;
	n->key = val;
	if(!head)
	{
		head = n;
		n->next = n;
		return;
	}
	while(p->next != head)
	    p = p-> next;
	p->next = n;	// last node now points to newly created node
	n->next = head;	// making the new node point to the first node **(see line 49)
	head = n;   	// now the new node becomes the first node of the list
	// ** the former first node in line 47 becomes the second node.
}

void insert_pos(int val, int pos)	// inserts node at a given position
{
	NODE *n = (NODE *)malloc(sizeof(NODE));
	NODE *p = head;	// temporary pointer variable, used to traverse all the nodes of the lsit
	n->key = val;
	if(pos == 1)
	{
		insert_first(val);
		return;
	}
	int i;
	for (i = 1; i < pos - 1; i++)
	{
		p = p->next;
	}
	n->next = p->next;	// making the newly inserted node point to the next node
	p->next = n;		// making the previous node of the newly inserted node point to the new node
}

int delete_first()	// deletes the first node from the lsit
{
	NODE *p = head;		// points to first node of the list
	int k = head->key;	// 'k' holds the value of the first node to be deleted
	if(p->next == head)
	{
		// below statements are executed when only one node is present in the lsit
		head = NULL;
		p->next = NULL;	// breaking the node link from head
		free(p);
		return k;
	}
	while(p->next != head)
		p = p->next;
	p->next = head->next;	// making the last node point to the second node
	head->next = NULL;		// breaking the link of the first node from other nodes
	free(head);		// dynamically deallocating the first node from memory space
	head = p->next;	// making the head pointer point to second node
					// now the second node becomes the first node of the list
	return k;		// returns the value of deleted node
}

int delete_last()	// deletes the last node
{
	int k;
	NODE *p = head;
	if(p->next == head)
	{
		// below statements are executed when only one node is present in the lsit
		head = NULL;
		p->next = NULL;	// breaking the node link from head
		k = p->key;
		free(p);
		return k;
	}
	while (p->next->next != head)
		p = p->next;	// traversing the list until we reach the second last node
	// Now we have,		p : second last node;	p->next : last node
	k = p->next->key;		// storing the value of last node
	p->next->next = NULL;	// breaking the link of the last node from the list
	free(p->next);			// deallocating the last node
	p->next = head;			// making the second last node point to first node 
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
	printf("\nThe elements of the list are: ");
	do
	{
		printf("%d  ", p->key);
		p = p->next;
	}while(p!=head);
}

void choice()	// menu choice function to perform all operations on the SLL through user choice
{
	int ch;
	int opt, val, pos;
	printf("1: Insertion:");
	printf("\n2: Deletion:");
	printf("\n3: Display");
	printf("\n4: Exit");
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
			val = delete_first(val);
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
		display();
		break;

	case 4:
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
