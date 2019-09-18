#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int a*;
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

int main(){
    struct Stack s;
    printf("Enter size of array");
    scanf("%d",&s.size);
    s.a=(int *)malloc(s.size*sizeof(int));
    s.top=-1;
    return 0;
}