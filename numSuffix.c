#include<stdio.h>
// char* is a return type for string values
char* suffix(int x) // function to return suffix of number in string form
{
    if (x==1 || x==21 || x==31)
        return "st";
    else if (x==2 || x==22)
        return "nd";
    else if(x==3 || x==23)
        return "rd";
    else
        return "th";
    
}
void main()
{
    int n;
    printf("\nEnter any positive number : ");
    scanf("%d", &n);

    if (n<0 || n>31)
    {
        printf("\nInvalid input! Enter the value again -->");
        main(); // calls the main() function again
    }
    else
    {
        printf("Your output is : %d", n);
        puts(suffix(n)); // shows the suffix of the number
        
    }
} // end of main()
