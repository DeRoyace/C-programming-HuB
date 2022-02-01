#include<stdio.h>

int main()
{
    int a=5;
    a= ++a - a++;
    printf(" %d %d  %d", a,a++,++a);
    return 0;
}