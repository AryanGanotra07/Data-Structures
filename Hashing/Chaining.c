#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


void SortedInsert(struct node *H,int x)
{
 
    struct node *t,*q=NULL,*p=H;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(H==NULL)
    {
    H=t;
    }
    while(p && p->data<x)
    {
    q=p;

    p=p->next;
    }
    if(p==H)
    {
    t->next=H;
    H=t;
    }
    else
    {
    t->next=q->next;
    q->next=t;
    }
    }

    
struct node *Search(struct node *p,int key)
    {
    while(p!=NULL)
    {
    if(key==p->data)
    {
        return p;
    }
    p=p->next;
    }
    return NULL;  
 }

int hash(int key)
{
    return key%10;
}
void insert(struct node *H[],int key)
{
    int index = hash(key);
    SortedInsert(H[index], key);
}

int main()
{
    struct node *HT[10];
struct node *temp;
int i;
for(i=0;i<10;i++)
HT[i]=NULL;
insert(HT,12);
insert(HT,22);
insert(HT,42);
temp=Search(HT[hash(22)],22);
printf("%d ",temp->data);
return 0;
}