#include<stdio.h>

int summation(int);

int main()
{
    int n;
    printf("\nenter number :");
    scanf("%d",&n);

    int re = summation(n);
    printf("\n-->%d",re);

    return 0;
}

int summation(int n)
{
    if(n==1)
        return 1;

    return (n + summation(n-1));
}