#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*first=NULL, *last=NULL;

void create()
{
    first = last = NULL;

    
}

void enqueue(int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp ->data = x;
    if(last == NULL)
    {
        first = last = temp;
        return;
    }
    temp->next = last ->next;
    last->next = temp;
    last = temp;
}

int dequeue()
{
    int x;
    struct Node *temp;
    if(first == NULL)
    {   
        printf("Empty Queue");
        return -1;
    }
    x = first->data;
    temp = first;
    free(temp);
    first = first -> next;
    if(first == NULL)
    {
        last = NULL;
    }
    return x;
    
}

int isEmpty()
{
    return first==last;
}

void BFS(int G[7][7], int start, int n)
{
    int i = start, j;
    int visited[7] = {0};
    printf("%d ", i);
    enqueue(i);
    visited[i] = 1;
    while(!isEmpty)
    {
        i = dequeue();
        for(j=1;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==1)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

}

int main()
{   
    int G[7][7] = {{0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0},
                   {0,1,0,0,1,0,0},
                   {0,1,0,0,1,0,0} ,
                   {0,0,1,1,0,1,1},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0}};

    BFS(G,1,7);

    return 0;
}