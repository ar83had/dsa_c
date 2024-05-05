#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    char name[20];
    int age;
    float marks;
    struct student* link;
}st;

st* create(st* start)
{
    start=NULL;
    int n;
    printf("enter the number of nodes in a list :");
    scanf("%d",&n);
    for(int c1=0;c1<n;c1++)
    {
        st* node = (st*) malloc(sizeof(st));
        printf("enter the details of %d student :-\n",c1+1);
        printf("name = ");
        scanf("%s",node->name);
        printf("age = ");
        scanf("%d",&node->age);
        printf("marks = ");
        scanf("%f",&node->marks);
        st* startcpy = start;

        if(startcpy==NULL || startcpy->age > node->age)
        {
            node->link = startcpy;
            startcpy = start = node;
        }
        else
        {
            while(startcpy->link != NULL && startcpy->link->age < node->age)
                startcpy = startcpy->link;

            if(startcpy ->link != NULL)
            {
                node->link = startcpy->link;
                startcpy->link = node;
            }
            else
            {
                startcpy->link = node;
                node->link = NULL;
            }
        }

    }
    return start;
}

void display(st* start)
{
    int c1=1;
    while(start != NULL)
    {
        printf("details of %d student :-\n name = %s\n age = %d\n marks = %f\n",c1++,start->name,start->age,start->marks);
        start = start->link;
    }
    return;
}

st* merge(st* list1,st* list2)
{
    st*p=list1,*q=list2,*r,*list3=NULL,*temp;

    while(p != NULL && q != NULL)
    {
        if(p->age < q->age)
        {
            temp = p->link;
            p->link= NULL;
            if(list3 != NULL)
            {
                r->link = p;
                r = r->link;
            }
            else   
                list3 = r=p;
            p = temp;
        }

        else
        {
            temp = q->link;
            q->link = NULL;
            if(list3 != NULL)
            {
                r->link = q;
                r = r->link;
            }

            else
                list3 = r=q;
            q = temp;
        }
    }

    if(p == NULL)
        r->link = q;
    else    
        r->link = p;

    return list3;
}

int main()
{
    st* list1,*list2,*list3;
    list1 = create(list1);
    list2 = create(list2);
    list3 = merge(list1,list2);

    printf("\n");
    display(list3);
    return 0;
}