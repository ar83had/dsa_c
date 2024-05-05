#include"tree.h"

int tree_height(tree*);

int main()
{
    list* inorder,*preorder;
    int n;
    printf("\nenter number of node :");
    scanf("%d",&n);
    printf("\nenter inorder equation :");
    inorder = linked_list(inorder,n);
    printf("\nenter preorder equation :");
    preorder = linked_list(preorder,n);

    tree* root;
    root = create_tree(preorder,inorder,n);

    int he = tree_height(root);
    printf("%d",he);
    return 0;
}

int tree_height(tree* root)
{
    if(root==NULL)
        return 0;
    
    int l_he = tree_height(root->lchild);
    int r_he = tree_height(root->rchild);
    return (l_he > r_he)? l_he+1 : r_he+1;
}