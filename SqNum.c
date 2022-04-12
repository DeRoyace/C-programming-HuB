#include<stdio.h>
int main()
{
	double num;
	printf("\nEnter any number: ");
	scanf("%lf", &num);
	printf("The square of %.2lf is : %.2lf\n", num, num*num);
	return 0;

}
