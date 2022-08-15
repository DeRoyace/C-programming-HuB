#include<stdio.h>
#define SIZE 30

char infix[SIZE], postfix[SIZE], stack[SIZE];
int top = -1, k = -1;

void input()
{
	printf("\nEnter your expression: ");
	scanf("%[^\n]", infix);
}

void pop() // poping out operators from stack and pushing into postfix expression
{
	char op;
	if(top == -1)
		return;
	op = stack[top--];
	if(op != '(' )
		postfix[++k] = op;
}

int precedence(char a, char b) // checking operator precedence [ except % ] 
{
	if ( ((a == '+' || a == '-') && (b == '-' || b == '+')) || ((a == '*' || a == '/') && (b == '/' || b == '*')) )
		return 1;
	else if ( (a == '+' || a == '-') && (b == '/' || b == '*') )
		return 0;
	else if ( (a == '*' || a == '/') && (b == '+' || b == '-') )
		return 1;
}

void display(char arr[])
{
	int i;
	for(i = 0; i < SIZE; i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");
}

void scan() // scanning expression and putting into stack and postfix[] as when condition matches
{
	int i, flag = 0;
	char ch, temp;
	for(i = 0; i < SIZE; i++)
	{
		//display(stack);
		while(top > 0 && precedence(stack[top-1], stack[top]) == 1)
		{
			temp = stack[top];
			stack[top--] = '\0';
			pop();
			stack[++top] = temp;
		}

		ch = infix[i];
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')' )
		{
			if(ch == '(') 
				flag = 1;

			if( top != -1 && ch == ')' && flag )
			{
				while(top > -1 && stack[top] != '(' )
					pop();
				flag = 0;
			}
			else if( top != -1 && precedence(stack[top], ch) == 1)
			{
				pop();
				stack[++top] = ch;
			}
			else
				stack[++top] = ch;
		}
		else
			postfix[++k] = ch;
	} //END OF for-loop
	while(top > -1)
		pop();
} //end of scan()

int main()
{
	input();
	printf("\nInfix expression: ");
	display(infix);
	scan();
	printf("\nPostfix expression: ");
	display(postfix);
	return 0;
}
