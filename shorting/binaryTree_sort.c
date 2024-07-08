#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
}node;

node* cre_bst(node*,int[]);
void asc(node*,int[]);
void des(node*,int[]);
node* des_bst(node*);


int main()
{
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    node* root = NULL;

    root=cre_bst(root,arr);

    printf("\nassending order :");
    asc(root,arr);
    for(int c1=0;c1<10;c1++)
        printf(" %d",arr[c1]);

    printf("\ndesending order :");
    des(root,arr);
    for(int c1=0;c1<10;c1++)
        printf(" %d",arr[c1]);
    
    root = des_bst(root);

    return 0;
}

node* cre_bst(node* root,int arr[])
{
    node* ptr=NULL;
    for(int c1=0;c1<10;c1++)
    {
        node* par=NULL;
        root=ptr;
        while(root!=NULL)
        {
            if(root->data > arr[c1])
            {
                par=root;
                root=root->lchild;
            }
            else
            {
                par=root;
                root=root->rchild;
            }
        }

        node* new_node = (node*)malloc(sizeof(node));
        new_node->data=arr[c1];
        new_node->lchild=NULL;
        new_node->rchild=NULL;

        if(par==NULL)
            root=ptr=new_node;
        else
        {
            if(par->data>arr[c1])
                par->lchild=new_node;
            else
                par->rchild=new_node;
        }
    }

    return ptr;
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