// Q. Write a program to print natural numbers from 10 to 20 when initial loop counter i=0.

#include<stdio.h>

int main()
{
    int i=0;
    while(i<=20)
    {
        if(i>=10)
            printf("%d\n",i);
        i++;
    }
    return 0;
}