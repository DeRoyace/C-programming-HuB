// Binary tree Non-recursively:
// create_node(): ask user to enter node on which side of the tree
// Non-Recursive functions: inorder, pre-order, post-order
#include <stdio.h>
#include <stdlib.h>
#define SIZE 30
int top = -1;

typedef struct BT
{
	int key;
	struct BT *left, *right;
} node;

node *head = NULL;
node *arr[SIZE];

void create_node(node *root, int val)
{
	int ch;
	node *n = malloc(sizeof(node));
	node *cp_node = root;
	n->key = val;
	n->left = n->right = NULL;
	if (!root)
	{
		head = n;
		return;
	}

	while (root)
	{
		cp_node = root;
		printf("\nWhich side of the node you want to enter? [ 0-left, 1-right ] 0/1: ");
		scanf("%d", &ch);
		if (ch)
			root = root->right;
		else
			root = root->left;
	}

	if (ch)
		cp_node->right = n;
	else
		cp_node->left = n;
}

node* pop()
{
	if (top == -1)
		return NULL;
	return arr[top--];
}

void push(node *n)
{
	if(n)
		arr[++top] = n;
}

void inorder(node *root)
{
	if (!root)
	{
		printf("\nTree has not been initialized.");
		return;
	}
	push(root);
	while (top!=-1)
	{
		while (root)
		{
			root = root->left;
			push(root);
		}

		node *pop_node = NULL;
		pop_node = pop();
		printf("%d  ", pop_node->key);

		if (pop_node->right)
		{
			root = pop_node->right;
			push(root);
		}
	}
}

void preorder(node *root)
{
	if (!root)
	{
		printf("\nTree has not been initialized.");
		return;
	}
	push(root);

	while (top != -1)
	{
		while (root)
		{
			printf("%d  ", root->key);
			root = root->left;
			push(root);
		}
		
		node *pop_node = pop();
		if (pop_node->right)
		{
			root = pop_node->right;
			push(root);
		}
	}
}

void postorder(node *root)
{
	if (!root)
	{
		printf("\nTree has not been initialized.");
		return;
	}
	node *cp_node = NULL;
	push(root);
	while (top!=-1)
	{
		while (root)
		{
			root = root->left;
			push(root);
		}
		node *pop_node = pop();
		if (pop_node->right && pop_node != cp_node)
		{
			push(pop_node);
			cp_node = pop_node;
			root = pop_node->right;
			push(root);
		}
		else
			printf("%d  ", pop_node->key);
	}
}

int main()
{
	int ch, data;
	while (1)
	{
		printf("\n1: INSERT\n2: PRE-ORDER\n3: INORDER\n4: POST-ORDER\n5: EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nEnter the data (integer) you want to insert: ");
			scanf("%d", &data);
			create_node(head, data);
			break;

		case 2:
			printf("\nPre-order:  ");
			preorder(head);
			break;

		case 3:
			printf("\nInorder:  ");
			inorder(head);
			break;

		case 4:
			printf("\nPost-order:  ");
			postorder(head);
			break;

		case 5:
			printf("EXITING...");
			exit(1);

		default:
			printf("INVALID choice entered!!");
		}
		printf("\n------------------------");
	}
	return 0;
}
