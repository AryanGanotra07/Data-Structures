#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int pow;
    struct Node *next;
}*first = NULL, *sec = NULL, *res = NULL;

void create1(struct Node *p)
{
    int i,j, pow, coeff;
    struct Node *last, *t;
    printf("\nEnter coeff\n");
    scanf("%d",&coeff);
    printf("\nEnter pow\n");
    scanf("%d", &pow);
    p = (struct Node *)malloc(sizeof(struct Node));
    p -> coeff = coeff;
    p -> pow = pow;
    last = p;
    printf("Enter 0/1 to exit/continue");
    scanf("%d",&coeff);

    
    while(coeff!=0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter coeff\n");
        scanf("%d",&coeff);
        printf("\nEnter pow\n");
        scanf("%d", &pow);
        t -> pow = pow;
        t -> coeff = coeff;
        last -> next = t;
        t -> next = t;
        last = t;
        printf("Enter 0/1 to exit/continue");
        scanf("%d",&coeff);
    }
   
}

void add()
{
    struct Node *p,*q,*last, *t;
    p = first;
    q = sec;
    res = (struct Node *)malloc(sizeof(struct Node));
    res -> next = NULL;
    last = res;

    while(p || q)
    {
        t = (struct Node *) malloc (sizeof(struct Node *));
        if(p->pow == q->pow)
        {   
            t->coeff = p->coeff + q->coeff;
            t->pow = q->pow;
            
            p = p->next;
            q = p->next;

        }
        else if(p->pow > q->pow)
        {
            
            t = p;
            p = p->next;
        }
        else
        {
            t = q;
            q = q->next;
        }
        t->next = NULL;
        last -> next = t;
        last = t;
    }
    if(p)
    {
        while(p)
        {
            t = p;
            t->next = NULL;
            last -> next = t;
            last = t;

            
        }
    }
    else if(q)
    {
        while(q)
        {
             t = q;
            t->next = NULL;
            last -> next = t;
            last = t;

        }

    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("\n%d %d\n",p->coeff,p->pow);
        p = p->next;
    }
}

int main()
{
    create1(first);
    display(first);
    create1(sec);
    display(sec);
    return 0;
}