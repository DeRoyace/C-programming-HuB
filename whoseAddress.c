#include<stdio.h>

int main()
{
    int a = 2, *ptr1, *ptr2;
    ptr1 = ptr2 = &a;

    printf("\n Value of ptr1 = %d", ptr1);
    printf("\n Value of ptr2 = %d", ptr2);
    
    printf("\n Value of &ptr1 = %d", &ptr1);
    printf("\n Value of &ptr2 = %d", &ptr2);

     printf("\n Value of *ptr1 = %d", *ptr1);
    printf("\n Value of *ptr2 = %d\n", *ptr2);
    return 0;
}