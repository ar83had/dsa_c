#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct vegetable
{
    int code;
    struct vegetable* next;
}veg;

void display(veg*);
void selection_short(veg*);
void insertion_short(veg*);
void insertion_bubblole(veg*);

int main()
{
    veg v3 = {63,NULL};
    veg v2= {34,&v3};
    veg v1 = {45,&v2};
    veg* start = &v1;

    //selection_short(start);

    //insertion_short(start);

    insertion_bubblole(start);
    display(start);

    
    return 0;
}
void display(veg* start)
{
    int c1=1;
    while(start != NULL)
    {
        printf("details of %d vegetable :-\ncode = %d\n\n",c1++,start->code);
        start = start->next;
    }
    return;
}

void selection_short(veg* start)
{
    while(start->next != NULL)
    {
        veg* min_no = start;
        veg* com = start->next;
        while(com != NULL)
        {
            if(com->code < min_no->code)
                min_no = com;
            com  = com->next;
        }
        int temp = start->code;
        start->code = min_no->code;
        min_no->code = temp;
        start = start->next;
    }
}

void insertion_short(veg* start)
{
    veg* shorted = start;
    start = start->next;
    while(start != NULL)
    {
        int next = start->code;
        veg* startcpy = start;
        while(shorted != NULL)
        {
            if(shorted->code > next)
                start->code = shorted->code;
            else
                shorted->next->code=next;
            shorted = shorted->next;
        }
        shorted = startcpy;
        start = startcpy->next;
        start = start->next;
    }
    return;
}

void insertion_bubblole(veg* start)
{
    veg* fix = start;
    while(start->next != NULL)
    {
        veg* start2 = fix;
        while(start2->next != NULL)
        {
            if(start2->code > start2->next->code)
            {
                int temp = start2->code;
                start2->code = start2->next->code;
                start2->next->code = temp;
            }
            start2 = start2->next;
        }
        start = start->next;
    }
    return;
}
