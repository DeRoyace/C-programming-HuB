#include <iostream>
#include <string.h>
using namespace std;
void reverse(char *str) // function to reverse the string
{
    int i, j = 0, len = strlen(str);
    char rev[30];
    for (i = len - 1; i >= 0; i--)
    {
        rev[j] = *(str + i);
        j++;
    }
    rev[j] = '\0';
    strcpy(str, rev);
} //end of reverse()

int main()
{
    char cinnum[30];
    cout << "\nEnter your CIN Number: ";
    cin >> cinnum;
    reverse(cinnum);
    cout << "Reversed CIN number is: " << cinnum << endl;
    return 0;
} //end of main()
