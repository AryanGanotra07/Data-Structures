#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int rear;
    int front;
    int *Q;
};

void create(struct Queue *q, int size){
    q->size=size;
    q->rear=q->front=-1;
    q->Q=(int *)malloc(size*sizeof(int));

}

void enqueue(struct Queue *q, int key){
    if(q->rear==q->size-1){
        printf("Queue is full");
    }
    else{
        q->rear++;
        q->Q[q->rear]=key;

    }
}

int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear){
        printf("Queue is empty");
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

void display(struct Queue q){
    int i;
    for(i=q.front+1;i<=q.rear;i++){
        printf("%d ",q.Q[i]);
    }
}

int main(){
    struct Queue q;
    create(&q,5);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    printf("%d\n",dequeue(&q));

    display(q);
    return 1;
}