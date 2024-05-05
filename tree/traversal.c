#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree* lchild,*rchild;
};
struct tree* stack[20];
int top=-1;
struct tree* queue[16];

void display_recurtion_preorder(struct tree*);
void display_recurtion_inorder(struct tree*);
void display_recurtion_postorder(struct tree*);

void display_nonrecurtion_preorder(struct tree*);
void display_nonrecurtion_inorder(struct tree*);
void display_nonrecurtion_postorder(struct tree*);

void levelwise(struct tree*);

void push(struct tree*);
struct tree* pop();
void enqueue(struct tree*);
struct tree* dequeue();

int rare=-1,front=-1;


int main()
{
    struct tree n7={7,NULL,NULL};
    struct tree n6={6,NULL,NULL};
    struct tree n5={5,NULL,NULL};
    struct tree n4={4,&n6,&n7};
    struct tree n3={3,NULL,&n5};
    struct tree n2={2,&n4,NULL};
    struct tree n1={1,&n2,&n3};
    struct tree* root = &n1;

    printf("\nrecurively preorder travertion :-\n");
    display_recurtion_preorder(root);

    printf("\nrecursively inorder travertion :-\n");
    display_recurtion_inorder(root);

    printf("\nrecursiverly postorder travertion :-\n");
    display_recurtion_postorder(root);

    printf("\nnon recurtion preorder travertion :-\n");
    display_nonrecurtion_preorder(root);

    printf("\nnon recursively inorder travertion :-\n");
    display_nonrecurtion_inorder(root);

    printf("\nnon recursively postorder travertion :-\n");
    display_nonrecurtion_postorder(root);

    printf("\nlevel wise data :-\n");
    levelwise(root);

    return 0;
}

void display_recurtion_preorder(struct tree* root)
{
    if(root==NULL)
        return;
    
    printf("->%d",root->data);
    display_recurtion_preorder(root->lchild);
    display_recurtion_preorder(root->rchild);
    return;
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

void push(struct tree* node)
{
    if(top==19)
    {
        printf("\nSTACK OVERFLOW !!");
        return;
    }
    stack[++top]=node;
    return;
}

struct tree* pop()
{
    if(top==-1)
    {
        printf("\nSTACK UNDERFLOW !!!");
        exit(1);
    }

    return stack[top--];
}

void display_nonrecurtion_preorder(struct tree* root)
{

    if(root==NULL)
    {
        printf("\nTREE DOES NOT EXISTS !!!");
        return;
    }

    push(root);

    while(top!=-1)
    {

        struct tree* ptr=pop();
        printf("->%d",ptr->data);

        if(ptr->rchild!=NULL)
            push(ptr->rchild);
        if(ptr->lchild!=NULL)
            push(ptr->lchild);

    }

    return;
}

void display_nonrecurtion_inorder(struct tree* root)
{
    if(root==NULL)
    {
        printf("\nTREE EMPTY !!!");
        return;
    }
    while(root != NULL)
    {
        while(root->lchild != NULL)
        {
            push(root);
            root = root->lchild;
        }

        while(root->rchild == NULL)
        {
            printf("->%d",root->data);
            if(top == -1)
                return;
            root = pop();
        }

        printf("->%d",root->data);
        root = root->rchild;
    }

    return;
}

void display_nonrecurtion_postorder(struct tree* root)
{
    if(root==NULL)
    {
        printf("/nEMPTY STACK !!!");
        return;
    }
    while(root != NULL)
    {
        while(root->lchild != NULL)
        {
            push(root);
            root = root->lchild;
        }

        struct tree* q=NULL;
        while(root->rchild == NULL || root->rchild == q)
        {
            printf("->%d",root->data);
            q = root;
            if(top==-1)
                return;
            root = pop();
        }

        push(root);
        root = root->rchild;
    }
    return;
}

void enqueue(struct tree* node)
{
    if(front==0 && rare==15 || front == rare+1)
    {
        printf("\nQUEUE OVERFLOW !!!");
        return;
    }
    else if(rare==-1)
        front = 0;
    
    if(rare == 15)
        rare = 0;
    else
        rare++;

    queue[rare]=node;
    return;
}

struct tree* dequeue()
{
    struct tree* temp;
    if(front==-1)
    {
        printf("\nQUEUE UNDERFLOW");
        return NULL;
    }
    else if(rare==front)
    {
        temp=queue[front];
        rare=front=-1;
        return temp;
    }
    
    if(front==15)
    {
        temp = queue[front];
        front = 0;
    }
    else
    {
        temp=queue[front];
        front++;
    }
    return temp;
}

void levelwise(struct tree* root)   // some node duplicatly printed;
{
    if(root==NULL)
    {
        printf("\nEMPTY TREE");
        return;
    }

    enqueue(root);

    while(front!=-1)
    {
        root = dequeue();
        printf("->%d",root->data);
        if(root->lchild!=NULL)
        {
            enqueue(root->lchild);
        }
        if(root->rchild !=NULL)
        {
            enqueue(root->rchild);
        }

    }
    return;
}
