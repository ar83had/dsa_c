#include<stdio.h>

//another applocation of stack;

char stack[10];
int top=-1;

void push(char);
char pop();
void check(char[]);
int para_check(char,char);

int main()
{
    char exp[20];
    printf("\nenter the expression :");
    gets(exp);

    check(exp);
    return 0;
}

void check(char exp[])
{
    int c1=0;
    while(exp[c1] != 0)
    {
        char el=exp[c1];
        if(el == '(' || el == '{' || el == '[')
        {
            push(el);
        }
        else if(el == ')' || el=='}' || el==']')
        {
            if(top==-1)
            {
                printf("\nINVALID(right parantheses > left paranthese)");
                return;
            }
            else
            {
                char st_el = pop();
                if(!para_check(st_el,el))
                {
                    printf("\nINVALID(paranthese mismatch)");
                    return;
                }
            }
        }
        c1++;
    }

    if(top == -1)
        printf("\nVALID expression");
    else
        printf("\nINVALID(left paramthese > left parasnthese)");
}

void push(char el)
{
    if(top == 9)
        printf("\nSTACK OVERFLOW !!!");
    else
        stack[++top]=el;
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

int para_check(char left,char right)
{
    if(left=='(' && right==')' ||left == '{' && right=='}' ||left == '[' && right==']')
        return 1;
    return 0;
}