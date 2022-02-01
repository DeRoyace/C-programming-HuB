//  Program to display those words that has ODD number of vowels.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i, count = 0, j=0;
    char ch, temp[20];
    char *s = (char *)malloc(sizeof(char) * 100);
    printf("Enter any sentence: ");
    scanf("%[^\n]", s);
    printf("Output: %s\n", s);
    strcat(s," ");
    for (i = 0; i < strlen(s); i++)
    {
        ch = *(s + i);
        if (ch != ' ')
        {
            switch (ch)
            {
            case 'a':
            case 'A':

            case 'e':
            case 'E':

            case 'i':
            case 'I':

            case 'o':
            case 'O':

            case 'u':
            case 'U':

                count++;
                break;

            default:
                break;
            }
            temp[j++]=ch;
        }
        else
        if (ch == ' ')
        {
            temp[j]='\0';
            if(count%2!=0)
            printf("%s -> %d\n", temp, count);
            j=count=0;
        }
    }
    free(s);
    return 0;
}