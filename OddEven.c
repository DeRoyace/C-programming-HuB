#include<stdio.h>

int main()
{
    int a[10],i,s1,s2;
    for(i=0; i<10; i++)
    {
        printf("Enter number %d : ", i+1);
        scanf("%d", &a[i]);
    }
    for(i=0, s1=s2=0; i<10; i++)
    {
        if(a[i]%2)  // this condition implies it is not equal to 0
            s1+=a[i]; // sum of odds
        else
            s2+=a[i]; // sum of evens
    }
    printf("\nSum of odd numbers = %d", s1);
    printf("\nSum of even numbers = %d \n", s2);
    return 0;
}