#include<stdio.h>
#include<stdlib.h>

typedef struct avl_tree
{
    int data,factore;
    struct avl_tree* lchild,*rchild;
}tree;

void inorder(tree*);
tree* l_roate(tree*);
tree* r_roate(tree*);
tree* search(tree*,int);
tree* search_2(tree*,int);

tree* insert(tree*,tree*);
tree* left_insertion(tree*);
tree* right_insertion(tree*);

tree* delete(tree*,int);
tree* check_avl(tree*,int);
void pre(tree*);

int flag=1;
int main()
{
    // int n;                                 //create binsry tree;
    // printf("\nenter number of node :");
    // scanf("%d",&n);

    // tree* root=NULL,*ptr=NULL;    
    // for(int c1=0;c1<n;c1++)
    // {
    //     tree* node=(tree*)malloc(sizeof(tree));
    //     printf("\nenter %d node data :",c1+1);
    //     scanf("%d",&node->data);
    //     node->lchild=node->rchild=NULL;
    //     node->factore=0;

    //     if(root==NULL)
    //         root=ptr=node;
    //     else
    //     {
    //         ptr=root;
    //         tree* parent=NULL;
    //         while(ptr!=NULL)
    //         {
    //             parent=ptr;
    //             if(ptr->data == node->data)
    //             {
    //                 printf("DUPLICATE DATA !");
    //                 c1--;
    //                 break;
    //             }
    //             else if(node->data > ptr->data)
    //                 ptr=ptr->rchild;
    //             else 
    //                 ptr=ptr->lchild;

    //         }

    //         if(parent->data != node->data)
    //         {
    //             if(parent->data > node->data)
    //                 parent->lchild=node;
    //             else
    //                 parent->rchild=node;
    //         }

    //     }

    // }

    // inorder(root);
    // printf("before root->%d",root->rchild->data);
    // root=search(root,7);                           //right rotation of search element;
    // printf("\n");
    // printf("after r_rotation->%d",root->rchild->data);
    // inorder(root);
    // root=search_2(root,6);                         //left rotation of search element;
    // printf("before l_rotation ->%d",root->rchild->data);
    // inorder(root);

    int n;                                  //for createing an avl tree;
    printf("\nenter number of nodes :");
    scanf("%d",&n);

    tree* root=NULL;
    for(int c1=0;c1<n;c1++)
    {
        tree* node=(tree*)malloc(sizeof(tree));
        printf("\nenter node data :");
        scanf("%d",&node->data);
        node->lchild=node->rchild=NULL;
        node->factore=0;


        flag=1;
        tree* temp=insert(root,node);
        printf("%d/",temp->data);
        if(temp==NULL)
            c1--;
        else
            root=temp;
    }
    
    printf("\n");
    inorder(root);
    printf("\n");
    pre(root);
    // printf("%d",root->data);
    // inorder(root);

    // int se;
    // printf("enter delete node data :");
    // scanf("%d",&se);
    // root=delete(root,se);
    // inorder(root);

    return 0;
}

void pre(tree* root)
{
    if(root==NULL)
        return;
    
    printf(" %d",root->data);
    pre(root->lchild);
    pre(root->rchild);

    return;
}

void inorder(tree* root)
{
    if(root==NULL)
        return;

    inorder(root->lchild);
    printf("%d(%d),",root->data,root->factore);
    inorder(root->rchild);
    return;
}

tree* r_roate(tree* root)
{
    tree* ptr=root->lchild;
    root->lchild=ptr->rchild;
    ptr->rchild=root;
    return ptr;
}

tree* search(tree* root,int se)
{
    tree* parent=NULL;
    tree* temp=root;
    while(root!=NULL && root->data != se)
    {
        parent=root;
        if(root->data > se)
            root=root->lchild;
        else
            root=root->rchild;
    }
    if(root==NULL)
        return root;
    else
    {
        if(parent==NULL)
            return r_roate(root);
        if(parent->data>se)
        {

            parent->lchild=r_roate(root);
        }
        else
        {
            parent->rchild=r_roate(root);
        }
    }
    inorder(temp);
    return temp;
}


tree* search_2(tree* root,int se)
{
    tree* parent=NULL;
    tree* ptr=root;

    while(ptr!=NULL && ptr->data!=se)
    {
        parent=ptr;
        if(ptr->data > se)
            ptr=ptr->lchild;
        else
            ptr=ptr->rchild;
    }

    if(parent==NULL)
        return l_roate(root);
    
    if(parent->data < se)
        parent->rchild=l_roate(ptr);
    else
        parent->lchild=l_roate(ptr);
    
    printf("/%d%d",root->data,root->rchild->data);
    return root;
}

tree* l_roate(tree* root)
{
    tree* ptr=root->rchild;
    root->rchild=ptr->lchild;
    ptr->lchild=root;
    return ptr;
}


//take rootnode , inserted node and a flag=1(flag referse that need of further check parent node avl proprity);
//insert node into winding phase;
//check the avl proprity(blabnce factore of parent node);
//if parent balance factore is 0 set 1 in left insertion and set right in right insertion and flag=1;
//if parent balance facotre is 1 (and insertion at right) or -1 (and insertion at left) set it 0 and flag=0;
//if parent node factore is 1 (and insertion at left so right rotation ) or -1 (insertion at right so letf rotation ) and flag=0;
tree* insert(tree* root,tree* node)  
{
    if(root==NULL)
    {
        return node;
    }
    if(root->data > node->data)
    {
        root->lchild=insert(root->lchild,node);   //insertion;
        if(flag)
            root=left_insertion(root);                     //balancing root and inserted node;
    }
    else if(root->data < node->data)
    {
        root->rchild=insert(root->rchild,node);
        if(flag)
            root=right_insertion(root);
    }
    else
    {
        printf("DUPLICATE DATA !");
        return NULL;
    }
    return root;
}

tree* left_insertion(tree* root)
{
    if(root->factore==0)
    {
        root->factore=1;
    }
    else if(root->factore==-1)
    {
        root->factore=0;
        flag=0;
    }
    else if(root->factore==1)
    {
        root->factore=0;
        root->lchild->factore=0;
        root=r_roate(root); 
        flag=0;
    }
    return root;
}

tree* right_insertion(tree* root)
{
    if( root->factore==0)
        root->factore=-1;
    else if(root->factore==1)
    {
        root->factore=0;
        flag=0;
    }
    else if(root->factore==-1)
    {
        root->factore=0;
        root->rchild->factore=0;
        root=l_roate(root);
        flag=0;
    }
    return root;
}


//delete node as per the binary search tree;
//chaeck_avl of parent node and set flag=1(further parent checking);
//if parent->factore=0 --->(left deletion set 1 and right deletion set -1) set flag=0;
//if parent->factore=1 --->(left deletion set it 0 flag=1 or right deletion call l_rotate());
//if parent->factore=-1--->(left deletion call r_rotation or right deletion set 0 ,flag=1);
 
tree* delete(tree* root,int se)
{   tree* temp;
    if(root==NULL)
    {
        printf("TREE IS EMPTY OR NODE WILL NOT FOUNDED !");
        return NULL;
    }
    else if(root->data ==  se)
    {
        if(root->lchild==NULL && root->rchild==NULL)
        {
            temp=root;
            return NULL;
        }
        else if(root->lchild==NULL && root->rchild != NULL)
        {
            temp=root;
            return root->rchild;
        }
        else if(root->rchild==NULL && root->lchild !=NULL)
        {
            temp=root;
            return root->lchild;
        }
        else
        {
            temp=root;
            temp=temp->rchild;
            while(temp->lchild != NULL)
            {
                temp=temp->lchild;
            }
            
            root->data=temp->data;
            free(temp);
            return root;
        }
    }
    else if(root->data > se)
    {
        root->lchild=delete(root->lchild,se);
        if(flag)
            root=check_avl(root,1);
    }
    else if(root->data<se)
    {
        root->rchild=delete(root->rchild,se);
        if(flag)
            root=check_avl(root,0);
    }
    return root;
}

tree* check_avl(tree* root,int l_flag)
{
    if(l_flag)
    {
        if(root->factore==0)
        {
            root->factore=-1;
            flag=0;
        }
        else if(root->factore==1)
        {
            root->factore=0;
        }
        else if(root->factore==-1)
        {
            root=l_roate(root);
            flag=0;
        }
    }
    else
    {
        if(root->factore==0)
        {
            root->factore=1;
            flag=0;
        }
        else if(root->factore==1)
        {
            root=r_roate(root);
            flag=0;
        }
        else if(root->factore==-1)
        {
            root->factore=0;
        }
    }
    return root;
}