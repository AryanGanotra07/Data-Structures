#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node * p, int elem)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = elem;
    t->next = NULL;
    if(p==NULL)
    {
        p=t;
        return;
    }
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next = t;
}

int delete(struct node *p)
{
    int x;
    x = p->data;
    if(p->next!=NULL)
    {
    p = p->next;
    }
    return x;

}

int findMax(int A[], int n)
{
    int i, greatest;
    greatest = A[0];
    for(i=0;i<n;i++)
    {
        if(greatest < A[i])
        {
            greatest = A[i];
        }
    }
    return greatest;
}

void binsort(int A[], int n)
{
    int max,i=0,j=0;
    struct node **bins;
    max = findMax(A, n);
    bins = (struct node **)malloc((max+1)*sizeof(struct node));
    for(i=0;i<=max;i++)
    {
        bins[i] = NULL;
    }
    for(i=0;i<n;i++){
        insert(bins[A[i]],A[i]);
    }
     i=0;
    while(i<max+1)
    {
        while(bins[i]!=NULL)
        {
            A[j++] = delete(bins[i]);
         

        }
        i++;
    }

}

int main()
{
    int A[10] = {1,5,2,1,6,3,6,2,5,10};
    int i;
    binsort(A,10);
    for(i=0;i<10;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}