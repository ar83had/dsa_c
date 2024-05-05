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
void display_tree_preorder(tree*);
void push(tree*);
tree* pop();
void display_recurtion_inorder(struct tree*);
void display_recurtion_postorder(struct tree*);
tree* create_binary_search(tree*);
tree* insert_binary_tree(tree*,tree*);
void max_node_binary(tree*);
void min_node_binary(tree*);



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

tree* create_tree(list* pre,list* inorder,int n)
{
    static int node_no=1;
    if(n==0)
        return NULL;

    list* root;
    int left;

    tree* node = (tree*)malloc(sizeof(tree));
    printf("\nenter node data :");
    scanf("%d",&node->data);
    node->lchild=NULL;
    node->rchild=NULL;

    if(n==1)
        return node;

    root = inorder;
    for(left=0;pre->data != root->data ;left++)  //point root node in inorder travertion;
        root = root->next;

    node->lchild = create_tree(pre->next,inorder,left); //create left subtree with new inoeder and preorder travertion;

    for(int c1=1;c1<=left+1;c1++)
        pre = pre->next;
    
    node->rchild = create_tree(pre,root->next,n-left-1);
    return node;
}

void display_tree_preorder(tree* root)
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


void display_recurtion_inorder(struct tree* root)
{
    if(root==NULL)
        return;
    
    display_recurtion_inorder(root->lchild);
    printf("->%d",root->data);
    display_recurtion_inorder(root->rchild);
    return;
}


void display_recurtion_postorder(struct tree* root)
{
    if(root == NULL)
        return;

    display_recurtion_postorder(root->lchild);
    display_recurtion_postorder(root->rchild);
    printf("->%d",root->data);
    return;
}

tree* create_binary_search(tree* root){
    tree* temp=NULL;
    int n;
    printf("\nneter number of node :");
    scanf("%d",&n);

    for(int c1=0;c1<n;c1++){
        tree* node=(tree*)malloc(sizeof(tree));
        printf("\nenter %d node data :",c1+1);
        scanf("%d",&node->data);
        node->lchild=node->rchild=NULL;

        temp=insert_binary_tree(root,node);
        if(temp==NULL)
            c1--;
        else
            root=temp;
    }

    return root;
}

tree* insert_binary_tree(tree* root,tree* node){
    tree* parent=NULL,*temp=root;

    while(root!=NULL){
        parent=root;
        if(root->data==node->data)
            return temp;
        else if(root->data > node->data)
            root=root->lchild;
        else
            root=root->rchild;
    }

    if(parent==NULL)
        return node;
    else
        if(parent->data > node->data)
            parent->lchild=node;
        else
            parent->rchild=node;
    
    return temp;
}

void max_node_binary(tree* root){
    if(root==NULL)
    {
        printf("\nEMPTY TREE !!!");
        return;
    }

    while(root->rchild!=NULL)
        root=root->rchild;
    
    printf("\nmaxium node->%d",root->data);
    return;
}

void min_node_binary(tree* root)
{
    if(root==NULL)
        printf("\nEMPTY TREE !!!");
    else
    {
        while(root->lchild!=NULL)
            root=root->lchild;
        
        printf("\nminimum data ->%d",root->data);
    }

    return;
}