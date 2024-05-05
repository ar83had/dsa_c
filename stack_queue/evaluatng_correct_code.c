#include<stdio.h>
#include<stdlib.h>
int top=-1;
int stack[20];

char* postfix(char[]);
void push(int);
int pop();
int priority(char);
int evaluation(char[]);

int main()
{
    char ch;
	do
	{
		char infix[20];
		printf("\nenter expression :");
		scanf("\n");
		scanf("%[^\n]s",&infix);
		
		printf("\ninfix-->");
		for(int c1=0;infix[c1]!=0;c1++)
			printf("%c",infix[c1]);
			
		char* post = postfix(infix);
		printf("\npostfix-->");
		for(int c1=0;post[c1]!=0;c1++)
			printf("%c",post[c1]);
			
		int re=evaluation(post);
		printf("\nresult-->%d",re);
			
		printf("\nagain(y/n):");
		scanf("\n%c",&ch);
	}while(ch=='y');
	
	printf("end");
	return 0;
}

void push(int el)
{
    if(top == 19)
    {
        printf("\nSTACK OVERFLW !!!");
        return;
    }
    
    stack[++top]=el;
    return;
}

int pop()
{
    if(top==-1)
    {
        printf("\nUNDERFLOW !!!");
        return -1;
    }
    return stack[top--];
}

char* postfix(char arr[])
{
    char* post=(char*)malloc(sizeof(char)*20);
    int c1=0,index=0;
    while(arr[c1]!=0)
    {
        if(arr[c1]=='(')
             push(arr[c1]);
             
        else if(arr[c1]==')')
        {
            while(stack[top] != '(')
                post[index++]=pop();
            int temp=pop();
        }
            
        
        else if(arr[c1]=='*' || arr[c1]=='/' || arr[c1]=='+' || arr[c1]=='-' || arr[c1]=='%')
        {
            while(priority(arr[c1]) <= priority(stack[top]))
            {
                post[index++]=pop();
            }
            push(arr[c1]);
        }
        else
            post[index++]=arr[c1];
        c1++;    
    }
    
    while(top!=-1)
        post[index++]=pop();
        
    return post;
}

int priority(char el)
{
    switch(el)
    {
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
        default:
            return -1;
    } 
}

int evaluation(char post[])
{
    int c1=0,a,b;
    while(post[c1]!=0)
    {
        switch(post[c1])
        {
            case '+':
                a= pop();
                b = pop();
                push(a+b);
                break;
            case '-':
                a= pop();
                b = pop();
                push(b-a);
                break;
            case '*':
                a= pop();
                b =pop();
                push(b*a);
                break;
            case '/':
                a= pop();
                b = pop();
                push(b/a);
                break;
            case '%':
                a= pop();
                b = pop();
                push(b%a);
                break;
            default:
                push((post[c1]-'0'));
        }
        c1++;
    }

   return pop();
}
