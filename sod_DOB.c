#include<stdio.h>

int sod(int x) // recursive function to compute sum of digits
{
    if(x < 10)
        return x;
    else
        return x % 10 + sod(x/10);
}

int main()
{
    int dob;
    printf("\nEnter your birth date in 8-digit(mmddyyyy) format: ");
    scanf("%d", &dob);
    printf("Sum of Digits of your DOB is : %d\n", sod(dob));
    return 0;
}