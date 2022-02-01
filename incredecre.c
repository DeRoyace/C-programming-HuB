#include <stdio.h>
int main()
{
    // int i=10;
    // printf("%d  %d  %d  %d  %d\n", ++i, i++, i--, --i, ++i);
    // // the above increment decrement is done from right to left

    // //Code 2:
    // int a =8,b;
    // b= a++;
    // printf("a = %d, b = %d\n", a, b);

    // //Code 3:
    // int a=8,b=7,c;
    // c = ++a * b--;
    // printf("a = %d, b = %d, c = %d\n", a, b, c);

    // code 4:
    int a = 1, b = 2, c = 3, d;
    d = --a * b++ + c--;
    printf("a = %d, b = %d, c = %d,  d = %d\n", a, b, c, d);

    // code 5:
    int x = 60;
    printf("%o", x);
    printf("%x", --x);

    return 0;
}