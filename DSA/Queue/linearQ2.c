#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int arr[SIZE], front = -1, rear = -1;

void choice()
{
    int ch, val;
    void insert(int);
    void delete ();
    void display();
    printf("\n1: Insert elements");
    printf("\n2: Delete elements");
    printf("\n3: Display elements");
    printf("\n4: Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nEnter element to be inserted in the Queue: ");
        scanf("%d", &val);
        insert(val);
        break;

    case 2:
        delete ();
        break;

    case 3:
        display();
        break;

    case 4:
        exit(0);
        break;

    default:
        printf("\nInvalid choice entered.");
    }
}

void insert(int e)
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue is full!");
        return;
    }
    if (rear == 0)
        front = 0;
    arr[++rear] = e;
}

void shift() // shifts the queue elements towards left by one place
{
    int i, temp;
    for (i = 0; i < rear; i++)
    {
        // arr[i-1] = arr[i];
        arr[i] = arr[i + 1];
    }
    rear--;
}

void delete ()
{
    int e;
    if (front == rear)
    {
        front = rear = -1;
        printf("\nQueue is empty!");
        return;
    }
    e = arr[front];
    printf("\n%d is removed from the Queue", e);
    shift();
}

void display()
{
    int i;
    if (front == rear && front == -1)
    {
        printf("\nNo elements presnt in the Queue.");
        return;
    }
    printf("\nElements present in Queue are:  ");
    for (i = front; i <= rear; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        choice();
        printf("\n---------------------------------------------------------");
    }
}