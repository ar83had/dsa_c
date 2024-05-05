#include<stdio.h>
#include<stdlib.h>


//code was incomplete 80% of code complete;

typedef struct red_black_tree
{
    int data;
    struct red_black_tree* r_child;
    struct red_black_tree* l_child;
    struct red_black_tree* parent;
    enum {red=1,black=0} color;
}rb_tree;

rb_tree* rb_create(rb_tree*);
rb_tree* insert(rb_tree*,rb_tree*);
void convert_rbt(rb_tree*,rb_tree*);
rb_tree* l_rotate(rb_tree*);
rb_tree* r_rotate(rb_tree*);
void inorder(rb_tree*);

rb_tree special;
rb_tree* main_root;
int flag_2=0;

int main()
{
    rb_tree* root=&special;
    special.data=-1;
    special.color=black;
    root=rb_create(root);

    inorder(root);
    return 0;
}

rb_tree* rb_create(rb_tree* root)
{
    int n;
    printf("\nenter number of node :");
    scanf("%d",&n);

    rb_tree* temp=root;
    rb_tree* parent=NULL;
    for(int c1=0;c1<n;c1++)
    {
        rb_tree* node=(rb_tree*)malloc(sizeof(rb_tree));
        printf("enter %d node data :",c1+1);
        scanf("%d",&node->data);
        node->l_child=node->r_child=&special;
        node->parent=&special;
        node->color=red;

        rb_tree* temp=insert(root,node);
        if(temp==NULL)
            c1--;
        else
            root=temp;
    }

    return root;
}

rb_tree* insert(rb_tree* root,rb_tree* node)
{
    rb_tree* parent=NULL;
    rb_tree* temp=root;
    if(root==&special)
    {
        node->color=black;
        return node;
    }
    
    while(temp != &special)
    {
        parent=temp;
        if(temp->data == node->data)
        {
            printf("\nDUPLICATE DATA !");
            return NULL;
        }
        else if(temp->data >  node->data)
            temp=temp->l_child;
        else if(temp->data < node->data)
            temp=temp->r_child;
    }

    if(parent->data >  node->data)
    {
        node->parent=parent;
        parent->l_child=node;
    }
    else 
    {
        node->parent=parent;
        parent->r_child=node;
    }

    if(parent->color != black)
        convert_rbt(parent,node);
    if(flag_2)
    {
        main_root->color=black;
        return main_root;
    }
    else
    {
        root->color=black;
        return root;
    }
}

void convert_rbt(rb_tree* root,rb_tree* child)
{
    rb_tree* grand_p=root->parent;
    rb_tree* parent=root;
    rb_tree* uncle=(parent->data < grand_p->data)?grand_p->r_child:grand_p->l_child;
    rb_tree* grand_grand_p=grand_p->parent;
    int round_2=1;

    while(parent->color==red)
    {
        if(uncle->color==red && parent->color==red)
        {
            grand_p->color=red;
            parent->color=uncle->color=black;
            round_2=0;
        }
        else if(grand_p->l_child==parent && parent->r_child==child) //obviously uncle is black;
        {
            grand_p->l_child=l_rotate(parent);
        }
        else if(grand_p->r_child==parent && parent->l_child==child)
        {
            grand_p->r_child=r_rotate(parent);
        }
        printf("\n");
        inorder(root);
        printf("\n");

        if(round_2)
        {
            if(grand_p->l_child==parent)
            {
                grand_p->color=red;
                parent->color=black;
                if(grand_grand_p==&special)
                {
                    main_root=r_rotate(grand_p);
                    flag_2=1;
                }
                else
                {
                    if(grand_grand_p->l_child==grand_p)
                        grand_grand_p->l_child=r_rotate(grand_p);
                    else    
                        grand_grand_p->r_child=r_rotate(grand_p);
                }
            }
            else if(grand_p->r_child==parent)
            {
                grand_p->color=red;
                parent->color=black;
                if(grand_grand_p==&special)
                {
                    main_root=l_rotate(grand_p);
                    flag_2=1;
                }
                else
                {
                    if(grand_grand_p->l_child=grand_p)
                        grand_grand_p->l_child=l_rotate(grand_p);
                    else
                        grand_grand_p->r_child=l_rotate(grand_p);
                }
            }
        }

        child=parent;
        parent=grand_p;
        grand_p=grand_grand_p;
    }
    return;
}


rb_tree* l_rotate(rb_tree* root)
{
    rb_tree* temp=root->r_child;
    root->r_child=root->r_child->l_child;
    temp->l_child=root;
    return temp;
}

rb_tree* r_rotate(rb_tree* root)
{
    rb_tree* temp=root->l_child;
    root->l_child=root->l_child->r_child;
    temp->r_child=root;
    return temp;   
}

void inorder(rb_tree* root)
{
    if(root==&special)
    {
        return;
    }
    inorder(root->l_child);
    printf("%d(%d)",root->data,root->color);
    inorder(root->r_child);
    return;
}