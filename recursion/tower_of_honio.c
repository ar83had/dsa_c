#include<stdio.h>

void tower(int,char,char,char);

int main()
{
    char a='a',b='b',c='c';
    int n;
    printf("\nenter the number of disks :");
    scanf("%d",&n);

    tower(n,a,b,c);
    return 0;
}

void tower(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("\n%c-->%c",a,c);
        return;
    }

    tower(n-1,a,c,b);
    printf("\n%c-->%c",a,c);
    tower(n-1,b,a,c);
    return;
}