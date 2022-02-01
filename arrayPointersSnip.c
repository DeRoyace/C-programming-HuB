#include <stdio.h>

int main()
{
    int a[] = {10, 20, 30, 40, 50}, *p;
    p = a;
    printf("%d\n", *p++);
    printf("%d\n", *++p);
    printf("%d\n", ++*p);
    return 0;
}