#include<stdio.h>

void display1(int);     // 1 to n;
void display2(int);     // 10 to 1;

int main()
{
    int n;
    printf("\nenter the number :");
    scanf("%d",&n);

    printf("\n 1 to %d ",n);
    display1(n);   

    printf("\n%d to 1",n);     
    display2(n);

    return 0;
}

void display1(int n)
{
    if(n == 0)
        return;
    display1(n-1);
    printf("\n->%d",n);
    return;
}

void display2(int n)
{
    if(n==0)
        return;
    
    printf("\n->%d",n);

    display2(n-1);
    return;
}