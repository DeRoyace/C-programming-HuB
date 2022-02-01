// Q. Write a program to print multiplication table of number N (Nx1 TO Nx10).

#include<stdio.h>
int main()
{
    int N,i=0;
    printf("\nEnter the number whose table to be displayed : ");
    scanf("%d", &N);
    printf("\nThe multiplication table of %d is :", N);
    do{
        i++;
        printf("\n%d x %d = %d",N,i, N*i);
    }while(i<10);
    return 0;
}