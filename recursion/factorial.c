#include<stdio.h>

long int fac(long int);

long int main()
{
    printf("enter the number :");
    long int num;
    scanf("%ld",&num);

    long int re = fac(num);
    printf("-->%ld",re);
    return 0;
}

long int fac(long int num)
{
    if(num == 0)
        return 1;

    return (num * fac(num-1));
}