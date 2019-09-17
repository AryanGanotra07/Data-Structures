#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[5][5],i,j;
    int *p[3],**c;
    /*
    p[0]=(int*)malloc(3*sizeof(int));
    p[1]=(int*)malloc(3*sizeof(int));
    p[2]=(int*)malloc(3*sizeof(int));
    p[0][0]=5;
    p[0][2]=5;
    */
    c=(int**)malloc(3*sizeof(int));
    c[0] = (int*)malloc(3*sizeof(int));
    c[1] = (int*)malloc(3*sizeof(int));
    c[2] = (int*)malloc(3*sizeof(int));




    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");

    }



    return 0;
}