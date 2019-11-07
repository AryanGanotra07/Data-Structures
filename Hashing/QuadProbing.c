#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int hash(int key)
{
    return key%SIZE;
}

int prob(int A[], int key)
{
    int i, index;
    i=0;
    index = hash(key);
    while(A[(index+i*i)%SIZE]!=0)
    {
        i++;
    }
    return (index+i)%SIZE;
}

void insert(int A[], int key)
{
    int index;
    index = hash(key);
  
    if(A[index]!=0)
    {
        index = prob(A, key);
    }
    A[index] = key;
}

int search(int A[], int key)
{
    int i, index;
    i = 0;
    index = hash(key);
    while(A[(index+i*i)%SIZE]!=key)
    {
        i++;
    }
    return (index+i)%SIZE;
}

int main(){
    int A[10] = {0};
    insert(A,14);
    insert(A,25);
    insert(A,35);
    printf("Key 35 is found at %d ",search(A,35));
    return 0;
}