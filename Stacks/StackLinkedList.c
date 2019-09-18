#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Overflow");
    }
    else{
        t->data=x;
        t->next=top->next;
        top=t;
    }
}

int pop(){
    int x=-1;
    struct Node *t;
    if(top==NULL){
        return -1;
    }
    t=top;
    x=t->data;
    top=top->next;
    free(t);

    return x;
}

void Display(){
    struct Node *p=top;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    return 1;
}