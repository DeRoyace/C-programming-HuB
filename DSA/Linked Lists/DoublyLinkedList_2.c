// Implementing Doubly Linked List using head and tail pointers.

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int key;
    struct list *next, *prev;
} NODE;

NODE *head = NULL, *tail = NULL;

void insert_first(int val)
{
    NODE *n = (NODE *)malloc(sizeof(NODE)), *p = head;
    n->prev = NULL;
    n->key = val;
    if (!head)
    {
        head = n;
        tail = n;
        n->next = NULL;
        return;
    }
    n->next = p;
    p->prev = n;
    head = n;
}

void insert_last(int val)
{
    NODE *n = (NODE *)malloc(sizeof(NODE)), *p = tail;
    n->next = NULL;
    n->key = val;

    if (!head)
    {
        head = n;
        tail = n;
        n->prev = NULL;
        return;
    }
    p->next = n;
    n->prev = p;
    tail = n;
}

void insert_pos(int val, int pos)
{
    NODE *n = (NODE *)malloc(sizeof(NODE *));
    n->key = val;
    if (!head)
    {
        head = n;
        tail = n;
        n->prev = NULL;
        printf("\nSince the list is empty the given position is invalid.\nTherefore, the element is placed as the first and the only element in the list.");
        return;
    }
    int i;
    NODE *p = head;
    for (i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    n->next = p->next;
    n->prev = p;
    p->next->prev = n;
    p->next = n;
}

int delete_first()
{
    int val;
    if (!head)
    {
        printf("\nList is empty!");
        return;
    }
    val = head->key;
    head = head->next;
    return val;
}

int delete_last()
{
    int val = tail->key;
    tail->prev->next = NULL;
    tail = tail->prev;
}

int delete_pos(int pos)
{
    int val, i;
    NODE *p = head;
    if (pos == 1)
        val = delete_first();
    else
    {
        for (i = 1; i < pos - 1; i++)
            p = p->next;
        val = p->next->key;
        p->next->prev = NULL;
        p->next->next->prev = p;
        p->next = p->next->next;
    }
    return val;
}

void display(NODE *start, int i)
{
    if (!head)
    {
        printf("\nList is empty!");
        return;
    }

    NODE *p = start;
    if (i)
    {
        do
        {
            printf("%d  ", p->key);
            p = p->next;
        } while (p);
    }
    else
    {
        do
        {
            printf("%d  ", p->key);
            p = p->prev;
        } while (p);
    }
}

void choice()
{
    int ch, val;
    printf("\n1: Insert\n2: Display\n3: Reverse display\n4: Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nEnter element to be inserted: ");
        scanf("%d", &val);
        insert_last(val);
        break;

    case 2:
        display(head, 1);
        break;

    case 3:
        display(tail, 0);
        break;

    case 4:
        exit(1);

    default:
        printf("\nInvalid choice!");
    }
}

int main()
{
    while (1)
    {
        choice();
        printf("\n---------------------------------------\n");
    }
    return 0;
}