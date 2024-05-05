#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    char name[20];
    int rno;
    int age;
    struct student* link;
}st;

st* create(st*);
void display(st*);
void display_circular(st*);
st* concat(st*,st*);
st* concat_circular(st*,st*);
st* create_circular(st*);

int main()
{
    st* list1=NULL,*list2;

    //list1 = create(list1);                     //create and concatenation of two single link-list;
    // list2 = create(list2);
    // list1 = concat(list1,list2);
    //display(list1);

    list1 = create_circular(list1);               //create and concatenation of two circular linked list;
    list2 = create_circular(list2);
    list1 = concat_circular(list1,list2);
    display_circular(list1);

    return 0;
}

st* create(st*list)
{
    static int c1=1;
    int n;
    st* p=NULL;
    printf("enter the number of elemnt into %d list :",c1++);
    scanf("%d",&n);
    for(int c1=0;c1<n;c1++)
    {
        st* node = (st*) malloc(sizeof(st));
        printf("enter the details of %d student :-\n",c1+1);
        printf("name = ");
        scanf("%s",&node->name);
        printf("roll no = ");
        scanf("%d",&node->rno);
        printf("age = ");
        scanf("%d",&node->age);

        if(list == NULL || p->rno > node->rno)
        {
            node->link = p;
            p = list = node;
        }

        else
        {
            while(p->link != NULL && p->link->rno < node->rno)
                p = p->link;
            
            if(p->link == NULL)
            {
                node->link = NULL;
                p->link=node;
            }
            else
            {
                node->link = p->link;
                p->link = node;
            }
        }   

        p=list;
    }

    return list;
}

void display(st* start)
{
    int c1=1;
    while(start != NULL)
    {
        printf("details of %d student :-\n name = %s\n age = %d\n roll no = %d\n",c1++,start->name,start->age,start->rno);
        start = start->link;
    }
    return;
}

void display_circular(st* list)
{
    if(list == NULL)
    {
        printf("list is empty !!!");
        return;
    }
    st* listcpy = list->link;
    int c1=1;

    printf("detils of %d student :-\nname = %s\n roll no = %d\nage = %d\n\n",c1++,listcpy->name,listcpy->rno,list->age);
    listcpy = listcpy->link;
    while(listcpy != list->link)
    {
        printf("detils of %d student :-\nname = %s\n roll no = %d\nage = %d\n\n",c1++,listcpy->name,listcpy->rno,list->age);
        listcpy = listcpy->link;
    }
    return;
}

st* concat(st* des,st* sor)
{
    if(des == NULL)
        return sor;
    else if(sor == NULL)
        return des;
    st* temp=des;

    while(temp->link != NULL)
        temp = temp->link;
    
    temp->link = sor;
    return des;
}

st* create_circular(st* list)
{
    st* listcpy = list;
    static int c=1;
    int n;
    printf("enter the number of node in %d list :",c++);
    scanf("%d",&n);

    for(int c1=0;c1<n;c1++)
    {
        st* node = (st*)malloc(sizeof(st));
        printf("enter the data of %d student :-\n",c1+1);
        printf("name = ");
        scanf("%s",node->name);
        printf("roll no = ");
        scanf("%d",&node->rno);
        printf("age = ");
        scanf("%d",&node->age);

        if(listcpy == NULL)
        {
            node->link = node;
            listcpy = node;
        }

        else if(listcpy->link == listcpy)
        {
            node->link = listcpy;
            listcpy->link = node;
            if(listcpy->rno < node->rno)
                listcpy = node;
        }

        else
        {
            listcpy = listcpy->link;
            while(listcpy != list && listcpy->link->rno < node->rno)
                listcpy = listcpy->link;
            node->link = listcpy->link;
            listcpy->link = node;
            if(listcpy == list)
                listcpy = node;
        }
        list = listcpy;
    }

    return list;
}

st*concat_circular(st* list1,st* list2)
{
    st* temp;
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    else
    {
        printf("hi");
        temp = list2->link;
        list2->link = list1->link;
        list1->link = temp;
        return list2;
    }
}