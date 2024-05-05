#include"tree.h"

//tree* create_binary_search(tree*);
tree* insert(tree*,tree*);
void binary_tree_search(tree*,int);
void max_node(tree*);
void min_node(tree*);
tree* delete_node(tree*,int);
tree* del_case_a(tree*,tree*,tree*);
tree* del_case_b(tree*,tree*,tree*);
tree* del_case_c(tree*,tree*,tree*);


int main()
{
    tree* root=NULL;
    root=create_binary_search(root);   //create binry tree

    printf("\ninorder :-");             //traverse binary tree bu inorder and preorder;
    display_recurtion_inorder(root);
    printf("\npreorder :-");
    display_tree_preorder(root);
 
    // int el;                              //serach in binary search tree;
    // printf("\nenter search data :");
    // scanf("%d",&el);
    // binary_tree_search(root,el);

    // max_node(root);             //find maximum node in tree;
    // min_node(root);           //find minimun node in tree;

    int el;
    printf("\nenter delete node data :");
    scanf("%d",&el);
    tree* temp=delete_node(root,el);
    root=temp;
    printf("\ninorder :-");             //traverse binary tree bu inorder and preorder;
    display_recurtion_inorder(root);
    printf("\npreorder :-");
    display_tree_preorder(root);

    return 0;
}

// tree* create_binary_search(tree* root)    //create binary serach tree;
// {
//     int n;
//     printf("\nenter number of node :");
//     scanf("%d",&n);

//     for(int c1=0;c1<n;c1++)
//     {
//         tree* node= (tree*)malloc(sizeof(tree));
//         printf("\nenter %d node data :",c1+1);
//         scanf("%d",&node->data);
//         node->lchild=node->rchild=NULL;

//         tree* temp = insert(root,node);
//         if(temp==NULL)
//             c1--;
//         else
//             root=temp;
        
//     }
//     return root;
// }

tree* insert(tree* root,tree* node)   //insert new node into existing bianry serach tree(non-recursion)
{
    tree*fix=root,*temp;
    if(root==NULL)
        return node;
    else
    {
        while(root!=NULL)
        {
            temp = root;

            if(root->data > node->data)
                root=root->lchild;
            else if(node->data > root->data)
                root=root->rchild;
            else
            {
                printf("\nDUPLICATE VALUE !");
                return NULL;
            }
        }
        
        if(temp->data > node->data)
            temp->lchild=node;
        else
            temp->rchild=node;

    }
    return fix;
}

// tree* insert(tree* root,tree* node)   //recursion method;
// {
//     if(root==NULL)
//         return node;
//     else if(root->data == node->data)
        
//     else if(node->data > root->data)
//         root->rchild=insert(root->rchild,node);
//     else
//         root->lchild=insert(root->lchild,node);
    
//     return root;
// }

void binary_tree_search(tree* root,int el)   //searching through non-recurtion
{ 

    while(root != NULL)
    {
        if(root->data > el)
            root = root->lchild;
        else if(root->data < el)
            root = root->rchild;
        else
        {
            printf("\nSEARCH FOUNDED !");
            return;
        }
    }

    printf("\nSEARCH UNSECCUSSFUL !");
    return;
}

// void binary_tree_search(tree* root,int node)  // searching througn recurtion
// {
//     if(root==NULL)
//         printf("\nSEARCH UNSECCEUSSFUL !");
//     else if(root->data == node)
//         printf("\nSEARCH SUCCESSFUL !");
//     else if(root->data > node)
//         binary_tree_search(root->lchild,node);
//     else
//         binary_tree_search(root->rchild,node);
//     return;
// }

void max_node(tree* root)                         //non-recursion(maximun node)
{
    while(root->rchild != NULL)
        root = root->rchild;
    
    printf("\nmaxium node data -> %d",root->data);
    return;
}

// void max_node(tree* root)                    //recusion(max node)
// {
//     if(root->rchild==NULL)
//     {
//         printf("\nmaxium node data--> %d",root->data);
//         return;
//     }

//     max_node(root->rchild);
//     return;
// }

// void min_node(tree* root)                //non-recursion(minimum)
// {
//     while(root->lchild!=NULL)
//         root =root->lchild;
    
//     printf("\nminimum node data -> %d",root->data);
//     return;
// }

void min_node(tree* root)                     //recusion
{
    if(root->lchild == NULL)
    {
        printf("\nminimum node data -> %d",root->data);
        return;
    }
    min_node(root->lchild);
    return;
}

tree* delete_node(tree* root,int el)
{
    tree* del_node=root,*del_parent=NULL;

    if(del_node==NULL)
    {
        printf("\nTREE EMPTY !");
        return NULL;
    }

    while(del_node->data != el)   //find delete node and it parent node;
    {
        del_parent=del_node;
        if(del_node->data > el)
            del_node=del_node->lchild;
        else
            del_node=del_node->rchild;
    }

    if(del_node->rchild==NULL && del_node->lchild==NULL)
        root=del_case_a(root,del_node,del_parent);
    else if(del_node->lchild ==NULL || del_node->rchild==NULL)
        root=del_case_b(root,del_node,del_parent);
    else
        root=del_case_c(root,del_node,del_parent);

    return root;

}

tree* del_case_a(tree* root,tree* del_node,tree* del_parent)
{
    if(del_node==root)
        return NULL;
    
    if(del_parent->rchild == del_node)
        del_parent->rchild=NULL;
    else
        del_parent->lchild=NULL;
    
    free(del_node);
    return root;
}

tree* del_case_b(tree* root,tree* del_node,tree* del_parent)
{
    if(del_node==root)
    {
        tree* temp=(root->lchild==NULL)?del_node->rchild:del_node->lchild;
        free(del_node);
        return temp;
    }
    
    if(del_parent->lchild==del_node)
        del_parent->lchild=(del_node->lchild==NULL)?del_node->rchild:del_node->lchild;
    else
        del_parent->rchild=(del_node->lchild==NULL)?del_node->rchild:del_node->lchild;
    
    free(del_node);
    return root;
}

tree* del_case_c(tree* root,tree* del_node,tree* del_parent)
{
    tree* succ_node;
    succ_node=del_node->rchild;

    while(succ_node->lchild != NULL)
        succ_node=succ_node->lchild;
    
    del_node->data = succ_node->data;
    if(succ_node==del_node->rchild)
        del_node->rchild=NULL;
    free(succ_node);
    printf("%d",root->data);
    return root;
}
