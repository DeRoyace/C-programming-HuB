// Threaded Binary Search tree:
// Two way threaded
// Inorder traversal

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Threaded_BST
{
	int key, lbit, rbit;
	struct Threaded_BST *left, *right;
} node;

node *head, *dummy = NULL;

void create_node(node *root, int val)  // inserting node in a Threaded BST
{
	node *n = malloc(sizeof(node));
	n->key = val;
	n->left = n->right = NULL;
	if (!root)
	{
		// initializing Dummy / sentinel node:
		dummy = malloc(sizeof(node));
		dummy->key = -999;	  // inserting values not related to actual values to be used in the tree
		dummy->right = dummy; // pointing to itself
		dummy->rbit = 1; // right thread is present

		// intitalizing Tree with the very first node:
		head = n;
		dummy->left = head;
		dummy->lbit = 0; // dummy has no left threaded as its left child is head
		head->left = head->right = dummy; // making the node fully threaded
		head->rbit = head->lbit = 1;	  // indicates the neww node inserted is fully threaded
		return;
	}

	node *cp_node; // temporary node
	while (root)
	{
		cp_node = root;
		if (val > root->key && root->rbit == 0)
			root = root->right;
		else if (val < root->key && root->lbit == 0)
			root = root->left;
		else
			break;
	}

	if (val > cp_node->key)
	{
		// making threads
		n->left = cp_node;
		n->right = cp_node->right;

		// inserting right child
		cp_node->right = n;
		cp_node->rbit = 0;
	}
	else
	{
		// making threads
		n->right = cp_node;
		n->left = cp_node->left;

		// inserting left child
		cp_node->left = n;
		cp_node->lbit = 0;
	}
	n->lbit = n->rbit = 1;
}

node* inorder_succ(node *n)   // finding inorder successor of a node in Threaded BST
{
	if(n->rbit)	
		return n->right;
	
	n = n->right;
	while(n->lbit == 0)
		n = n->left;
	
	return n;
}

void inorder(node *root)  // inorder traversal for Threaded BST
{
	if (!root)
	{
		printf("\nTree has not been initialized.");
		return;
	}
	node *trav = root;
	while(!trav->lbit)
	{
		trav = trav->left;
	}
	// after the above while loop the trav node becomes the leftmost node of the tree
	while (1)
	{
		if(trav == dummy)
			break;
		printf("%d  ", trav->key);
		trav = inorder_succ(trav);
	}
}

int main()
{
	int ch, data;
	while (1)
	{
		printf("\n1: INSERT\n2: INORDER\n3: EXIT");
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
			printf("\nInorder:  ");
			inorder(head);
			break;

		case 3:
			printf("EXITING...");
			exit(1);

		default:
			printf("INVALID choice entered!!");
		}
		printf("\n-------------------------------------------------");
	}
	return 0;
}
