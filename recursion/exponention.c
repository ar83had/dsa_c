#include<stdio.h>

int pow(int,int);

int main()
{
    int base,power;
    printf("\nenter the base :");
    scanf("%d",&base);
    printf("\nenter the power :");
    scanf("%d",&power);

    int re=pow(base,power);
    printf("%d^%d --> %d",base,power,re);
    return 0;
}

int pow(int base,int power)
{
    if(power == 0)
        return 1;
    
    return base * pow(base,power-1);
}