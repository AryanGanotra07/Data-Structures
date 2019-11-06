#include<stdio.h>
#include<stdlib.h>

void insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    while(i>1 && temp>A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int delete(int A[], int n)
{
    int val, last, i, j, temp;
    val = A[1];
    last = A[n];
    A[1] = last;
    i = 1;
    j = 2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j])
        {
            j = j+1;
        }
        if(A[i]<A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i=j;
            j=2*i;
        }
        else
        {
            break;
        }
       
    }
     A[n] = val;
    return val;
    

}

int main()
{
    int A[] = {0,1,3,2,4,5,6,10}; 
    int n, i;
    A[0] = 0;
    
    for(i=2;i<=7;i++)
    {
        insert(A,i);
    }

    for(i=1;i<=7;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

    

    for(i=7;i>1;i--)
    {
        delete(A,i);
    }

      for(i=1;i<=7;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

    

    
    return 0;
}