#include<stdio.h>
int main()
{
    int a=2,b=7;
    b=b^a;
    a=a^b;
    printf("a = %d   b = %d \n",a,b);
    return 0;
}