#include <stdio.h>
#define SWAP(a, b)  a=a+b, b=a-b, a=a-b
// swapping two numbers without using any extra variable

int main()
{
    int x = 2, y = 3;
    SWAP(x, y);
    printf("%d  , %d\n", x, y);
    return 0;
}