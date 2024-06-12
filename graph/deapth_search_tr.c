//performe depth search traversal
//both way recurively and non recurively

#include "graph.h"
#define is_underflow (top==-1)?1:0

int** adj;
int top=-1;
int* state;
int* stack;

 void  dft(int);
 void push(int);
 int pop();

int main()
{

    adj = create();
    state = (int*) calloc(v,sizeof(int));
    stack=(int*)malloc(sizeof(int)*v);

    printf("\nadjency matrix :-");
    display_adj(adj);
    
    printf("\nlist of vertex's :");
    dft(0);
    return 0;
}

// void dft(int s_v)    //recurevely
// {
//     printf(" %d",s_v);
//     state[s_v]=1;
//     for(int c1=0;c1<v;c1++)
//     {
//         if(adj[s_v][c1] && !state[c1])
//         {
//             dft(c1);
//         }
//     }
//     return;
// }

void dft(int s_v)    //non recursively
{
    push(0);
    state[0]=1;
    while(!is_underflow)
    {
        int pop_el = pop();
        if(!state[pop_el])
            printf("%d",pop_el);

        state[pop_el]=1;
        for(int c1=v-1;c1>=0;c1--)
        {
            if(adj[pop_el][c1] && !state[c1])
            {
                push(c1);
            }
        }
    }
    return;
}

void push(int el)
{
    if(top==v-1)
    {
        printf("OVERFLOW !");
        return;
    }
    stack[++top]=el;
    return;
}

int pop()
{
    if(is_underflow)
    {
        printf("\nUNDERFLOW !");
        return -1;
    }

    return stack[top--];
}