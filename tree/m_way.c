#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key[2];
    struct node* child[3];
    int count;
}node;

node* insert(node*,int);
int rec_inc(node*,int*,node**,node**,int*);
void traverse(node*);
void enqueue(node*[],int*,int*,node*);
int is_underflow(node*[],int);
int is_overflow(node*[],int,int);
node* pop(node*[],int*,int*);
int search(node*,int,int*);

int main()
{
    node* root=NULL;
    int n,key;
    printf("\nenter number of nodes :");
    scanf("%d",&n);

    for(int c1=0;c1<n;c1++)
    {
        printf("\nenter %d data :",c1+1);
        scanf("%d",&key);
        root=insert(root,key);
        traverse(root);
    }

    return 0;
}

node* insert(node* root,int key)
{
    node* l_child,*r_child;
    l_child=r_child=NULL;
    int n;

    node* newnode = (node*)malloc(sizeof(node));
    if(root==NULL)
    {
        for(int c1=0;c1<3;c1++)
        {
            if(c1<2)
            {
                if(c1==0)
                    newnode->key[c1]=key;
                else
                    newnode->key[c1]=0;
            }
            
            newnode->child[c1]=NULL;
        }
        newnode->count=1;
        return newnode;
    }

    int flag = rec_inc(root,&key,&l_child,&r_child,0);
    if(flag)
    {
        for(int c1=0;c1<3;c1++)
        {
            if(c1<2)
            {
                if(c1==0)
                    newnode->key[c1]=key;
                else
                    newnode->key[c1]=0;
            }
            
            if(c1==0)
                newnode->child[c1]=l_child;
            else if(c1==1)
                newnode->child[c1]=r_child;
            else
                newnode->child[c1]=NULL;
        }
        newnode->count=0;
    }
}


void traverse(node* root)
{
    node* queue[20];
    int front=-1;
    int rare=-1;

    enqueue(queue,&front,&rare,root);
    while(!is_underflow(queue,front))
    {
        node* pop_el = pop(queue,&front,&rare);
        for(int c1=0;c1<pop_el->count;c1++)
        {
            printf("%d",pop_el->key[c1]);
            enqueue(queue,&front,&rare,pop_el->child[c1]);
        }
    }

}

void enqueue(node* queue[],int* front,int* rare,node* el)
{
    if(is_overflow(queue,*front,*rare))
        return;

    if(*front==-1)
    {
        (*rare)+=1;
        *front=0;
    }
    else if(*rare==19)
    {
        *rare=0;
    }
    queue[*rare]=el;
    return;
}

int is_underflow(node* queue[],int front)
{
    if(front==-1)
    {
        printf("\nUNDERFLOW !");
        return 1;
    }
    return 0;
}

int is_overflow(node* queue[],int front,int rare)
{
    if(front==rare+1 || (rare==19&&front==0))
        return 1;
    return 0;
}

node* pop(node* queue[],int* front,int*rare)
{
    node* temp;
    if(is_underflow(queue,*front))
    {
        printf("UNDERFLOW !");
        return NULL;
    }
    if(*front==*rare)
    {
        *rare=-1;
        temp=queue[*front];
        *front=-1;
    }
    else if(*front==19)
    {
        temp=queue[(*front)++];
        *front=0;
    }
    else
        temp=queue[(*front)++];

    return temp;
}

int rec_inc(node* root,int* key,node** l_child,node** r_Child,int* flag2)
{
    if(root==NULL)
        return 1;
    int n;
    if(search(root,key,&n))
    {
        printf("\nDUPLICATE VALUES ARE NOT ALLOWED !");
        return 0;
    }

    root = rec_inc(root->child[n],&key,&l_child,&r_Child,&flag_2);

    if(flag)
    {
        if(root->count<2)
            flag = insert_shifting(root,key,*l_child,*r_Child);
        else if(root->count == 2)
        {
            if(flag2)
            {
                //re think on flag2 concept;
            }
            else
            {
                flag = insert_split(root,&key,&l_child,&r_Child);
                *flag_2=1;
            }
        }
    }
}

int search(node* root,int key,int* n)
{
    int c1;
    for(c1=0;root->key[c1]<=key && c1<root->count;c1++)
    {
        if(root->key[c1]==key)
            return 1;
    }
    *n=c1;
    return 0;
}
