// AVL Tree
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct AVL
{
	int key;
	struct AVL *left, *right;
} node;

node *head = NULL;

int height(node *n)
{
	int hl, hr;
	if (n == NULL)
	{
		return 0;
	}
	hl = height(n->left);
	hr = height(n->right);
	return 1 + (hl > hr ? hl : hr);
}

int balanceFactor(node *n)
{
	int hl, hr;
	hl = height(n->left);
	hr = height(n->right);
	return hl - hr;
}

void rr_rotate(node *n, node *parent)
{
	node *rc = n->right;
	if (parent == n)
	{
		head = rc;
	}
	else
	{
		if (parent->left == n)
			parent->left = rc;
		else
			parent->right = rc;
	}

	n->right = rc->left;
	rc->left = n;
}

void rl_rotate(node *n, node *parent)
{
	node *rc = n->right;
	n->right = rc->left;
	rc->left = rc->left->right;
	rr_rotate(n, parent);
}

void ll_rotate(node *n, node *parent)
{
	node *lc = n->left;
	if (parent == n)
	{
		head = lc;
	}
	else
	{
		if (parent->left == n)
			parent->left = lc;
		else
			parent->right = lc;
	}
	n->left = lc->right;
	lc->right = n;
}

void lr_rotate(node *n, node *parent)
{
	node *lc = n->left;
	n->left = lc->right;
	lc->right = lc->right->left;
	ll_rotate(n, parent);
}

void rotation(node *n, node *parent)
{
	printf("\ninside rotation");
	int bf = balanceFactor(n);
	// since BF is left - right
	if (bf < -1)
	{
		// RL or RR
		node *rc = n->right;
		if (balanceFactor(rc) == -1)
			rr_rotate(n, parent);
		else
			rl_rotate(n, parent);
	}
	else if (bf > 1)
	{
		// LL or LR
		node *lc = n->left;
		if (balanceFactor(lc) == 1)
			ll_rotate(n, parent);
		else
			lr_rotate(n, parent);
	}
}

void balancing(node *root, node *unbalanced_node, node *parent_un) // balancing in postorder order manner
{
	if (root)
	{
		balancing(root->left, unbalanced_node, root);
		balancing(root->right, unbalanced_node, root);
		int bf = balanceFactor(root);
		printf("\nBalance factor of %d = %d", root->key, bf);
		if (abs(bf) > 1 && !unbalanced_node)
		{
			unbalanced_node = root;
			printf("\nUnbalanced node = %d\n Parent node = %d", unbalanced_node->key, parent_un->key);
			rotation(unbalanced_node, parent_un);
		}
	}
}

void inorder(node *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d  ", root->key);
		inorder(root->right);
	}
}

void preorder(node *root)
{
	if (root)
	{
		printf("%d  ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d  ", root->key);
	}
}

void create_node(node *root, int val)
{
	node *n = malloc(sizeof(node));
	node *cp_node = root;
	n->key = val;
	n->left = n->right = NULL;
	if (!root)
	{
		head = n;
		balancing(head, NULL, head);
		return;
	}

	while (root)
	{
		cp_node = root;
		if (val > root->key)
			root = root->right;
		else
			root = root->left;
	}

	if (val > cp_node->key)
		cp_node->right = n;
	else
		cp_node->left = n;
	balancing(head, NULL, head);
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
			printf("\nPostorder:  ");
			postorder(head);
			break;
		case 5:
			printf("EXITING...");
			exit(1);

		default:
			printf("INVALID choice entered!!");
		}
		printf("\n----------------------------------------");
	}
	return 0;
}