#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define M 3

typedef struct node
{
    int count;
    int key[M];
    struct node* child[M];
}node;

node* insert(int,node*);
int rec_ins(int,node*,int*,node**);
int search(int,node*,int*);
void shifiting_insert(int,node*,node*,int);

int main()
{
    int n;
    printf("enter number of keys :");
    scanf("%d",&n);
    node* root=NULL;

    for(int c1=0;c1<n;c1++)
    {
        int ikey;
        printf("enter %d key :");
        scanf("%d",&ikey);
        root = insert(ikey,root);
    }

    // int n1;
    // node temp = {1,{0,1},{NULL,NULL}};
    // int re =search(0,&temp,&n1);
    // printf("%d",n1);

    return 0;
}

node* insert(int ikey,node* proot)
{
    int p_k,flag=0;
    node* new_node,*r_child;

    flag = rec_ins(ikey,proot,&p_k,&r_child);

    if(flag)
    {
        new_node->count=1;
        new_node->key[1]=p_k;
        new_node->child[0]=proot;
        new_node->child[1]=r_child;
        proot=new_node;
    }
    return proot;
}

int rec_ins(int ikey,node* proot,int* p_k,node** r_child)
{
    if(proot==NULL)
    {
        *p_k=ikey;
        *r_child=NULL;
        return 1;
    }
    int n;
    if(search(ikey,proot,&n))     //find next child node;
    {
        printf("\nDUPLICATE VALUE IS NOT ALLOW !");
        return 0;
    }
    int flag = rec_ins(ikey,proot->child[n],p_k,*r_child);

    if(flag)
    {
        if(proot->count < M)
        {
            shifting_insert(p_k,r_child,proot,n);
            return 0;
        }
        else
        {
            split(*p_k,*r_child,proot,n,p_k,r_child);
            return 1;
        }

    }
    return 0;
}


int search(int ikey,node* proot,int* n)
{
    int c1=1;
    while(ikey >= proot->key[c1] && c1 <= proot->count)
    {
        if(ikey==proot->key[c1])
            return 1;
        c1++;
    }
    if(c1==1)
        *n=0;
    else
        *n=c1-1;

    return 0;
}

void shifiting_insert(int ikey,node* r_child,node* proot,int n)
{
    for(int c1=proot->count;c1>n;c1--)
    {
        proot->key[c1+1]=proot->key[c1];
        proot->child[c1+1]=proot->child[c1];
    }
    proot->key[c1+1] = ikey;
    proot->child[c1+1] = r_child;
    proot->count +=1;
    return;
}

// pause dsa now;