#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* pre,*next;
}node;

node* insert(node*);
void traverse(node*);
node* delete(node*);

int main()
{
    int ch;
    node* last=NULL;
    do
    {
        printf("\n1)Insert\n2)Delete\n3)Traverse\nenter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                last = insert(last);
                break;
            case 2:
                last=delete(last);
                break;
            case 3:
                traverse(last);
                break;
        }
    } while (ch>=1 && ch<=3);
    
    return 0;
}

node* insert(node* last)
{
    node* newnode = (node*)malloc(sizeof(node));
    printf("\nenter node data :");
    scanf("%d",&newnode->data);
    node* temp;

    if(last == NULL)
    {
        newnode->next=newnode;
        newnode->pre=newnode;
    }
    else
    {
        temp=last->next;
        while(temp != last)
        {
            temp=temp->next;
        }
        newnode->next=last->next;
        newnode->pre = last;
        last->next->pre = newnode;
        last->next = newnode;
    }

    return newnode;
}

void traverse(node* last)
{
    if(last==NULL)
    {
        printf("\nlist id EMPTY !");
        return;
    }

    node* ptr = last->next;
    do
    {
        printf("->%d",ptr->data);
        ptr=ptr->next;
    }while(ptr!=last->next);
    
    return;
}

node* delete(node* last)
{
    if(last ==NULL)
    {
        printf("\nlist is empty !");
        return NULL;
    }

    int se;
    printf("\nenter delete node data :");
    scanf("%d",&se);

    node* ptr = last->next;
    if(ptr->data == se);
    else
        while(ptr->next->data!=se)
        {
            ptr=ptr->next;
        }

    if(ptr->data == se)
    {
        ptr->next->pre = last;
        last->next=ptr->next;
    }
    else if(ptr->next == last)
    {
        last->next->pre= ptr;
        ptr->next=last->next;
        last=ptr;
    }
    else
    {
        ptr->next->next->pre=ptr;
        ptr->next=ptr->next->next;
    }
    
    return last;
}
