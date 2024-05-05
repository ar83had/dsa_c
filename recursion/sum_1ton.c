#include<stdio.h>

int series(int);

int main()
{
    int n;
    printf("\nenter the number :");
    scanf("%d",&n);

    int re = series(n);
    printf("\b\b\b = %d",re);
    return 0;
}

int series(int n)
{
    if(n==0)
        return 0;
int sum = n + series(n-1);

printf("%d + ",n);
return sum;
}