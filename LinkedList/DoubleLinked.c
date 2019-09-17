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

void insert(struct Node *p, int key, int pos){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    int i;
    if(pos<0 || pos>Length(p)) return;
    if(pos==0){

        t->prev=NULL;
        t->data=key;
        t->next=first;
        first=t;

    }
    else{
        for(i=0;i<pos-1;i++){
            p=p->next;
            }
            t->data=key;
            t->prev=p;
            t->next=p->next;
            if(p->next)
            p->next->prev=t;
            p->next=t;
            
        }
}

int delete(struct Node *p, int pos){
    int x=-1,i;
    if(pos<1 && pos>Length(p)){
        return -1;
    }
     if(pos==1){
            first=p->next;
            free(p);
            if(first)first->prev=NULL;;


        }
        else{
            for(i=0;i<pos-1;i++){
                p=p->next;
            }
            x=p->data;
            p->prev->next = p->next;
           if(p->next) p->next->prev = p->prev;
            free(p); 

        }
        return x;
    
}

void Reverse(struct Node *p){
    struct Node *t;
    while(p){
        t=p->next;
        p->next=p->prev;
        p->prev=t;
        p=p->prev;
        if(p && p->next==NULL){
            first=p;
        }
    }
}

int main(){
    int a[]={0,1,2,3,4,5};
    create(a,6);
   // insert(first,2,2);
    //delete(first,4);
    Reverse(first);
    display(first);
    return 0;
}