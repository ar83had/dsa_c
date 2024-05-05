#include<stdio.h>
#include<stdlib.h>

typedef struct binary_thread_tree
{
    int data,lthread,rthread;
    struct binary_thread_tree* lchild,* rchild;
}thread_tree;
int inorder[20],preorder[20];

thread_tree* create(thread_tree*);
thread_tree* insert(thread_tree*,thread_tree*);
void inorder_fn(thread_tree*);
thread_tree* delete(thread_tree*);
thread_tree* case_a(thread_tree*,thread_tree*,thread_tree*);
thread_tree* case_b(thread_tree*,thread_tree*,thread_tree*);
thread_tree* successor(thread_tree*);
thread_tree* preduccesor(thread_tree*);
thread_tree* case_c(thread_tree*,thread_tree*);

int main()
{
    thread_tree* root=NULL;
    root=create(root);
    inorder_fn(root);
    root=delete(root);
    inorder_fn(root);
    return 0;
}

thread_tree* create(thread_tree* root)
{
    int n;
    printf("\nenter number of node :");
    scanf("%d",&n);

    for(int c1=0;c1<n;c1++)
    {
        thread_tree* node=(thread_tree*)malloc(sizeof(thread_tree));
        printf("\nenter %d node data :",c1+1);
        scanf("%d",&node->data);
        node->lthread=node->rthread=1;
        node->lchild=node->rchild=NULL;

        thread_tree* temp = insert(root,node);
        if(temp==NULL)
        {
            printf("\nDUPLICATE DATA !!!");
            c1--;
        }
        else
            root=temp;

    }

    return root;
}

thread_tree* insert(thread_tree* root,thread_tree* node)
{
    thread_tree* ptr=root;
    while(ptr!=NULL)
    {
        if(ptr->data == node->data)
            return root;
        else if(ptr->data > node->data)
        {
            if(ptr->lthread==0)
                ptr=ptr->lchild;
            else
                break;
        }
        else
        {
            if(ptr->rthread==0)
                ptr=ptr->rchild;
            else
                break;
        }
    }

    if(root==NULL)
        return node;
    else
    {
        if(node->data > ptr->data)
        {
            node->rchild=ptr->rchild;
            node->lchild=ptr;
            ptr->rchild=node;
            ptr->rthread=0;
        }
        else
        {
            node->lchild=ptr->lchild;
            node->rchild=ptr;
            ptr->lchild=node;
            ptr->lthread=0;
        }
    }

    return root;
}


void inorder_fn(thread_tree* root)
{
    if(root==NULL)
    {
        printf("\nEMPTY TREE !");
        return;
    }
    while(root->lchild!=NULL)
        root=root->lchild;
    while(root!=NULL)
    {
        printf("->%d",root->data);
        root=successor(root);
    }

    return;
}

thread_tree* delete(thread_tree* root)
{

    if(root==NULL)
    {
        printf("\nEMPTY TREE !");
        return NULL;
    }

    int se;
    printf("\nenter deleted data :");
    scanf("%d",&se);
    thread_tree* parent=NULL;
    thread_tree* ptr=root;
    while(ptr->data != se)
    {
        parent=ptr;
        if(se>ptr->data)
            ptr=ptr->rchild;
        else
            ptr=ptr->lchild;
    }

    if(ptr->lthread==1 && ptr->rthread==1)
        root=case_a(parent,ptr,root);
    else if(ptr->lthread==1 || ptr->rthread==1)
        root=case_b(root,parent,ptr);
    else
        root=case_c(root,ptr);
    return root;
}

thread_tree* case_a(thread_tree* parent,thread_tree* node,thread_tree* root)
{
    if(parent==NULL)
        return NULL;
    if(parent->lchild==node)
    {
        parent->lchild=node->lchild;
        parent->lthread=1;
    }
    else
    {
        parent->rchild=node->rchild;
        parent->rthread=1;
    }

    return root;
}

thread_tree* case_b(thread_tree* root,thread_tree* parent,thread_tree* node)
{
    thread_tree* node2;
    if(node->lthread==1)
    {
        node2=successor(node);
        node2->lchild=node->lchild;
    }
    else
    {
        node2=preduccesor(node);
        node2->rchild=node->rchild;
    }

    thread_tree* child;
    if(node->lthread==0)
    {
        child=node->lchild;
        if(parent==NULL)
            return child;
        else
        {
            if(parent->lchild==node)
                parent->lchild=child;
            else
                parent->rchild=child;
        }
    }
    else
    {
        child=node->rchild;
        if(parent==NULL)
            return child;
        else
        {
            if(parent->lchild==node)
                parent->lchild=child;
            else
                parent->rchild=child;
        }
    }
    return root;
}

thread_tree* successor(thread_tree* root)
{
    if(root->rthread==1)
        return root->rchild;
    
    root=root->rchild;
    while(root->lthread!=1)
        root=root->lchild;
    
    return root;
}

thread_tree* preduccesor(thread_tree* root)
{
    if(root->lthread==1)
        return root->lchild;
    
    root = root->lchild;
    while(root->rthread!=1)
        root=root->rchild;
    return root;
}

thread_tree* case_c(thread_tree* root,thread_tree* node)
{
    thread_tree* parent=node,*succ=node->rchild;
    while(succ->lthread!=1)
    {
        parent=succ;
        succ=succ->lchild;
    }
    node->data=succ->data;
    if(succ->lthread==0 && succ->rthread==0)
        root=case_c(root,succ);
    else if(succ->lthread==1 && succ->rthread==1)
        root=case_a(parent,succ,root);

    else
        root=case_b(root,parent,succ);
    
    return root;
}