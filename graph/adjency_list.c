#include<stdio.h>
#include<stdlib.h>

int v,e;
typedef struct edge
{
    struct vertex* adj;
    struct edge* next;
}edge;
typedef struct vertex
{
    int no;
    struct vertex* next;
    struct edge* adj;
}vertex;

vertex* create(vertex*);
vertex* insert_v(vertex*,vertex*);
edge* insert_a(edge*,edge*);
void display_e(vertex*);
vertex* create_v();
void display_v(vertex*);
void in_e_help(vertex*[],vertex*);
edge* create_e(vertex*);
vertex* search(vertex*,int);
edge* delete_e(edge*,int);
void display_g(vertex*);
vertex* delete_v(vertex*,int);

int main()
{
    int ch;
    vertex* s_vertex=NULL;
    vertex* search_v;
    edge* temp;
    int s,d;
    vertex* arr[2]={0,0};
    do{
        printf("\n\n1)create\n2)insert vertex\n3)insert edge\n4)delete vertex\n5)insert edge\n6)dsiplay\nenter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                s_vertex = create(s_vertex);
                break;
            case 2:
                s_vertex=insert_v(s_vertex,create_v());
                display_v(s_vertex);
                v++;
                break;
            case 3:
                in_e_help(arr,s_vertex);
                if(arr[0] != 0)
                    arr[0]->adj=insert_a(arr[0]->adj,create_e(arr[1]));
                display_e(s_vertex);
                break;
            case 4:
                printf("\nenter vrtex number :");
                scanf("%d",&s);
                s_vertex = delete_v(s_vertex,s);
                break;
            case 5:
                printf("\nenter source and destination vertex :");
                scanf("%d %d",&s,&d);
                search_v= search(s_vertex,s);
                search_v->adj = delete_e(search_v->adj,d);
                break;
            case 6:
                display_g(s_vertex);
                break;
        }
    } while(ch>0 && ch<=6);
    return 0;
}

vertex* create(vertex* s_vertex)
{
    printf("\nenter number of vertex :");
    scanf("%d",&v);

    for(int c1=1;c1<=v;c1++)
    {
        vertex* newnode = (vertex*) malloc(sizeof(vertex));
        newnode->next=NULL;
        newnode->adj=NULL;
        newnode->no=c1;
        s_vertex = insert_v(s_vertex,newnode);
    }

    printf("\nenter number of edges :");
    scanf("%d",&e);
    int s,d;
    for(int c1=1;c1<=e;c1++)
    {
        printf("\nenter source and destination of %d edge :",c1);
        scanf("%d %d",&s,&d);
        if(s<1 || d<1 || s>v || d>v)
        {
            printf("\nINVALID INPUT");
            c1--;
            continue;
        }
        vertex* ptr=s_vertex;
        vertex* s_v,*d_v;
        s_v=d_v=ptr;

        int c2=1;
        while(c2<s || c2<d)
        {
            if(c2<s)
                s_v = ptr->next;
            if(c2<d)
                d_v=ptr->next;
            
            c2++;
            ptr = ptr->next;
        }

        edge* newnode = (edge*) malloc(sizeof(edge));
        newnode->adj=d_v;
        newnode->next=NULL;
        s_v->adj=insert_a(s_v->adj,newnode);
    }
    return s_vertex;
}

vertex* insert_v(vertex* start,vertex* node)
{
    vertex* temp2 = start;
    if(start==NULL)
        return node;
    
    vertex* temp = start;
    while(start->next!=NULL)
        start=start->next;
    
    start->next=node;

    return temp2;
}

edge* insert_a(edge* start,edge* node)
{
    edge* temp =start;
    if(start == NULL)
        return node;

    edge* ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next=node;

    return start;
}

void display_e(vertex* start)
{
    printf("\nList of edge :");
    while(start!=NULL)
    {
        edge* adj = start->adj;
        while(adj!=NULL)
        {
            printf("\nV(%d)----->V(%d)",start->no,adj->adj->no);
            adj = adj->next;
        }
        start = start->next;
    }

    return;
}

vertex* create_v()
{
    vertex* newnode = (vertex*)malloc(sizeof(vertex));
    printf("\nenter vertex number :");
    scanf("%d",&newnode->no);
    newnode->adj=NULL;
    newnode->next=NULL;
    return newnode;
}

void display_v(vertex* s_vertex)
{
    if(s_vertex == NULL)
    {
        printf("\nEMPTY VERTEX LIST !");
        return;
    }

    printf("\nvertex list :");
    while(s_vertex!=NULL)
    {
        printf("V(%d)",s_vertex->no);
        s_vertex = s_vertex->next;
    }

    return;
}

void in_e_help(vertex* arr[],vertex* start)
{
    int s,d;
    printf("\nenter source & destination V of edge :");
    scanf("%d %d",&s,&d);
    if(s<1 || d<1 ||s>v || d>v)
    {
        printf("\ninvalid vertex !");
        return;
    }
    arr[0]=arr[1]=start;

    if(s<0 || d<0 || s>v+1 || d>v+1)
    {
        printf("\ninvalid input");
        in_e_help(arr,start);
    }
    else
    {
        for(int c1=1;c1<s || c1<d;c1++)
        {
            if(c1<s)
            {
                *(arr+0)= start->next;
            }
            if(c1<d)
            {
                *(arr+1)=start->next;
            }
            start = start->next;
        }
    }

    return;
}  

edge* create_e(vertex* node)
{
    edge* newnode = (edge*)malloc(sizeof(edge));
    newnode->next=NULL;
    newnode->adj=node;
    return newnode;
}

void display_g(vertex* start)
{
    if(start == NULL)
    {
        printf("\nempty list !");
        return;
    }
    while(start != NULL)
    {
        edge* ptr = start->adj;
        while( ptr != NULL)
        {
            printf("\nV(%d)-------->V(%d)",start->no,ptr->adj->no);
            ptr = ptr->next;
        }
        start = start->next;
    }

    return;
}

vertex* search(vertex* start,int se)
{
    while(start != NULL && start->no != se)
        start = start->next;
    
    if(start!=NULL)
    {
        return start;
    }
    else
    {
        printf("\nvertex is not founded !");
        return NULL;
    }
}

edge* delete_e(edge* start,int se)
{
    edge* temp,*ptr;
    ptr = start;
    if(start == NULL)
    {
        printf("\nempty list");
        return NULL;
    }
    else if(start->adj->no == se)
    {
        temp = start;
        start = start->next;
        free(temp);
    }
    else
    {
        while( ptr->next != NULL && ptr->next->adj->no != se)
            ptr = ptr->next;
        
        temp = ptr->next;
        ptr->next=ptr->next->next;
        free(temp);
    }

    return start;
}

vertex* delete_v(vertex* start,int se)
{
    if(start == NULL)
    {
        printf("\nempty list !");
        return NULL;
    }

    vertex* ptr = start;
    while(ptr!=NULL)
    {
        ptr->adj = delete_e(ptr->adj,se);
        ptr = ptr->next;
    }

    ptr = start;
    vertex* temp;
    if(ptr->no == se)
    {
        temp = ptr;
        ptr=ptr->next;
        free(temp);
        start = ptr;
    }
    else
    {
        while(ptr->next!=NULL && ptr->next->no!=se)
            ptr = ptr->next;
        
        if(ptr->next==NULL)
        {
            printf("\ninvalid  vertex !");
        }
        else
        {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        }
    }

    return start;
}