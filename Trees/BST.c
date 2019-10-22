#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void insert(int key)
{
    struct Node *t=root;
    struct Node *r, *p;

    if(root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p -> lchild = p -> rchild = NULL;
        p -> data = key;
        return;
    } 
    while (t != NULL) 
    {
        r=t;
        if(key == t->data)
        {
            return;
        }
        else if(key<t->data) t = t->lchild;
        else t = t->rchild;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p -> lchild = p -> rchild = NULL;
    p -> data = key;
    if(key < r->data) r->lchild = p;
    else r->rchild = p;
    
}