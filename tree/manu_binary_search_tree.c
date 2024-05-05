#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* r_child,*l_child;
}node;

node* create(node*);
node* insert(node*,node*);
void display(node*);
int search(node*,int);
int is_empty(node*);
node* delete(node*,int);

int main()
{
    int ch,se,flag;
    node* root=NULL;
    do
    {
        printf("\n1)create\n2)search\n3)delete\nenter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                root= create(root);
                break;
            case 2:
                printf("\nenter search data :");
                scanf("%d",&se);
                flag=search(root,se);
                if(flag)
                    printf("\nSEARCH SUCCESSFULL !");
                else
                    printf("\nSEARCH NOT SUCCESSFULL !");
                break;
            case 3:
                printf("\nenter deleted node data :");
                scanf("%d",&se);
                root = delete(root,se);
                break;
        }
        printf("\n");
        display(root);
    } while (ch <=3);
    
    return 0;
}

node* create(node* root)
{
    int n;
    printf("\nenter number of nodes :");
    scanf("%d",&n);

    for(int c1=0;c1<n;c1++)
    {
        node* new_node = (node*)malloc(sizeof(node));
        printf("\nenter %d node data :",c1+1);
        scanf("%d",&new_node->data);
        new_node->l_child=new_node->r_child=NULL;

        node* temp = insert(root,new_node);
        if(temp !=NULL)
            root = temp;
        else
            c1--;
    }
    return root;
}

node* insert(node* root,node* new_node)
{
    if(root==NULL)
        return new_node;

    node* temp = root;
    node* parent = NULL;
    while(temp != NULL)
    {
        parent = temp;
        if(temp->data > new_node->data)
            temp = temp->l_child;
        else if(temp->data < new_node->data)
            temp = temp->r_child;
        else if(temp->data == new_node->data)
        {
            printf("\nDUPLICATE DATA !");
            return NULL;
        }
    }

    if(parent->data > new_node->data)
        parent->l_child=new_node;
    else
        parent->r_child=new_node;
    
    return root;
}

// void display(node* root)
// {
//     if(root==NULL)
//         return;
    
//     display(root->l_child);
//     printf("->%d",root->data);
//     display(root->r_child);
//     return;
// }

void display(node* root)      //level wise travertion;
{
    node* stack[20];
    int index=0;
    stack[index]=root;
    int front=0;
    while(front <= index)
    {
        printf("->%d ",root->data);
        front++;
        if(root->l_child!=NULL)
            stack[++index]=root->l_child;
        if(root->r_child!=NULL)
            stack[++index]=root->r_child;
        root = stack[front];
    }
    return;
}
int is_empty(node* root)
{
    if(root==NULL)
    {
        printf("\nEMPTY TREE !");
        return 1;
    }
    else
        return 0;
}

int search(node* root,int se)
{
    if(is_empty(root))
        return 0;
    
    while(root!=NULL)
    {
        if(root->data == se)
            return 1;
        else if(root->data > se)
            root = root->l_child;
        else
            root = root->r_child;
    }
    return 0;
}

node* delete(node* root,int se)
{
    if(is_empty(root))
        return root;
    node* parent = NULL;
    node* ptr = root;
    node* succ;

    while(ptr->data != se && ptr !=NULL)
    {
        parent = ptr;
        if(ptr->data >  se)
            ptr = ptr->l_child;
        else
            ptr = ptr->r_child;
    }

    if(ptr == NULL)
    {
        printf("DATA WILL FOUNDED !");
        return ptr;
    }

    if(ptr->l_child !=NULL && ptr->r_child !=NULL)
    {
        succ = ptr->r_child;
        parent = ptr;
        while(succ->l_child!=NULL)
        {
            parent = ptr;
            succ = succ->l_child;
        }

        ptr->data = succ->data;
        ptr = succ;
    }

    node* child;
    if(ptr->l_child==NULL || ptr->r_child==NULL)    //find child in both cases(leaf , single child)
        if(ptr->l_child!=NULL)
            child = ptr->l_child;
        else
            child = ptr->r_child;
    
    if(parent == NULL)               //jion child her parent node;
    {
        root = child;
    }
    else if(parent->data > ptr->data)
        parent->l_child=child;
    else
        parent->r_child=child;
        
    
    return root;
}