#include<stdio.h>

//first application stack "REVERSING A STRING ";
//first push string character into stack and then pop charcter from stack and store into string;

char stack[20];
int top=-1;

void push(char);
char pop();
void display(char[]);

int main()
{
    char name[20];
    printf("enter your name :");
    gets(name);

    printf("\nbefore reversing....");
    display(name);
    int c1=0;
    while(name[c1] != 0)
        push(name[c1++]);

    c1=0;

    while(name[c1]!=0)
        name[c1++] = pop();
    printf("\nafter reverseng....");
    display(name);

    return 0;

}

void push(char ch)
{
    if(top == 19)
        printf("\nSTACK OVERFLOW !!!");
    else
        stack[++top] = ch;
    return;
}

char pop()
{
    if(top == -1)
        printf("\nSTACK UNDERFLOW !!!");
    else
        return stack[top--];
    return 0;
}

void display(char name1[])
{
    int c1=0;
    printf("\n");
    while(name1[c1] != 0)
        printf("%c",name1[c1++]);
    return;
}