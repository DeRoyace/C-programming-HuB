#include<stdio.h>
int main()
{
    int *ptr1, *ptr2, a, b;
    printf("\nEnter two numbers : ");
    printf("\n a = ");
    scanf("%d",&a);
    printf("\n b = ");
    scanf("%d",&b);
    
    ptr1=&a;
    ptr2=&b;

    printf("\nPointer value is(*d) : %d", *ptr1);
    printf("\nPointer value is(d) : %d", ptr1);
    printf("\nAddress of %d is : %d", a, &ptr1);
    printf("\nAddress of %d is : %d\n", b, &ptr2);

    printf("\nPointer value is(*o) : %o", *ptr1);
    printf("\nPointer value is(o) : %o", ptr1);
    printf("\nAddress of %d is : %o", a, &ptr1);
    printf("\nAddress of %d is : %o\n", b, &ptr2);

    printf("\nPointer value is(*f) : %f", *ptr1);
    printf("\nPointer value is(f) : %f", ptr1);
    printf("\nAddress of %d is : %f", a, &ptr1);
    printf("\nAddress of %d is : %f\n", b, &ptr2);

    printf("\nPointer value is(*x) : %x", *ptr1);
    printf("\nPointer value is(x) : %x", ptr1);
    printf("\nAddress of %d is : %x", a, &ptr1);
    printf("\nAddress of %d is : %x\n", b, &ptr2);

    printf("\nHexa value : %x",a);
    printf("\nOctal Value: %o\n",a);
    return 0;
}