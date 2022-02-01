#include <stdio.h>
int countwords(char str[])
{
    int i, count = 0;
    char ch;
    for (i = 0; str[i]!='\0'; i++)
    {
        ch = str[i];
        if (ch == ' ' || ch=='\t')
            count++;
    }
    return count + 1;
}

int main()
{
    char s[100];
    printf("\nEnter a String : ");
    scanf("%[^\n]", s);
    printf("Your string is : %s\n", s);
    printf("Total no. of words: %d\n", countwords(s));
    return 0;
}