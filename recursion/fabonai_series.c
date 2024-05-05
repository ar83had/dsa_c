#include<stdio.h>

void fabo(int,int,int,int);

int main()
{
    int n;
    printf("\nenter the number :");
    scanf("%d",&n);

    printf("1 + 1 +");
    fabo(1,1,n,3);
    printf("\b\b\b   ");

    return 0;
}

void fabo(int first,int sec,int n,int c1)
{
    if(c1 == n)
        return;

    printf("%d + ",first+sec);
    fabo(sec,first+sec,n,++c1);
    return;
}
