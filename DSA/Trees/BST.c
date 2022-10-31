// Binary Search Tree:
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
	int key;
	struct Tree *left, *right;
}NODE;

NODE *root = NULL;

void create(int val)
{
	NODE  *n = malloc(sizeof(NODE));
	NODE *trav = root;
	NODE *track;
	n->key = val;
	n->left = n->right = NULL;
	while(!root)
	{
		root = n;
		return;
	}

	while(trav)
	{
		track = trav;
		if(val > trav->key)
			trav = trav->right;
		else
			trav = trav->left;
	}

	if(val > track->key)
		track->right = n;
	else
		track->left = n;
}

void inorder(NODE *r)
{
	if(r)
	{
		inorder(r->left);
		printf("%d	", r->key);
		inorder(r->right);
	}
}

void preorder(NODE *r)
{
	if(r)
	{
		printf("%d	", r->key);
		preorder(r->left);
		preorder(r->right);
	}
}

void postorder(NODE *r)
{
	if(r)
	{
		postorder(r->left);
		postorder(r->right);
		printf("%d	", r->key);
	}
}

void search(int val)
{
	int flag = 0;
	NODE *r = root;
	if(!r)
	{
		printf("Tree has not been initialized");
		return;
	}
	while(r)
	{
		if(val > r->key)
			r = r->right;
		else if(val < r->key)
			r = r->left;
		else
		{
			flag = 1;
			printf("\nElement found");
			break;
		}
	}
	if(flag==0)
		printf("\nElement not found");
}

void choice()
{
	int ch, val;
	printf("\n1: Insert\n2: Display\n3: Search element\n4: Exit\nEnter your choice: ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
		printf("\nEnter the element to be inserted in the tree: ");
		scanf("%d", &val);
		create(val);
		break;

		case 2:
		printf("\n1: Preorder\n2: Inorder\n3: Postorder\nEnter the display type: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
			preorder(root);
			break;

			case 2:
			inorder(root);
			break;

			case 3:
			postorder(root);
			break;

			default:
			printf("\nInvalid choice");
		}
		break;

		case 3:
		printf("\nENter value to be search: ");
		scanf("%d", &val);
		search(val);
		break;

		case 4:
		exit(1);

		default:
		printf("\nInvalid choice");
	}
}

int main()
{
	while(1)
	{
		choice();
		printf("\n----------------------------------------------------------");
	}
}