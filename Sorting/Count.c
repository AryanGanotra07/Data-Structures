#include<stdio.h>
#include<stdlib.h>

int findMax(int A[], int n)
{
    int i, greatest;
    greatest = A[0];
    for(i=0;i<n;i++)
    {
        if(greatest < A[i])
        {
            greatest = A[i];
        }
    }
    return greatest;
}

void countsort(int A[], int n)
{
    int max,*t,i=0,j=0;
    max = findMax(A, n);
    t = (int *)malloc((max+1)*sizeof(int));
    for(i=0;i<=max;i++)
    {
        t[i] = 0;
    }
    for(i=0;i<n;i++){
        t[A[i]]++;
    }
     i=0;
    while(i<max+1)
    {
        if(t[i]>0)
        {
            A[j++] = i;
            t[i]--;

        }
        else{
            i++;
        }
    }

}

int main()
{
    int A[10] = {1,5,2,1,6,3,6,2,5,10};
    int i;
    countsort(A,10);
    for(i=0;i<10;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}