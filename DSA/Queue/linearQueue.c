// Implemetation of Linear Queue using Arrays.

#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int arr[SIZE], front = -1, rear = -1;

void choice() // menu driven choice function to perform queue operations via user choice inputs
{
    int ch, val;
    void insert(int);
    void delete();
    void display();
    printf("\n1: Insert elements");
    printf("\n2: Delete elements");
    printf("\n3: Display elements");
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
        delete();
        break;

    case 3:
        display();
        break;

    case 4:
        front = rear = -1;
        printf("\nYour queue is clear now!");
        break;

    case 5:
        exit(0);
        break;

    default:
        printf("\nInvalid choice entered.");
    }
} // end of choice()

void insert(int e) // function to insert queue elements
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

void delete() // function to delete queue elements from front end
{
    int e;
    if (front == rear)
    {
        front = rear = -1;
        printf("\nQueue is empty!");
        return;
    }
    e = arr[front++];
    printf("\n%d is removed from the Queue", e);
} // end of delete()

void display() // displays queue elements
{
    // actually this function displays elements between front and rear index.
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
} // end of display()

int main()
{
    while (1)
    {
        choice();
        printf("\n----------------------------------------------------");
    }
} // end of main()