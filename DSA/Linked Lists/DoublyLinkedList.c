// Implementing Doubly Linked List using head pointer

#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
	int key;
	struct list *prev, *next;
}NODE;

NODE *head = NULL;

void insert_first(int val)
{
	NODE *n = (NODE *) malloc(sizeof(NODE));
	n -> key = val;
	n -> prev = NULL;
	n -> next = head;
	if(head)
		head -> prev = n;
	head = n;
}

void insert_last(int val)
{
	NODE *n = (NODE *) malloc(sizeof(NODE)), *p = head;
	n -> key = val;
	n -> next = NULL;
	if(!head)  // i.e. head == NULL
	{
		n -> prev = NULL;
		head = n;
		return;
	}
	while(p -> next)
		p = p -> next;
	n -> prev = p;
	p->next = n;
}

void insert_pos(int pos, int val)
{
	int i;
	NODE *n = (NODE *) malloc(sizeof(NODE)), *p = head;
	n -> key = val;
	if(pos == 1)
	{
		insert_first(val);
		return;
	}
	for(i = 1; i < pos-1; i++)
		p = p->next;
	n -> next = p->next;
	n -> prev = p;
	p->next->prev = n;
	p -> next = n;
}

int delete_first()
{
	NODE *p = head;
	int val = head->key;
	head = p->next;
	if(head)
		head->prev = NULL;
	p->next = NULL;
	free(p);
	return val;
}

int delete_last()
{
	NODE *p = head;
	int val;
	if(p->next == NULL)
	{
		return delete_first();
	}
	while(p->next->next)
		p = p->next;
	val = p->next->key;
	p->next->prev = NULL;
	free(p->next);
	p->next = NULL;
	return val;
}

int delete_pos(int pos)
{
	NODE *p = head, *n;
	int i, val;
	for(i = 1; i < pos-1; i++)
		p = p->next;
	n = p->next;
	val = n->key;
	p->next = n->next;
	if(n->next)
		n->next->prev = p;
	n-> prev = NULL;
	n->next = NULL;
	free(n);
	return val;
}

void display()
{
	if(!head)
	{
		printf("List is empty!");
		return;
	}
	NODE *p = head;
	printf("\nList elements are:  ");
	while(p->next)
	{
		printf("%d  ", p->key);
		p = p->next;
	}
	printf("%d\n", p->key);
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

void choice()
{
	int ch;
	int opt, val, pos;
	printf("1: Insertion:");
	printf("\n2: Deletion:");
	printf("\n3: Display");
	printf("\n4: Reverse list display");
	printf("\n5: Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &ch);
	// ch = toupper(ch);
	switch (ch)
	{
	case 1:
		printf("\nInsertion:");
		printf("\n  1: At beginning");
		printf("\n  2: At a given position");
		printf("\n  3: At the End");
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
			insert_pos(pos, val);
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
		printf("\n  1: At beginning");
		printf("\n  2: At a given position");
		printf("\n  3: At the End");
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
		reverseList();
		break;

	case 5:
		exit(1);

	default:
		printf("\nInvalid choice.\nEnter again...");
	}
}

int main()
{
	while (1)
	{
		choice();
		printf("\n-------------------------------------------------------------------\n");
	}
}