#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    char name[20];
    int age;
    int rno;
    struct student *next;
}st;

void display(st *);
st* short_selection(st*);
st* bubble(st*);

int main()
{
    int n;
    printf("enter the number of element :");
    scanf("%d",&n);

    st* start,*fix;
    start=fix=NULL;
    for(int c1=0;c1<n;c1++)
    {
        st* node= malloc(sizeof(st));
        printf("enter the details of %d student(name,age,roll no) :-\n",c1+1);
        scanf("%s%d%d",node->name,&node->age,&node->rno);
        if(c1==0)
            fix=start=node;
        else
        {
        start->next = node;
        start = start->next;
        }
        node->next=NULL;
    }
    start=fix;

    start = short_selection(start);           //selection shorting in linked list by node reference ; 
    display(start);

    // start = bubble(start);                    //bullble shorting in linked list by node referenece;
    // display(start);
    return 0;

}
void display(st* start2)
{
    if(start2==NULL)
    {
        printf("empty list !!!");
        return;
    }
    while(start2 != NULL)
    {
        printf("name = %s\nage = %d\nroll no = %d\n\n",start2->name,start2->age,start2->rno);
        start2=start2->next;
    }
    return;
}



st* short_selection(st* start)
{
    st* p,*q,*r,*s,*temp;
    for(p = r=start;p->next != NULL;r=p,p=p->next)
    {
        for(q=s=p->next;q != NULL;s=q,q=q->next)
        {
            if(p->rno > q->rno)
            {
                st*temp=p->next;
                p->next = q->next;
                q->next = temp;
                if(p!= start)
                    r->next = q;
                else
                    start = q;
                s->next = p;
                temp = p;
                p = q;
                q = temp;
            }
        }
    }
    return start;
}


st* bubble(st* start)
{
    st* end,*pre,*p,*q,*temp;
    if(start==NULL)
        return start;
    for(end= NULL;end != start->next;end = q)
    {
        for(p=start;p->next != end;pre=p,p=p->next)
        {
            q=p->next;
            if(p->rno > q->rno )
            {
                p->next = q->next;
                q->next=p;
                if(p!=start)
                    pre->next = q;
                if(p==start)
                    start=q;
                temp = p;
                p=q;
                q=temp;   
            }
        }
    }
    return start;
}