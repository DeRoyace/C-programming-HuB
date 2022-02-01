#include<stdio.h>

int countDigits(int x)
{
    if(x<10)
    return x;
    else 
    return 1+countDigits(x/10); 
}

int sod(int x)
{
    if(x<10)
    return x;
    else
    return x%10 + sod(x/10);
}

int main()
{
    int dob;
    printf("\nEnter your birth date in 8-digit(mmddyyyy) format: ");
    scanf("%d", &dob);
    printf("%d", countDigits(dob));
    if(countDigits(dob)==8)
    {
        printf("Sum of Digits of you DOB : %d\n", sod(dob));
    }
    else
    {
        printf("Invalid Input.\n");
        // main();
    }
    return 0;
}