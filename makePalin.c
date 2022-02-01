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
    return (strncmp(str, rev, len) == 0);
}

void makePalin(char *str)
{
    int i, flag = 0, j = 0, len = strlen(str);
    char rev[len];
    for (i = len - 1; i >= 0; i--)
    {
        rev[j] = *(str + i);
        j++;
    }
    rev[j] = '\0';
    strcat(str,rev);
    // strcpy(str, rev);
}

void changeString(char str[])
{
    int i, j = 0;
    char ch, temp[30], newstr[100];
    strcpy(newstr,"");
    strcat(str," ");
    for (i = 0; i < strlen(str); i++)
    {
        ch = str[i];
        if (ch != ' ')
        {
            temp[j++]= ch;
        }
        else
        {
            temp[j] = '\0';
            if (isPalin(temp) == 0)
            {
                makePalin(temp);
            }
            // newstr[j]+=temp[j];
            strcat(newstr, temp);
            // printf("%s", newstr);
            strcat(newstr, " ");
            strcpy(temp, "");
            j=0;
        }
    }
    strcat(newstr, "\0");
    printf("New String: %s\n", newstr);
}

int main()
{
    char s[100];
    printf("\nEnter a String: ");
    scanf("%[^\n]", s);
    printf("Your string is : %s\n", s);
    changeString(s);
    return 0;
}