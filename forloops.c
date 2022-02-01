#include<stdio.h>

int main()
{
    int x,y;
    for(x=10, y=10; y; x++,y--)
        printf(" %d  %d\n",x,y);
    return 0;
}

// void main()
// {
// 	int x=1,y=1;
// 	clrscr();
// 	for(;y; printf("%d %d", x,y)
// 		y=x++ <=5; ===> [if x<=5 then x=x+1]
// 	getch();
// }

// output:
// 2 1
// 3 1
// 4 1
// 5 1
// 6 1
// 7 0  ===> [x>5 so y=0]