#include<stdio.h>
char stack[50],infix[50],postfix[50];
int top=-1;

void display(char[]);
void infix_to_postfix();
void push(char);
int pop();
int priority(char);
char result();

int main()
{
    int ch;
    do
    {

        printf("\n1)postfix notation\n2)evalutate expression\nenter your choice :");
        scanf("%d",&ch);
        printf("\nenter the inflix :");
        scanf("\n");
        gets(infix);

        switch(ch)
        {
            case 1:
                infix_to_postfix();
                display(infix);
                display(postfix);
                break;
            case 2:
                infix_to_postfix();
                char re = result();
                display(infix);
                printf("= %d",re);
                break;
        }

    } while(ch < 3);
    
    return 0;
}

void display(char arr[])
{
    printf("\n--->");
    int c1=0;
    while(arr[c1] != 0)
    {
        printf("%c",arr[c1++]);
    }
    return;
}

void infix_to_postfix()
{
    int c1=0,c2=0;
    char temp;
    while(infix[c1] != 0)
    {
        switch(infix[c1])
        {
            case '(':
                push(infix[c1]);
                break;
            case ')':
                while((temp = pop()) != '(')
                {
                    postfix[c2++]=temp;
                    printf("");
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                while(top != -1 && priority(infix[c1]) <= priority(stack[top]))
                {
                    postfix[c2++] = pop();
                }
                push(infix[c1]);
                break;
            default:
                postfix[c2++]=infix[c1];
        }
        c1++;
    }
    while(top != -1)
    {
        postfix[c2++]=pop();
    }
}

void push(char el)
{
    if(top == 49)
    {
        printf("\nSTACK OVERFLOW !!!");
        return;
    }

    stack[++top]=el;
    return;
}

int pop()
{
    if(top == -1)
    {
        printf("\nSTACK UNDERFLOW !!!");
        return -1;
    }

    return stack[top--];
}

int priority(char el)
{
    switch(el)
    {
        case '+':
        case '-':
            return 1;
        case '/':
        case '*':
        case '%':
            return 2;
    }
    return -1;
}

char result()                                                 //this funcation doest not work
{                                                              //tere logic was correct but type casting problem arrise;
    int c1=0;                                                   //so follow book method for seloving ghis question;
    while(postfix[c1] != 0)
    {
        char temp=postfix[c1];                          ///the game of assivalue;
        switch(temp)
        {
            case '+':
                temp=(pop()-'0')+(pop()-'0') + '0';
                break;
            case '-':
                temp=(pop()-'0')-(pop()-'0') + '0';
                break;
            case '*':
                temp=(pop()-'0') * (pop()-'0') + '0';
                break;
            case '/':
                temp=(pop()-'0')/(pop()-'0')+'0';
                break;
            case '%':
                temp=(pop()-'0')%(pop()-'0') + '0';
                break;
        }
        push(temp);
        display(stack);
        c1++;
    }
    return pop();
}