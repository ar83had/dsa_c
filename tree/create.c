#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list* next;
}list;

typedef struct tree 
{
    int data;
    struct tree* lchild,*rchild;
}tree;

tree* stack[20];
int top=-1;
list* linked_list(list*,int);
void display_list(list*);
tree* create_tree(list*,list*,int);
void travertion_preorder(tree*);
void push(tree*);
tree* pop();

int main()
{
    list* inorder=NULL,*postfix=NULL;
    tree* root=NULL;
    int n;
    printf("\nenter number of node :");
    scanf("%d",&n);
    printf("\ninorder nodes:-");
    inorder = linked_list(inorder,n);
    printf("\npreorder nodes:-");
    postfix = linked_list(postfix,n);
    printf("\ninorder->");display_list(inorder);
    printf("\npostfix->");display_list(postfix);

    root = create_tree(postfix,inorder,n);

    travertion_preorder(root);
}

list* linked_list(list* start,int n)
{
    list* temp=start;

    for(int c1=0;c1<n;c1++)
    {
        list* node = (list*)malloc(sizeof(list));
        printf("\nenter %d node number :",c1+1);
        scanf("%d",&node->data);
        node->next = NULL;

        if(start == NULL)
            start = temp=node;
        else
        {
            start->next = node;
            start=start->next;
        }
    }
    return temp;
}

void display_list(list* start)
{
    while(start != NULL)
    {
        printf("->%d",start->data);
        start = start->next;
    }
    return;
}

// tree* create_tree(list* pre,list* inorder,int n)
// {
//     static int node_no=1;
//     if(n==0)
//         return NULL;

//     list* root;
//     int left;

//     tree* node = (tree*)malloc(sizeof(tree));
//     printf("\nenter node data :");
//     scanf("%d",&node->data);
//     node->lchild=NULL;
//     node->rchild=NULL;

//     if(n==1)
//         return node;

//     root = inorder;
//     for(left=0;pre->data != root->data ;left++)  //point root node in inorder travertion;
//         root = root->next;

//     node->lchild = create_tree(pre->next,inorder,left); //create left subtree with new inoeder and preorder travertion;

//     for(int c1=1;c1<=left+1;c1++)
//         pre = pre->next;
    
//     node->rchild = create_tree(pre,root->next,n-left-1);
//     return node;
// }

tree* create_tree(list* pre,list* inorder,int n)
{
    static int num=1;
    if(n==0)
        return NULL;

    tree* node=(tree*)malloc(sizeof(tree));
    printf("\nenter %d node data :",num++);
    scanf("%d",&node->data);
    node->lchild=NULL;
    node->rchild=NULL;

    if(n==1)
        return node;
    
    list* root=inorder;
    int left=0;
    while(root->data != pre->data)
    {
        root = root->next;
        left++;
    }
    
    node->lchild = create_tree(pre->next,inorder,left);

    for(int c1=0;c1<=left;c1++)
        pre=pre->next;

    node->rchild = create_tree(pre,root->next,n-left-1);

    return node;

}

void travertion_preorder(tree* root)
{
    if(root == NULL)
    {
        printf("\nEMPTY TREE !");
        return;
    }

    push(root);
    while(top!=-1)
    {
        root = pop();
        printf("->%d",root->data);

        if(root->rchild!=NULL)
            push(root->rchild);
        if(root->lchild!=NULL)
            push(root->lchild);
        
    }
    return;
}

void push(tree* node)
{
    if(top==19)
    {
        printf("\nOVERFLOW !");
        return;
    }

    stack[++top] = node;
    return;
}

tree* pop()
{
    if(top==-1)
    {
        printf("\nUNDERFLOW !");
        return NULL;
    }

    return stack[top--];
}