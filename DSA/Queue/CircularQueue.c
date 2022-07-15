#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int arr[SIZE], front = -1, rear = -1;

void choice()
{
    int ch, val;
    int isFull();
    int isEmpty();
    void insert(int);
    void delete ();
    void display();
    printf("\n1: Insert elements");
    printf("\n2: Delete elements");
    printf("\n3: Display queue elements");
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

int isFull()
{
    if ((front == rear + 1 && front < SIZE) || (front == 0 && rear == SIZE - 1))
    {
        return 1; // implies queue is full
    }
    return 0;
}

int isEmpty()
{
    if (front == rear == -1)
        return 1; // implies queue is empty
    return 0;
}

void insert(int e)
{
    if (isFull())
    {
        printf("\nQueue is full");
        return;
    }
    if (rear == 0 && front == -1)
        front = 0;
    if (rear == SIZE - 1)
        rear = -1;
    arr[++rear] = e;
}

void delete ()
{
    int e;
    if (isEmpty())
    {
        printf("\nQueue is empty!");
        return;
    }
    e = arr[front];
    printf("\n%d is deleted from the queue", e);
    if (front > rear && front == SIZE - 1)
        front = 0;
    else if (front == rear)
        front = rear = -1;
    else
        front++;
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is empty!");
        return;
    }
    printf("\nQueue elements are: ");
    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d  ", arr[i]);
        }
    }
    else
    {
        for(i = front; i < SIZE; i++)
        {
            printf("%d  ", arr[i]);
        }
        for(i = 0; i <= rear; i++)
        {
            printf("%d  ", arr[i]);
        }
    }
}

int main()
{
    while (1)
    {
        choice();
        printf("\n---------------------------------------------------------");
    }   
}