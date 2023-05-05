// DFS using Adjacency List

#include<stdio.h>
#include<stdlib.h>
#define size 30
int stack[size], vertices[size], top = -1;

typedef struct vertex
{
	int vertex_name, visited;
	struct vertex *next_vertex, *adj_vertex;
} vtx;

vtx *head = NULL;

typedef struct adj_list
{
	int adj_vname;
	struct adj_list *next;
} list;

void insert(int v)
{	
	vtx *n = malloc(sizeof(vtx));
	n->vertex_name = v;
	n->next_vertex = head;
	head = n;
}

void input()
{
	int N, i, vname;
	printf("\nEnter no. of vertices you want to insert : ");
	scanf("%d", &N);
	printf("\nEnter the vertices: ");
	for(i=0; i<N; i++)
	{
		scanf("%d", &vname);
		vertices[i] = vname;
		insert(vname);
	}
	
	printf("\nProvide the connection between vertices: ");
	vtx *trav = head;
	int ans;
	while(trav)
	{
		vtx *adj_trav = head;
		while(adj_trav)
		{
			printf("\nIs there any connection between %d and %d ? [0-NO, 1-YES]: ", trav->vertex_name, adj_trav->vertex_name);
			scanf("%d", &ans);
			if(ans)
			{
				list *n = (list*)malloc(sizeof(list));
				n->adj_vname = adj_trav->vertex_name;
				n->next = trav->adj_vertex;
				trav->adj_vertex = n;
			}
			adj_trav = adj_trav->next_vertex;
		}
		trav = trav->next_vertex;
	}
}

void push(int v)
{
	if(top == size-1)
	return;
	stack[++top] = v;
}

int pop()
{
	if(top==-1)
	return -999;
	int v = stack[top--];
	return v;
}

void dfs()
{
	vtx *trav = head;
	while(trav)
	{
		if(trav->visited != 1)
		{
			push(trav->vertex_name);
			trav->visited = 1;
		}
		list *adj_trav = trav->adj_vertex;
		while(adj_trav)
		{
			trav = adj_trav;
			if(trav->visited != 1)
			{	
				push(trav->vertex_name);
				trav->visited = 1;
			}
			adj_trav = adj_trav->next;
		}
		trav = trav->next_vertex;
	}
}

void display()
{
	vtx *trav = head;
	while(trav)
	{
		printf("%d --> ", trav->vertex_name);
		list *adj_trav = trav->adj_vertex;
		while(adj_trav)
		{
			printf("%d, ", adj_trav->adj_vname);
			adj_trav = adj_trav->next;
		}
		trav = trav->next_vertex;
		printf("\n-----------------------------------------------------\n");
	}
}

int main()
{
	input();
	display();
	return 0;
}
