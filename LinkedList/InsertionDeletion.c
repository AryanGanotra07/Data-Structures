#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *next;
    int data;
}*first = NULL;

void create(int A[], int size)
{
    int i;
    struct Node *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(i=1;i<size;i++)
    {
        struct Node *t;
        t = (struct Node *) malloc (sizeof(struct Node));
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void display()
{
    printf("\n");
    struct Node *p = first;
    while(p)
    {
        printf(" %d ",p->data);
        p=p->next;
    }
}

void insert(int key, int index)
{
    struct Node *p = first;
    struct Node *t, *q;
    int i;
    t = (struct Node *) malloc(sizeof(struct Node));
    t -> data = key;
    if(index == 0)
    {
        t->next = p ;
        
        first = t;
    }
    else 
    {
        for(i=0; i<index ; i++)
            {
                if(p)
                {
                q=p;
                p=p->next;
                }
                else
                {
                    printf("\nIndex out of range\n");
                    return;
                }
            }
        q->next = t;
        t->next = p;

    }
}

int delete(int index)
{
    int x, i;
    struct Node *p = first;
    struct Node *q;
    if(index == 0)
    {
        x = p->data;
        first = p->next;
        free(p);
        return x;
    }
    for(i=0;i<index;i++)
    {   
        if(p)
        {
        q=p;
        p = p->next;
        }
        else{
            return -1;
        }
    }
    x = p->data;
    q->next = p->next;
    free(p);
    return x;
}


int main(){
int A[] = {1,4,5,6,2,0, 5, 10};
int size = 8;
int ch, index, elem;
 create(A,size);
 display();
// printf("\n");
// insert(12,0);
// display();
// printf("\n");
// insert(12,2);
// display();
// printf("\n");
// delete(3);
// display();

while(ch!=3)
{
    printf("\nEnter Choice:\n1.Insert\n2.Delete\n3.Exit\n");

    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter Element to insert\n");
            scanf("%d",&elem);
            printf("\nEnter Position/Index\n");
            scanf("%d",&index);
            insert(elem, index);
            display();
            break;
        case 2:
            printf("\nEnter index to delete\n");
            scanf("%d",&index);
            delete(index);
            display();
            break;
        




    }
}
}