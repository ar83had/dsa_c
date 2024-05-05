#include<stdio.h>
#include<stdlib.h>

typedef struct charcter
{
    int value;
    int frequency;
}cha;

typedef struct hoffan_tree
{
    int weight;
    char ch;
    struct hoffan_tree* l_child,*r_child;
}tree;

cha freq[20];
tree* stack[20];
int top=0;


int find_frequency(char[]);
int binary_search(char,int);
tree* hoffan_tree(int);
tree* pop();
void display(tree*);
void insert(tree*);
void insertion_short(int);

int main()
{
    char str[20];
    printf("enter your string :");
    scanf("%[^\n]s",str);

    int freq_size=find_frequency(str);

    printf("\n");

    tree* root = hoffan_tree(freq_size);
    return 0;
}

int find_frequency(char str[])
{
    int c1=0;
    int index=1;
    int find=-1;
    while(str[c1]!=0)
    {
        if(index!=1)
            find=binary_search(str[c1],index);

        if(find!=-1)
            freq[find].frequency+=1;
        else
        {
            freq[index].value=str[c1];
            freq[index++].frequency=1;
        }
        c1++;
    }
    return index;
}

int binary_search(char el,int index)
{
    int st=0;
    int en=index;
    int mid=st+en/2;
    while(st <= en)
    {
        if(el==freq[mid].value)
            return mid;
        else if(el > freq[mid].value)
            st=mid+1;
        else if(el < freq[mid].value)
            en=mid-1;
        
        mid=(st+en)/2;
    }
    return  -1;
}

tree* pop()
{
    if(top==-1)
    {
        printf("\nUNDERFLOW !");
        return NULL;
    }

    return stack[top--];
}

void display(tree* root)
{
    if(root==NULL)
        printf("\nEMPTY TREE !");
    else
    {
        stack[top++]=root;
        printf("\n");
        while(top!=-1)
        {
            printf("%c->%d\n",root->ch,root->weight);
            if(root->r_child!=NULL)
                stack[top++]=root->r_child;
            
            if(root->l_child!=NULL)
                stack[top++]=root->l_child;
        }
    }
    return;
}

tree* hoffan_tree(int size)
{
    for(int c1=1;c1<size;c1++)
    {
        printf("1");
        tree* node = (tree*)malloc(sizeof(tree));
        node->ch=freq[c1].value;
        node->weight=freq[c1].frequency;
        node->l_child=node->r_child=NULL;
        insert(node);
        printf("2%c",node->ch);
    }

    while(top!=1)
    {
        printf("%d",top);
        tree* a = pop();
        tree* b = pop();
        tree* node = (tree*)malloc(sizeof(tree));
        node->ch=0;
        node->weight=a->weight+b->weight;
        node->l_child=a;
        node->r_child=b;
        insert(node);
    }

    tree* temp = pop();
    printf("%d",temp->weight);
    display(temp);
}

void insert(tree* node)
{
    top++;
    int c1=top;
    tree* temp = node;
    int c2 = c1-1;
    if(top==1)
        stack[1]=node;
    else
    {    
        while(stack[c2]->weight < temp->weight && top > 0)
        {
            stack[c2+1] = stack[c2];
            c2--;
        }
    }
    stack[c2+1]=temp;
    return;
}