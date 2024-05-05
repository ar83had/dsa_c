#include<stdio.h>

int hcf(int,int,int);

int main()
{
    int n1,n2;
    printf("\nenter the number 1 :");
    scanf("%d",&n1);
    printf("\nenter the value 2 :");
    scanf("%d",&n2);

    int min = (n1>n2)?n2:n1;
    int re = hcf(n1,n2,min);
    printf("H.C.F of %d and %d is %d",n1,n2,re);

    return 0;
}

int hcf(int n1,int n2,int min)
{
    if(min == 1)
        return 1;
    else if(n1%min==0 && n2%min==0)
        return min;
    int re = hcf(n1,n2,--min);
    return re;
}