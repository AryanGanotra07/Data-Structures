#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 10);

    printf("Enter root value");
    scanf("%d",&x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q) && !isFull(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        printf("Enter right child of %d",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }

}

void Preoder(struct Node *p)
{
    if(p)
    {
        printf("%d",p->data);
        Preoder(p->lchild);
        Preoder(p->rchild);
    }

}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d",p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d",p->data);
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);
    printf("%d ",root->data);
    enqueue(&q, root);
    while(!isEmpty)
    {
        root = dequeue(&q);
        if(root->lchild)
        {
            printf("%d",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int main()
{
    Treecreate();
    LevelOrder(root);
    
}