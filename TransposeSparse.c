
#include<stdio.h>


void print(int k[3][100], int count){
    int i,j;
    for(j=0 ;j<3;j++){
        for(i=0;i<count;i++){
            printf("%d",k[j][i]);
        }
        printf("\n");
    }
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;




}

void sort(int k[3][100], int count){
    int i,j;
    for(i =0 ;i<count;i++){
        for(j=0;j<count - i -1 ; j++){
            
            if(k[0][j]>k[0][j+1] ){
                
                swap(&k[0][j], &k[0][j+1]);
                swap(&k[1][j], &k[1][j+1]);
                swap(&k[2][j], &k[2][j+1]);
                 }
            else if(k[0][j]==k[0][j+1]){
                if(k[1][j]>k[1][j+1]){
                    swap(&k[0][j], &k[0][j+1]);
                    swap(&k[1][j], &k[1][j+1]);
                    swap(&k[2][j], &k[2][j+1]);
                }
            }

        }
    }

}

void transpose(int k[3][100], int count){
    int i,j, temp;
    printf("\n");
   
        for(j=0;j<count;j++){
        
         swap(&k[0][j],&k[1][j]);
        }
        sort(k,count);
        print(k,count);
}

int main(){
    int a[20][20], k[3][100], i, j, m, n, count=0;
    printf("Enter no of rows");
    scanf("%d",&m);
    printf("Enter no of coloumns");
    scanf("%d",&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]){
                k[0][count] = i;
                k[1][count] = j;
                k[2][count] = a[i][j];
                count++;

            }
        }
    }

    print(k,count);
    

    transpose(k,count);

}
