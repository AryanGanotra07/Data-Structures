#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int pow;
    struct Node *next;
}*first = NULL, *sec = NULL, *res = NULL;


void display(struct Node *p)
{
    while(p)
    {
        printf("\n%d %d\n",p->coeff,p->pow);
        p = p->next;
    }
}


struct Node * create1(struct Node *p)
{
    printf("\nEnter Polynomial\n");
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
        t -> next = NULL;
        last = t;
        printf("Enter 0/1 to exit/continue");
        scanf("%d",&coeff);
    }
    return p;
   
}

void show(struct Node *node) 
{ 
while(node->next != NULL) 
    { 
    printf("%dx^%d", node->coeff, node->pow); 
    node = node->next; 
    if(node->next != NULL) 
        printf(" + "); 
    } 
} 

void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly) 
{ 
    struct Node *q = poly;
    
while(poly1->next && poly2->next) 
    { 
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is 
        // and move its pointer 
        if(poly1->pow > poly2->pow) 
        { 
            q->pow = poly1->pow; 
            q->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
          
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is 
        // and move its pointer 
        else if(poly1->pow < poly2->pow) 
        { 
            q->pow = poly2->pow; 
            q->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
          
        // If power of both polynomial numbers is same then add their coefficients 
        else
        { 
            q->pow = poly1->pow; 
            q->coeff = poly1->coeff+poly2->coeff; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
          
        // Dynamically create new node 
        q->next = (struct Node *)malloc(sizeof(struct Node)); 
        q = q->next; 
        q->next = NULL; 
    } 
while(poly1->next || poly2->next) 
    { 
        if(poly1->next) 
        { 
            q->pow = poly1->pow; 
            q->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
        if(poly2->next) 
        { 
            q->pow = poly2->pow; 
            q->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
        q->next = (struct Node *)malloc(sizeof(struct Node)); 
        q = q->next; 
        q->next = NULL; 
    } 

    show(poly);

} 

void add(struct Node *firs, struct Node *se)
{
    struct Node *p,*q,*last, *t;
    p = firs;
    q = se;
    // display(p);
    // display(q);
    //  res = (struct Node *)malloc(sizeof(struct Node));
    //  res -> next = NULL;
    // last = res;
    
    
    while(p && q)
    { 
        printf("Entered loop");
        t = (struct Node *) malloc (sizeof(struct Node));
        if(p->pow == q->pow)
        {   
            t->coeff = p->coeff + q->coeff;
            t->pow = q->pow;
            p = p->next;
            q = p->next;
            printf("Entered this condition");

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
        if(res == NULL)
        { 
            res = t;
            last = res;
        }
        else{
            last -> next = t;
            last = t;
        }
        
    }
    // if(p)
    // {
    //     while(p)
    //     {
    //         t = p;
    //         t->next = NULL;
    //         last -> next = t;
    //         last = t;

            
    //     }
    // }
    // if(q)
    // {
    //     while(q)
    //     {
    //          t = q;
    //         t->next = NULL;
    //         last -> next = t;
    //         last = t;

    //     }

    // }
    show(res);
}

int main()
{
    struct Node *p,*q;
    p = create1(first);
    display(p);
  //  display(first);
    q = create1(sec);
    display(q);
    
   // polyadd(p,q,res);
 
    
    add(p,q);
    //display(res);
    
    return 0;
}