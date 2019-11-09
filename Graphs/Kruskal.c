#include<stdio.h>
#include<stdlib.h>
#define I 32767

int edges[3][9] = {{1,1,2,2,3,4,4,5,5},
            {2,6,3,7,4,5,7,6,7},
            {25,5,12,10,8,16,14,20,18}};
int included[9] = {0};
int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int t[2][6]; 
void Union(int u, int v)
{
    if(set[u]<set[v])
    {
        set[u] = set[u] + set[v];
        set[v] = set[u];
    }
    else
    {
        set[v] = set[v] + set[u];
        set[u] = set[v];
    }
}
int find(int u)
{
    int x = u,v=0;
    while(set[x]>0)
    {
        x = set[x];
    }
    while(u!=x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

int main()
{
    int i,min,u,v,j=0,k;
    while(j<6)
    {
    min = I;
    for(i=0;i<9;i++)
    {
        if(included[i]==0 && edges[2][i]<min)
        {
            min=edges[2][i];
            u = edges[0][i];
            v = edges[1][i];
            k = i;
        }
    }
    if(find(u)!=find(v))
    {
        t[0][j] = u;
        t[1][j] = v;
        Union(find(u),find(v));
        j++;
    }
    included[k] = 1;
    }
    for(j=0;j<6;j++)
    {
        printf("(%d,%d)",t[0][j],t[1][j]);
    }
    return 0;
}