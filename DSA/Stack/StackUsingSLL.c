// Implementing Stack using Simply Linked Lists
#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
	int key;
	struct Stack *next;
}NODE;

NODE *head = NULL;

void push(int val)
{
	NODE *n = (NODE *) malloc(sizeof(NODE));
	n->key = val;
	n->next = head;
	head = n;
}

int pop()
{
	if(head == NULL)
	{
		printf("\nStack is empty");
		return -1;
	}
	int val = 0;
	NODE *n = head;
	head = n->next;
	n->next = NULL;
	val = n->key;
	free(n);
	return val;
}

int peep()
{
	if(head == NULL)
	{
		printf("\nStack is empty");
		return -1;
	}
	return head->key;
}

void display()
{
	if(head == NULL)
	{
		printf("\nStack is empty");
		return;
	}
	NODE *n = head;
	printf("\nStack elements are:\n");
	while(n->next != NULL)
	{
		printf("%d\n", n->key);
		n = n->next;
	}
	printf("%d\n", n->key);
}

void choice() // menu driven function for stack operations
{
	int ch, val;
	printf("\n1: PUSH Elements");
	printf("\n2: POP element");
	printf("\n3: PEEP element");
	printf("\n4: CLEAR Stack");
	printf("\n5: DISPLAY Stack elements");
	printf("\n6: TERMINATE the program");
	printf("\nEnter your choice: ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter element to be inserted: ");
			scanf("%d", &val);
			push(val);
			break;
			
			case 2:
			if(pop() != -1)
				printf("\nDeleted element is %d", pop());
			break;
			
			case 3:
			if(peep() != -1)
				printf("\nTopmost element is %d", peep());
			break;
			
			case 5:
			display();
			break;
			
			case 4:
			head = NULL;
			printf("\nStack is empty now.");
			break;

			case 6:
			exit(1);

			default:
			printf("\nInvalid chhoice\nEnter again...");
			choice();
	}
} // end of choice()

int main()
{
	while(1)
	{
		// this loop runs until user terminates the program by entering choice 6
		choice();
		printf("\n---------------------------------------------");
	}

} // end of main()

