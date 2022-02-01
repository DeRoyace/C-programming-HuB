#include<stdio.h>

void main()
{
    int M,N;
    printf("\nEnter the lower limit : ");
    scanf("%d", &M);

    printf("Enter the upper limit : ");
    scanf("%d", &N);

    if( M>N || M==N || M<1 || M>100 || N<1 || N>100)
    {
        printf("\nInvalid input. Enter the inputs again -->");
        main();
    }
    else
    {
        printf("The even numbers are : ");
        for ( int i = M; i < N; i++)
        {
            /* code */
            if(i%2==0)
                printf("%d, ", i);
        }
        
    }
}