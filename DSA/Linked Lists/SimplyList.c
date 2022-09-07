// implementing Simply Linked List:
// Using integers as node values
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct List
{
	int key;
	struct List *next;
}NODE;

NODE *head = NULL;

void insert(int val)
{
	NODE *n = (NODE *) malloc(sizeof(NODE));
	NODE *p = head;
	n->key = val;
	n->next = NULL;
	if(!head) // head == NULL
	{
		head = n;
		return;
	}
	while(p->next != NULL)
		p = p -> next;
	p->next = n;
}

void insert_first(int val)
{
	NODE *n = (NODE *) malloc(sizeof(NODE));
	n->key = val;
	n->next = head;
	head = n;
}

void insert_pos(int val, int pos)
{
	NODE *n = (NODE *) malloc(sizeof(NODE));
	NODE *p = head;
	n->key = val;
	int i;
	for(i = 1; i < pos-1; i++)
	{
		p = p->next;
	}
	n->next = p->next;
	p->next = n;
}

int delete_first()
{
	NODE *p = head;
	int k = p->key;
	head = p->next;
	p->next = NULL;
	free(p);
	return k;
}

int delete_last()
{
	int k;
	NODE *p = head;
	while( p->next->next != NULL)
		p = p->next;
	k = p->next->key;
	free(p->next);
	p -> next = NULL;
	return k;
}

int delete_pos(int pos)
{
	int i, k;
	NODE *p1 = head, *p2;
	if(pos == 1)
	{
		k = delete_first();
	}
	else
	{
		for(i=1; i<pos-1; i++)
			p1 = p1->next;
		p2 = p1->next;
		p1->next = p2->next;
		p2->next = NULL;
		k = p2->key;
		free(p2);
	}
	return k;
}

void display()
{
	NODE *p = head;
	printf("\nThe elements of the list are: ");
	while(p->next != NULL)
	{
		printf("%d  ", p->key);
		p = p->next;
	}
	printf("%d\n", p->key);
}

void choice()
{
	char ch, yn;
	int opt, val, pos;
	if(head == NULL)
	{
		printf("\nCreate a linked list (Y/N): ");
		scanf("%c", &yn);
		if(yn == 'y' || yn == 'Y')
		{
			printf("\nEnter an element to be inserted: ");
			scanf("%d", &val);
			insert(val);
		}
		else
			exit(1);
	}
	else
	{
		printf("\nA: Insertion:");
		printf("\nB: Deletion:");
		printf("\nC: Display");
		printf("\nD: Exit");
		printf("\nEnter your choice: ");
		scanf("%c", &ch);
		ch = toupper(ch);
		switch(ch)
		{
			case 'A':
				printf("\nInsertion:");
				printf("\n	1: At beginning");
				printf("\n	2: At a given position");
				printf("\n	3: At the End");
				printf("\nEnter your option: ");
				scanf("%d", &opt);
				printf("Enter element to be inserted: ");
				scanf("%d", &val);
				switch(opt)
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
						insert(val);
						break;

					default:
						printf("\nInvalid Choice");
				}
				break;

			case 'B':
				printf("\nDeletion:");
				printf("\n	1: At beginning");
				printf("\n	2: At a given position");
				printf("\n	3: At the End");
				printf("\nEnter your option: ");
				scanf("%d", &opt);
				switch(opt)
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

			case 'C':
				display();
				break;

			case 'D':
				exit(1);

			default:
				printf("\nInvalid choice.\nEnter again...");
		}
	}
}

int main()
{
	while(1)
	{
		choice();
		printf("\n-------------------------------------------------------------------\n");
	}
}
