int fact(int x)
{
    if(x==1 || x==0)
    return 1;
    else
    return x * fact(x-1);
}

int isSpecial(int x)
{
    int sum=0,n=x;
    while(x)
    {
        sum+=fact(x%10);
        x/=10;
    }

    if(sum==n)
        return 1;
    return 0;
}