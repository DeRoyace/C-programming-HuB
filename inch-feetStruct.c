// Write a Program to add two distances in the inch-feet system.
#include<stdio.h>

struct st
{
    int in;
    int ft;
}a[2];

int main()
{
    int i, sumft=0, sumIN=0;
    printf("\nEnter distance in inch-feet system : ");
    for(i=0; i<2; i++)
    {
        printf("\nFeet: ");
        scanf("%d", &a[i].ft);
        printf("Inch: ");
        scanf("%d", &a[i].in);

        sumft+=a[i].ft;
        sumIN+=a[i].in;
        printf("------------------------");

    }
    printf("\nSum of two distance is %d\' %d\" \n", sumft, sumIN);

    return 0;
}