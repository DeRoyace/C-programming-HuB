//BFS using Adjacency Matrix

#include<stdio.h>
#define size 30
int arr[size][size], vertices[size];
int queue[size], N, front = -1, rear = -1;

void input()
{
	printf("\nEnter no. of nodes [<=30] : ");
	scanf("%d", &N);
	int i, j, k;
	printf("\nEnter the vertices: ");
	for(k=0; k<N; k++)
	{
		scanf("%d", &vertices[k]);
	}
	
	printf("\nFill up the adjacency matrix: ");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("\nIs there any connection between %d and %d ? [0-NO, 1-YES]: ", vertices[i], vertices[j]);
			scanf("%d", &arr[i][j]);	
		}
	}
}

void enqueue(int v)
{	
	if(front > rear)
	{
		front = rear = -1;
	}
	if(front == -1)
		front = 0;
	queue[++rear] = v;
}

int dequeue()
{
	if(front > rear)
	{
		front = rear = -1;
		return -999;
	}
	int v = queue[front++];
	return v;
}

void bfs() // Breadth First Search graph traversal
{
	int i, j;
	int visited[N]; // keeps track of visited vertices (1 - visited, 0 - not visited)
	// initializing the visited array with 0:
	for(i=0; i<N;i++)
	{
		visited[i] = 0;
	}
	
	enqueue(vertices[0]); // assusming source node is from vertices[] at index 0;
	visited[0] = 1;  // the node (at index 0) is marked as visited
	printf("\nTraversed path: ");
	for(i=0; i<N; i++)
	{
		if(visited[i]==0)
		{
			enqueue(vertices[i]);
			visited[i] = 1;
		}	
		for(j=0; j<N; j++)
		{
			if(arr[i][j] == 1 && visited[j]==0)
			{
				enqueue(vertices[j]);
				visited[j] = 1;
			}
		}
		
		int v = dequeue();
		if(v!=-999)
		printf("%d\t", v);
	}
	printf("\n");
}

void display()
{
	int i, j;
	printf("\n");
	for(i=0; i<N; i++)
	{
		printf("\t%d", vertices[i]);
	}
	printf("\n-------------------------------------------------------------------\n");
	for(i=0; i<N; i++)
	{
		printf(" %d |\t", vertices[i]);
		for(j=0; j<N; j++)
		{
			printf("%d\t", arr[i][j]);	
		}
		printf("\n");
	}
	printf("\n******************************************************************\n");	
}

int main()
{
	input();
	display();
	bfs();
	return 0;
}
