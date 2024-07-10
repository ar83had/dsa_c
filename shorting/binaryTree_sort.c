#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
    int fac;
}node;

node* cre_bst(node*,int,int);
void asc(node*,int[]);
void des(node*,int[]);
node* des_bst(node*);
node* cre_avl(node*,int,int*);
node* l_rotate(node*);
node* r_rotate(node*);
void pre_order(node*);

int main()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    node* root = NULL;

    for(int c1=0;c1<10;c1++)
        root=cre_bst(root,arr[c1],1);

    printf("\nassending order :");
    asc(root,arr);
    for(int c1=0;c1<10;c1++)
        printf(" %d",arr[c1]);

    printf("\npreorder :");
    pre_order(root);

    printf("\ndesending order :");
    des(root,arr);
    for(int c1=0;c1<10;c1++)
        printf(" %d",arr[c1]);
    
    root = des_bst(root);

    return 0;
}

node* cre_bst(node* root,int el,int flag)
{
    if(root==NULL)
    {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->lchild=NULL;new_node->rchild=NULL;new_node->fac=0;new_node->data=el;
        return new_node;
    }

    if(root->data>el)
    {
        root->lchild=cre_bst(root->lchild,el,flag);
        if(flag)
            root = cre_avl(root,1,&flag);    

    }
    else
    {
        root->rchild=cre_bst(root->rchild,el,flag);
        if(flag)
            root = cre_avl(root,0,&flag);
    }

    return root;
}

node* cre_avl(node* root,int l,int* flag)
{
    if(l==1)
    {
        if(root->fac==0)
            root->fac=1;
        else if(root->fac==1)
        {
            root->fac=0;root->lchild->fac=0;
            root = r_rotate(root);
            *flag=0;
        }
        else
        {
            root->fac=0;
            *flag=0;
        }
    }
    else
    {
        if(root->fac==0)
            root->fac=-1;
        else if(root->fac==1)
        {
            root->fac=0;
            *flag=0;
        }
        else
        {
            root->fac=0;root->rchild->fac=0;
            root = l_rotate(root);
            *flag=0;
        }
    }

    return root;
}

node* r_rotate(node* root)
{
    node* r_ptr = root->lchild;
    node* temp=r_ptr->rchild;
    r_ptr->rchild=root; 
    root->lchild=temp;

    return r_ptr;
}

node* l_rotate(node* root)
{
    node* r_ptr=root->rchild;
    node* temp=r_ptr->lchild;
    r_ptr->lchild=root;
    root->rchild=temp;

    return r_ptr;
}

void asc(node* root,int arr[])
{
    int static c1=0;
    if(root==NULL)
        return;
    
    asc(root->lchild,arr);
    arr[c1++]=root->data;
    asc(root->rchild,arr);

    return;
}

void des(node* root,int arr[])
{
    int static c1=0;
    if(root==NULL)
        return;
    
    des(root->rchild,arr);
    arr[c1++]=root->data;
    des(root->lchild,arr);

    return;
}

node* des_bst(node* root)
{
    if(root==NULL)
        return NULL;
    
    root->lchild=des_bst(root->lchild);
    root->rchild=des_bst(root->rchild);
    free(root);
    return NULL;
}

void pre_order(node* root)
{
    if(root==NULL)
        return;
    
    printf(" %d",root->data);
    pre_order(root->lchild);
    pre_order(root->rchild);

    return;
}