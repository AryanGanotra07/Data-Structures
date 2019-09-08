#include<stdio.h>
void swap(int *a, int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void print(int s[], int n){
    int i;

    for(i=0;i<n;i++){
        printf("%d",s[i]);
    }
    printf("\n");
}
int main(){
    int l[20], i, j, n;
    char order;
    printf("Enter length of array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&l[i]);
    }
    printf("Enter order a/d:");
    scanf(" %c",&order);
    if(order == 'a'){
        for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(l[j]>l[j+1]){
                    swap(&l[j+1],&l[j]);
                }
            }
        }
        print(l,n);
    }
    else if(order == 'd'){
        for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(l[j]<l[j+1]){
                    swap(&l[j+1],&l[j]);
                }
            }
        }
        print(l,n);
        }
    else{
        printf("Wrong choice");
    }
    return 0;

    }

