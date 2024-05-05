#include"tree.h"
char char_stack[20];

char* postfix(char*);
void push_char(char);
char pop_char();
char* postfix(char[]);
int priority(char);
tree* postfix_tree(char[]);
void display_inorder(tree*);

int main()
{
    char infix[20];
    printf("\nenter infix charcter  :\n");
    scanf("%[^\n]s",infix);

    char* post = postfix(infix);
    tree* root= postfix_tree(post);
    display_inorder(root);
    
}

void push_char(char el)
{
    if(top == 19)
    {
        printf("\nSTACK OVERFLW !!!");
        return;
    }
    
    char_stack[++top]=el;
    return;
}

char pop_char()
{
    if(top==-1)
    {
        printf("\nUNDERFLOW !!!");
        return -1;
    }
    return char_stack[top--];
}

char* postfix(char arr[])
{
    char* post=(char*)malloc(sizeof(char)*20);
    int c1=0,index=0;
    while(arr[c1]!=0)
    {
        if(arr[c1]=='(')
             push_char(arr[c1]);
             
        else if(arr[c1]==')')
        {
            if(top==-1)
                printf("\nright bracket excided !");

            else
            {
            while(char_stack[top] != '(')
                post[index++]=pop_char();
            int temp=pop_char();
            }
        }
            
        
        else if(arr[c1]=='*' || arr[c1]=='/' || arr[c1]=='+' || arr[c1]=='-' || arr[c1]=='%')
        {
            while(priority(arr[c1]) <= priority(char_stack[top]))
            {
                post[index++]=pop_char();
            }
            push_char(arr[c1]);
        }
        else
            post[index++]=arr[c1];
        c1++;    
    }
    
    while(top!=-1)
        post[index++]=pop_char();
        
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

tree* postfix_tree(char post[])
{
    for(int c1=0;post[c1]!=0;c1++)
    {
        tree* node = (tree*)malloc(sizeof(tree));
        if(post[c1]=='+' || post[c1]=='-' || post[c1]=='/' || post[c1]=='%' || post[c1]=='*')
        {
            tree* b = pop();
            tree* a = pop();
            node->data=post[c1];
            node->lchild = a;
            node->rchild = b;
            push(node);
        }
        else
        {
            node->data=post[c1];
            node->lchild=NULL;
            node->rchild=NULL;
            push(node);
        }
    }
    return pop();
}

void display_inorder(tree* root)
{
    if(root==NULL)
        return;
    
    display_inorder(root->lchild);
    printf("%c",root->data);
    display_inorder(root->rchild);

    return;
}