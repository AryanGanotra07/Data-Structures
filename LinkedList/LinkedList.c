#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int a[],int n){
    struct Node *last,*t;
    int i;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last = first;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}

void Rdisplay(struct Node *p){
    if(p!=NULL){
        printf("%d",p->data);
        Rdisplay(p->next);
    }
}

void reverseDisplay(struct Node *p){
    if(p!=NULL){
        reverseDisplay(p->next);
        printf("%d",p->data);
    }
}

int count(struct Node *p){
    if (p==NULL) return 0;
    return 1+count(p->next);
}
int sum(struct Node *p){
    if (p==NULL) return 0;
    return sum(p->next)+p->data;
}

int max(struct Node *p){
    int max = INT32_MIN;
    while (p!=NULL)
    {
      if(p->data>max){
          max=p->data;
      }
    }
    return max;
    
}

int Rmax(struct Node *p){
    int x=0;
    if(p==NULL) return INT32_MIN;
    x=Rmax(p->next);
    if(x>p->data) return x;
    else return p->data;
}

struct Node* Lsearch(struct Node *p,int key){
    struct Node *q;
    while(p!=NULL){
        if(key == p->data){
            q->next = p->next;
            p->next=first;
            first=p;

            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

struct Node* RLsearch(struct Node *p, int key){
    if(p==NULL) return NULL;
     if(key==p->data){
            printf("Found");
            return p;
        }
        return RLsearch(p->next,key);
    }

void insert(struct Node *p, int pos, int key){
    struct Node *t;
    int i;
    if(pos < 0 || pos > count(p)) return;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data=key;
    if (pos == 0)
    {
       t->next = first;
       first = t;
    }
    else{
        for(i=0;i<pos-1;i++) p=p->next;
        t->next = p->next;
        p->next =t;
    }
    


}
/*
void append(struct Node *p, int key){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=key;
    t->next=NULL;
    if(first==NULL){
        first = last = NULL;
    }
    else{
        last->next = t; 
        last = t;
    }
}
*/

void sortedInsert(struct Node *p, int key){
    struct Node *t,*q;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=key;
    if(p==NULL){
        first = t;
    }
    else{

    while(p->data<key && p!=NULL){
        q=p;
         p=p->next;
        }
        if(p==first){
            t->next = first;
            first =t;
        }else{

         t->next = q->next;
        q->next = t;
        }
    

}
}

int delete(struct Node *p, int pos){
    int i,x=-1;
    struct Node *q=NULL;
    if(pos<1 || pos>count(p)) return -1;
  else{  if(pos==1){
        first = p->next;
        x=p->data;
        free(p);
    }
    else{
        for(i=0;i<pos-1;i++){
            q=p;
            p=p->next; 
        }
        if(p!=NULL){
        q->next = p->next;
        x=p->data;
        free(p);
        }

    }
    return x;
}

}

int checkSorted(struct Node* p){
    struct Node *q;
    while(p!=NULL){
        q=p;
        p=p->next;
        if(p!=NULL){
        if(p->data < q->data){
            return 0;
        }
        }
        
    }
    return 1;
}

void removedup(struct Node *p){
    struct Node *q;
    q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q=p->next;
            
        }
    }
}

void reverseElem(struct Node *p){
    int a[20],i=0;
    while(p!=NULL){
        a[i]=p->data;
        i++;
        p=p->next;
    }
    p=first;
    i--;
    while(p!=NULL){
        p->data=a[i--];
        p=p->next;
}
}

void reversePointers(struct Node *p){
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first=q;
}

void recReverse(struct Node *q, struct Node *p){
    if(p!=NULL){
        recReverse(p,p->next);
        p->next = q;
    }
    else{
        first=q;
    }

}

int main(){
    int a[]={0,1,2,2,3,3,4,6,6};
    create(a,9);
    printf("\n");
    reverseDisplay(first);
    printf("\n");
    printf("%d",sum(first));
    printf("\n");
    printf("%d",Rmax(first));
    RLsearch(first,4);
    //insert(first,4,10);
   // sortedInsert(first,5);
   // delete(first,3);
    printf("\n");
   // printf("%d",checkSorted(first));
   // removedup(first);
   //reversePointers(first);
   recReverse(NULL,first);
    printf("\n");
    display(first);
    return 0;
}