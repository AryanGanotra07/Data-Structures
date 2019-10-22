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
        root = p;
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

struct Node * search(int key)
{
    struct Node *t = root;
    while(t != NULL)
    {
        if(t->data = key)
        {
            return t;
        }
        else if(key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

int main()
{
    insert(50);
    insert(20);
    insert(60);
    insert(10);
    insert(5);
    insert(100);
    inorder(root);
    return 0;
}