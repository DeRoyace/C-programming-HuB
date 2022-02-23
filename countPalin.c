#include <stdio.h>
#include <string.h>

int isPalin(char str[])
{
    int i, j = 0, len = strlen(str);
    char rev[len];
    for (i = len - 1; i >= 0; i--)
    {
        rev[j] = str[i];
        j++;
    }
    // printf("%d", strncmp(str, rev, len) );
    return (strncmp(str, rev, len) == 0);
}

int countPalin(char str[])
{
    int i, j=0, count=0;
    char ch, temp[30];
    for(i=0; i< strlen(str); i++)
    {
        ch=str[i];
        if(ch!=' ')
        {
            temp[j++]=ch;
        }
        else
        {
            temp[j]='\0';
            if(isPalin(temp))
            {
                count++;
            }
            strcpy(temp,"");
            j=0;
        }
    }
    return count;
}

int main()
{
    char s[100];
    printf("\nEnter a String : ");
    scanf("%[^\n]", s);
    printf("Your string is : %s\n", s);
    printf("No. of palindromic words: %d\n", countPalin(s));
    return 0;
}