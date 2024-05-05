#include<stdio.h>

void prime_fac(int,int);
int prime(int,int);

int main()
{
    int n;
    printf("\nenter the number :");
    scanf("%d",&n);

    printf("\nprime factore :-\n");
    prime_fac(n,2);
    return 0;
}

void prime_fac(int num,int div)
{
    if(num == 1)
        return;

    int pri = prime(div,2);

    if(num % div == 0)
    {
        printf("%d * ",div);
        prime_fac(num/div,2);
    }
    else
        prime_fac(num,++div);
        
    return;
}

int prime(int num,int div)
{
    if(div == num-1)
        return num;
    else if(num%div==0)
        num = prime(num+1,2);
    num = prime(num,div+1);
    return num;
}