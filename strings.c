#include<stdio.h>
// #include<string.h>
int main()
{
    char ch[100];
    printf("\nEnter your name: ");
    scanf("%[^\n]", ch); // will take input until we press enter
    // scanf("%[^\Z]", ch); // will take input until i press Z
    printf("Your string is : %s\n",ch);
    return 0;
}