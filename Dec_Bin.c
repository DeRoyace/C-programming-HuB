#include<stdio.h>
int bin(int x)
{
	if(x==0 || x==1)
		return x;
	else
		return x%2 + 10*bin(x/2);
}

int main()
{
	int num;
	printf("\nEnter any number: ");
	scanf("%d", &num);
	printf("Binay form: %d\n", bin(num) );
	return 0;
}
