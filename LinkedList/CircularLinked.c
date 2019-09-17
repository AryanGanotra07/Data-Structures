#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    Head=(struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;    

    }
    }

void display(struct Node *h){
    do{
        printf("%d",h->data);
        h=h->next;
    }
    while(h!=Head);
    printf("\n");
}

void Rdisplay(struct Node *h){
    static int flag=0;
    if(h!=Head || flag==0){
        flag=1;
        printf("%d",h->data);
        Rdisplay(h->next);
    }
    flag=0;
}

int Length(struct Node *p){
    int l=0;
    do{
        l++;
        p=p->next;
    }
    while (p!=Head);
    return l;    
}

void insert(struct Node *h, int key, int pos){
    int i;
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(pos>=0 && pos<=Length(h)){
    if(pos == 0){
        t->data=key;
        if(Head==NULL){
            Head = t;
            Head->next = Head;
        }
        else{
            
            while(h->next!=Head){
                h=h->next;
            }
            t->next = Head;
            h->next=t;
            Head=t;

        }
    }
    else{

    for(i=0;i<pos-1;i++){
        h=h->next;
        }
        t->data=key;
        t->next=h->next;
        h->next=t;
        
}

    }

}

int delete(struct Node* p, int pos){
    int x=-1,i;
    struct Node *q;
    if(pos<0 || pos>Length(p)){
        return -1;
    }
    else{
        if(pos==1){
            x=Head->data;
            while(p->next!=Head){
                p=p->next;
            }
            if(Head==p){
                free(Head);
                Head=NULL;
            }
            else{
                p->next=Head->next;
                free(Head);
                Head=p->next;
            }

        }
        else{
            for(i=0;i<pos-2;i++){
                p=p->next;
            }
            q=p->next;
            x=q->data;
            p->next=q->next;
            free(q);

        }
        return x;
    }
}

int main(){
    int A[]={0,1,2,3,4,5};
    create(A,6);
    insert(Head, 3, 0);
   // delete(Head,1);
    Rdisplay(Head);
    return 0;
}