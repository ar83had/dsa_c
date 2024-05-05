#include<stdio.h>

void string_rec(char*);

int main()
{
    char name[20];
    for(int c1=0;c1<6;c1++)
    {
        printf("\nenter string :");
        scanf("\n");
        scanf("%[^\n]s",name);
        printf("\n");
        string_rec(name);
    }
    return 0;
}

void string_rec(char * str)
{
    if(*(str) == 0)
        return;
    
    printf("%c",*(str));
    string_rec(str+1);
}