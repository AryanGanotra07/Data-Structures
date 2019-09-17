#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p,*q;
    p=(int *)malloc(3*sizeof(int));
    p[0]=1;
    p[1]=2;
    p[2]=3;
    q=(int *)malloc(5*sizeof(int));
    q[0]=p[0];
    q[1]=p[1];
    q[2]=p[2];
    free(p);
    p=q;
    q=NULL;
    printf("%d",p[2]);
}