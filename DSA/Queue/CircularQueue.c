// Implementation of Circular Queue.
#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int arr[SIZE], front = -1, rear = -1;

void choice() // menu driven choice function to perform queue operations via user choice inputs
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
    printf("\n4: Clear queue");
    printf("\n5: Exit");
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
        front = rear = -1;
        printf("\nYour Circular Queue is clear now!");
        break;

    case 5:
        exit(0);
        break;

    default:
        printf("\nInvalid choice entered.");
    }
} // end of choice()

int isFull() // function to check whether queue is full or not
{
    if ((front == rear + 1 && front < SIZE) || (front == 0 && rear == SIZE - 1))
    {
        return 1; // implies queue is full
    }
    return 0;
}

int isEmpty() // function to check whether the queue is empty or not
{
    if (front == rear == -1)
        return 1; // implies queue is empty
    return 0;
}

void insert(int e) // function to insert queue elements
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
} // end of insert()

void delete () // function to delete queue elements from front end
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
} // end of delete()

void display() // displays queue elements
{
    // actually this function displays elements between front and rear index.
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
        for (i = front; i < SIZE; i++)
        {
            printf("%d  ", arr[i]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d  ", arr[i]);
        }
    }
} // end of display()

int main()
{
    // running the choice() until the program is terminated by the user (via choice option 5: Exit);
    while (1)
    {
        choice();
        printf("\n---------------------------------------------------------");
    }
} // end of main()