#include<stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push(int e) // pushing or inserting elements into stack
{
	if(top == SIZE-1)
	{
		printf("\nStack is full!\nCannot insert anymore element.");
		return;
	}
	stack[++top] = e;
}

void pop() // poping / deleting stack elements from top
{
	if(top == -1)
	{
		printf("\nStack is empty!");
		return;
	}
	printf("\nPoped element is %d", stack[top--]);
}

void peep() // shows the topmost element present in the stack
{
	if(top == -1)
	{
		printf("\nStack is empty!!");
		return;
	}
	printf("\nTopmost element is %d",stack[top]);
}

void display() // displays stack elements
{
	int i;
	if(top == -1)
	{
		printf("\nStack is empty!");
		return;
	}
	printf("\nStack elements are: ");
	for(i = top; i >= 0; i--)
	{
		printf("\n%d", stack[i]);
	}
} // end of display

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
			pop();
			break;
			
			case 3:
			peep();
			break;
			
			case 5:
			display();
			break;
			
			case 4:
			top = -1;
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
