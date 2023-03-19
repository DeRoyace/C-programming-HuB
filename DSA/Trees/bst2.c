// Binary Search tree:
// Insertion 
// Deletion
// Search
// Traversal - Non-recursive technique

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 30
int top = -1;

typedef struct BT {
	int key;
	struct BT *left, *right;
} node;

node *head = NULL;
node *arr[SIZE];

void create_node( node *root, int val)
{
	node *n = malloc(sizeof(node));
	node *cp_node = root;
	n->key = val;
	n->left = n->right = NULL;
	if(!root)
	{
		head = n;
		return;
	}
	
	while(root)
	{
		cp_node = root;
		if(val > root->key)
			root = root->right;
		else
			root = root->left;
	}
	
	if(val > cp_node->key)
		cp_node->right = n;
	else
		cp_node->left = n;
}

node* pop()
{
	if(top == -1)
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
	if(!root)
	{
		printf("\nTree has not been initialized.");
		return;
	}
	push(root);
	while(top!=-1)
	{
		while(root)
		{
			root = root->left;
			push(root);
		}	
		
		node *pop_node = pop();
		printf("%d  ", abs(pop_node->key));
		if(pop_node->right)
		{
			root = pop_node->right;
			push(root);
		}
	}
}

void preorder(node *root)
{
	if(!root)
	{
		printf("\nTree has not been initialized.");
		return;
	}
	push(root);
	while(top!=-1)
	{
		while(root)
		{
			printf("%d  ", abs(root->key));
			root = root->left;
			push(root);
		}
		node *pop_node = pop();
		if(pop_node->right)
		{
			root = pop_node->right;
			push(root);
		}
	}
}

void postorder(node *root)
{
	if(!root)
	{
		printf("\nTree has not been initialized.");
		return;
	}
	node *cp_node = NULL;
	push(root);
	while(top!=-1)
	{
		while(root)
		{
			root = root->left;
			push(root);
		}
		node *pop_node = pop();
		if( pop_node->right && pop_node->key > 0)
		{
			pop_node->key = -pop_node->key;
			push(pop_node);
			root = pop_node->right;
			push(root);
		}
		else
			printf("%d  ", abs(pop_node->key));
	}
}

int search(node *root, int val)
{
	if(!root)
	{
		printf("\nTree has not been initialized.");	
		return 0;
	}
	int flag = 0;
	while(root)
	{
		if(val > root->key)
			root = root->right;
		else if(val < root->key)
			root = root->left;
		else
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

void delete_childNode(node *child, node *parent)
{
	if(parent->left == child)
		parent->left = NULL;
	else
		parent->right = NULL;
		
	free(child);
}

void delete_halfNode(node *child, node *parent)
{
	if(parent->left == child)
	{
		if(child->left)
		{
			parent->left = child->left;
			child->left = NULL;
		}	
		else
		{
			parent->left = child->right;
			child->right = NULL;
		}
			
	}
	else
	{
		if(child->left)
		{
			parent->right = child->left;
			child->left = NULL;
		}	
		else
		{
			parent->right = child->right;
			child->right = NULL;
		}
	}
	free(child);
}

node* inorder_succ(node *n)
{
	node *parent = n;
	n = n->right;
	while (n->left)
	{
		parent = n;
		n = n->left;
	}
	if(parent->left == n)
		parent->left = NULL;
	else
		parent->right = NULL;
	return n;
}

void delete_fullNode(node *child, node *parent)
{
	node *in_succ = inorder_succ(child);
	in_succ->right = child->right;
	in_succ->left = child->left;
	if(parent->left = child)
		parent->left = in_succ;
	else
		parent->right = in_succ;
	child->left = child->right = NULL;
	free(child);
}

void deleteNode(node *root, int val)
{
	node *trav = root;
	if(!root)
	{
		printf("\nTree has not been initialized.");	
		return;
	}
	int child = -1;
	node *parent = NULL;
	while(trav)
	{
		if(trav->key == val)
		{
			if(trav->left && trav->right )
				child = 2;
			else if (trav->left || trav->right)
				child = 1;
			else
				child = 0;
			break;
		}
		parent = trav;
		if(val > trav->key && trav->right!=NULL )
			trav = trav->right;
		else if(val < trav->key && trav->left!=NULL)
			trav = trav->left;
		
	}
	switch(child)
	{
		case 0:
			delete_childNode(trav, parent);
			break;
			
		case 1:
			delete_halfNode(trav, parent);
			break;

		case 2:
			delete_fullNode(trav, parent);
			break;

		default:
			printf("\nThe element not present in the tree.");
	}
}


int main()
{
	int ch, data;
	while(1)
	{
		printf("\n1: INSERT\n2: PRE-ORDER\n3: INORDER\n4: POST-ORDER\n5: SEARCH\n6: DELETE\n7: EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
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
				printf("\nPostorder:  ");
				postorder(head);
				break;
			case 5:
				printf("\nEnter the element you want to search:  ");
				scanf("%d", &data);
				if (search(head, data) == 1)
					printf("\nElement is present.");
				else
					printf("\nElement not found.");
				break;
			
			case 6:
				printf("\nEnter the element you want to delete: ");
				scanf("%d", &data);
				deleteNode(head, data);
				break;
				
			case 7:
				printf("EXITING...");
				exit(1);
				
			default:
				printf("INVALID choice entered!!");
		}
		printf("\n----------------------------------------");
	}
	return 0;
}
