#include<stdio.h>

main()
{
    #line 10 "lineError.c"
    int a=10:
    #line 20 
    printf("%d", a);
}