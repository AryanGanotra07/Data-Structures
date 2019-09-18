#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int a*;
}

void display(struct Stack s){
    int i;
    for(i=s.top;i>=0;i++){
        printf("%d ",s.a[i]);
    }
}

void push(struct Stack *s, int key){
    if(s->top==s->size){
        printf("Overflow condition");
    }
    else{
        s->top++;
        s->a[top]=elem;
    }
}

int pop(struct Stack *p){
    int x=-;
    if(p->top==-1){
        printf("Underflow condition");
    }
    else{
        x=p->a[p->top];
        p->top--;
    }
    return x;
}

int peek(struct Stack s, int pos){
    int x=-1;
    if(p->top==-1){
        printf("Underflow condition");
    }
    else{
        x=s.a[s.top-pos+1];
    }
    return x;
}

int stackTop(struct Stack s){
    int x=-1;
    if(p->top==-1){
        printf("Underflow condition");
    }
    else{
        x=s.a[s.top];
    }
}

int isFull(struct Stack s){
    if(s.top==s.size-1){
        return 1;
    }
    else{
        return 0;
    }

}

int isEmpty(struct Stack s){
    if(s.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct Stack s;
    printf("Enter size of array");
    scanf("%d",&s.size);
    s.a=(int *)malloc(s.size*sizeof(int));
    s.top=-1;
    return 0;
}