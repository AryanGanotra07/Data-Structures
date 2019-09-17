#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    struct Node *t,*last;
    int i;
    first = (struct Node*)malloc(sizeof(struct Node));
    first -> data=A[0];
    first->next=first->prev=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
}

}

void display(struct Node *p){
    while (p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    
}
int Length(struct Node *p){
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

int main(){
    int a[]={0,1,2,3,4,5};
    create(a,6);
    display(first);
    return 0;
}