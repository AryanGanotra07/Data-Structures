#include<stdio.h>
#include<stdlib.h>
#define I 32767

int A[][8]=
{{I,I,I,I,I,I,I,I},
{I,I,25,I,I,I,5,I},
{I,25,I,12,I,I,I,10},
{I,I,12,I,8,I,I,I},
{I,I,I,8,I,16,I,14},
{I,I,I,I,16,I,20,18},
{I,5,I,I,I,20,I,I},
{I,I,10,I,14,18,I,I}};
int next[8] = {I,I,I,I,I,I,I,I}, t[2][7];

int main()
{
    int i, j, s=I, r, c;
    for(i=1;i<8;i++)
    {
        for(j=i;j<8;j++)
        {
            //printf("%d ",A[i][j]);
            if(A[i][j]<s)
            {
                s = A[i][j];
                r = i;
                c = j;
                //printf("Smallest is %d\n",s);

            }
        }
    }
    next[r] = 0;
    next[c] = 0;
    t[0][0] = r;
    t[1][0] = c; 
    for(i=1;i<8;i++)
    {
        if(next[i]!=0)
        {
        if(A[i][r]<A[i][c])
        {
            next[i] = r; 
        }
        else
        {
            next[i] = c;
        }
        }
    }
    
   for(j=1;j<7;j++)
   {

    s = I;
    for(i=1;i<8;i++)
    {
        if(A[i][next[i]]<s)
        {
            s = A[i][next[i]];
            r = i;
            c = next[i];
        }
    }
    t[0][j] = r;
    t[1][j] = c;
    next[r] = 0;

    for(i=1;i<8;i++)
    {
        if(next[i]!=0)
        {
            if(A[i][r]<A[i][c])
            {
                next[i] = r;
            }
        }
    }
   }

   for(i=0;i<6;i++)
    {
        printf("(%d,%d)",t[0][i],t[1][i]);
       // printf("%d",next[i]);
    }

    

    return 0;
}