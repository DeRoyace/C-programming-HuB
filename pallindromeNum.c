#include <stdio.h>

int ispalin(int x)
{
    int rev = 0, d, num = x;
    while (x > 0)
    {
        d = x % 10;
        rev = rev * 10 + d;
        x /= 10;
    }
    return (num == rev);
}

int main()
{
    int n;
    printf("\nEnter any number: ");
    scanf("%d", &n);

    if (ispalin(n))
        printf("%d is Palindrome Number.\n", n);
    else
        printf("Not a palindrome number.\n");
    return 0;
}
