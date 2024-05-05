#include<stdio.h>
#include<stdlib.h>

// incomplete and not working code;

int validation(char[]);
void push(char[],char,int*);
int pop(char[],int*);
char* postfix(char[]);
int priority(char);

int main()
{
    char infix[20];
    printf("\nenter expretion :");
    scanf("%[^\n]s",infix);

    int is_valid = validation(infix);

    if(!is_valid)
    {
        printf("\nINVALID VALID EXPRESSION");
        return 0;
    }

    char* post=postfix(infix);

    int c1=0;
    while(post[c1] != 0)
    {
        printf("%c",*(post+c1));
        c1++;
    }

    return 0;
}

int validation(char arr[])
{
    int c1=0;
    char stack[20];
    int top=-1;
    while(arr[c1] != 0)
    {
        printf("j");
        if(arr[c1] == '(' || arr[c1] == '[' || arr[c1] == '{')
        {
            push(stack,arr[c1],&top);
        }

        else if(arr[c1]==')' || arr[c1]=='}' || arr[c1]==']')
        {
            if(top == -1)
            {
                printf("\nRIGHT BRACKET EXCADE");
                return 0;
            }

            char el = pop(stack,&top);
            int flag=1;
            if(el=='[' && arr[c1]!=']')
                flag=0;
            else if(el=='{' && arr[c1]!='}')
                flag=0;
            else if(el=='(' && arr[c1] != ')')
                flag=0;
            
            if(!flag)
            {
                printf("\nBRACKET MISMATCH!!");
                return 0;
            }
        }
        c1++;
    }
    if(top != -1)
    {
        printf("\nlift bracket excade !");
        return 0;
    }

    return 1;
}

void push(char stack[],char el,int* top)
{
    if(*top == 19)
        printf("\nOVERFLOW !!!");

    else
        stack[++(*top)]=el;
    return;
}

int pop(char stack[],int* top)
{
    if(*top == -1)
        printf("\nunderflow !!!");
    
    else
        return stack[(*top)--];

    return -1;
}

char* postfix(char infix[])
{
    char* post=(char*)malloc(20);
    char stack[20];

    int c1=0,top=-1,c2=0;
    while(infix[c1] != 0)
    {
        if(infix[c1]=='+' || infix[c1]=='-' || infix[c1]=='*' || infix[c1]=='%' || infix[c1]=='/' || infix[c1] =='(')
        {
            while(top != -1 && priority(infix[c1]) <= stack[top])
                *(post+(c2++)) = pop(stack,&top);
            push(stack,infix[c1],&top);
        }

        else if(infix[c1]==')')
        {
            while(stack[top] != '(' )
                post[c2++]=pop(stack,&top);
            top--;
        }

        else if(infix[c1] >= 48 && infix[c1] <=57 || infix[c1] >= 65 && infix[c1]<= 91 || infix[c1]>=97 && infix[c1]<=123)
        {
            push(post,infix[c1],&c2);
        }

        else
            printf("\nonly alphanumaric allow !!");
        
        c1++;
    }
    post[c2]='\n';
    return post;
}

int priority(char el)
{
    switch(el)
    {
        case'+':
        case'-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '(':
            return 0;
    }
    return -1;
}