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

struct Node * RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
       t = (struct Node *)malloc(sizeof(struct Node));
       t -> data = key;
       t -> lchild = t -> rchild = NULL;
       return t;
    }
    if(key < p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = RInsert(p->rchild, key);
    }
    
}

struct Node * Delete(struct Node *p, int key)
{
    struct Node *q;
     if(p==NULL)
        {
            return NULL;
        }
        if(p->lchild == NULL && p->rchild == NULL)
        {
            if(p==root) root = NULL;
            free(p);
            return NULL;
        }

    if(key<p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if(key>p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else{
        if(Height(p->lchild)>Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(q->rchild, q->data);
        }
    }
}

int Height(struct Node *p)
{
    int x,y;
    if(p==NULL)return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x>y?x+1:y+1;
}

struct Node *InPre(struct Node *p)
{
    while(p && p->rchild)
    {
        p = p->rchild;
    }
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while(p && p->lchild)
    {
        p = p->lchild;
    }
    return p;
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