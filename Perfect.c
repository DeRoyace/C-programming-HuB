#include<stdio.h>
int sum_divs(int x, int i)
{
	if(i==x)
		return 0;
	else if(x%i == 0)
		return i + sum_divs(x, i+1);
	else
		return sum_divs(x,i+1);
}

int main()
{
	int low, upp, i;
	printf("\nEnter lower limit: ");
	scanf("%d", &low);
	printf("Enter upper limit: ");
        scanf("%d", &upp);
	printf("\nThe perfect numbers are (if present) : ");
	for(i = low; i<=upp; i++)
	{
		if(i == sum_divs(i,1))
			printf("%d, ", i);
	}
	printf("\n");
	return 0;
}

