#include <stdio.h>
#include <string.h>

int isPalin(char str[])
{
    int i, flag = 0, j = 0, len = strlen(str);
    char rev[len];
    for (i = len - 1; i >= 0; i--)
    {
        rev[j] = str[i];
        j++;
    }
    rev[j]='\0';
    // for (i = 0; i < strlen(str); i++)
    // {
    //     if (str[i] != ch[i])
    //     {
    //         flag = 1;
    //         break;
    //     }
    // }
    printf("Reverse String is: %s\n", rev);
    return (strcmp(str, rev) == 0);
}

int main()
{
    char s[100];
    printf("\nEnter a String: ");
    scanf("%[^\n]", s);
    printf("Your string is : %s\n", s);

    if (isPalin(s))
        printf("Palindromic String\n");
    else
        printf("NOT a Palindromic String\n");
    return 0;
}