#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    int data;
    struct tree* l_child,*r_child;
}tree;

tree* insert(tree*,tree*);
void inorder(tree*);
void preorder(tree*);
tree* succeor(tree*);
tree* delete(tree*,int);
tree* case_a(tree*,tree*,tree*);
tree* case_b(tree*,tree*,tree*);
tree* case_c(tree*,tree*,tree*);


int main()
{
    tree* root = NULL;
    int n;
    printf("\nenter number of node :");
    scanf("%d",&n);
    for(int c1=0;c1<n;c1++)
    {
        tree* node = (tree*)malloc(sizeof(tree));
        printf("\nenter %d node data :",c1+1);
        scanf("%d",&node->data);
        node->l_child=node->r_child=NULL;

        tree* temp = insert(root,node);
        if(temp == NULL)
            c1--;
        else
            root = temp;
    }
    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);

    int se;
    printf("\nenter delete node data :");
    scanf("%d",&se);
    root =  delete(root,se);

    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);
    return 0;
}

tree* insert(tree* root,tree* node)
{
    if(root==NULL)
        return node;
    
    if(root->data == node->data)
        return NULL;
    else if(root->data > node->data)
        root->l_child = insert(root->l_child,node);
    else if(root->data < node->data)
        root->r_child = insert(root->r_child,node);
    
    return root;
}

void inorder(tree* root)
{
    if(root==NULL)
        return;
    inorder(root->l_child);
    printf("->%d",root->data);
    inorder(root->r_child);
    return;
}

void preorder(tree* root)
{
    if(root==NULL)
        return;
    printf("->%d",root->data);
    preorder(root->l_child);
    preorder(root->r_child);
    return;
}


tree* succeor(tree* root)
{
    if(root->r_child == NULL)
        return NULL;
    else
    {
        root = root->r_child;
        while(root->l_child !=NULL)
            root = root->l_child;
    }
    return root;
}

tree* delete(tree* root,int data)
{
    tree* parent=NULL;
    tree* ptr = root;
    while(ptr->data != data)
    {
        parent = ptr;
        if(ptr->data > data)
            ptr = ptr->l_child;
        else
            ptr = ptr->r_child;
    }

    if(ptr->l_child == NULL && ptr->r_child == NULL)
        root = case_a(ptr,parent,root);
    else if(ptr->l_child != NULL && ptr->r_child != NULL)
        root = case_c(ptr,parent,root);   
    else 
        root = case_b(ptr,parent,root); 

    return root;
}

tree* case_a(tree* ptr,tree* parent,tree* root)
{
    if(parent == NULL)
        return NULL;
    
    if(parent->data > ptr->data)
        parent->l_child = NULL;
    else
        parent->r_child = NULL;
    
    return root;
}

tree* case_b(tree* ptr,tree* parent,tree* root)
{
    tree* child;
    if(ptr->l_child != NULL)
        child = ptr->l_child;
    else
        child = ptr->r_child;

    if(parent == NULL)
        return child;
    
    if(parent->data > ptr->data)
        parent->l_child = child;
    else
        parent->r_child = child;
    
    return root;
}

tree* case_c(tree* ptr,tree* parent,tree* root)
{
    tree* succ = succeor(ptr);
    ptr->data = succ->data;
    ptr = ptr->r_child;
    while(ptr->data != succ->data)
    {
        parent = ptr;
        if(ptr->data > succ->data)
            ptr = ptr->l_child;
        else
            ptr = ptr->r_child;
    }
    if(ptr->l_child == NULL && ptr->r_child == NULL)
        root = case_a(ptr,parent,root);
    else
        root = case_b(ptr,parent,root);

    return root;
}