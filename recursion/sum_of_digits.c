#include<stdio.h>

int sum(int);

int main()
{
    int n;
    printf("\nenter the number :");
    scanf("%d",&n);

    int re = sum(n);
    printf("\b\b\b = %d",re);

    return 0;
}

int sum(int n)
{
    if(n == 0)
        return n;

    int re = n%10 + sum(n/10);

    printf("%d + ",n%10);
    return re;
}