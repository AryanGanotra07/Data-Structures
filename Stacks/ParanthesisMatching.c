#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x){
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

char pop(){
    char x=' ';
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
        printf("%c ",p->data);
        p=p->next;
    }
}

int isBalanced(char *exp){
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(exp[i]);
        }
        else if (exp[i]==')')
        {
            if(top==NULL) return 0;
            pop();
        }
        

    }
    if(top==NULL)return 1;
    else
    {
        
        return 0;
    }
    
}
int main(){
    char *exp="((a+b)*(c+d))";
    printf("%d",isBalanced(exp));
    return 1;
}