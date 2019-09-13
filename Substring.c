#include<stdio.h>

int main(){
    char s[100], ss[100];
    int l, sl, i=0, j=0, flag=1;
    printf("Enter string:");
    gets(s);
    printf("Enter substring");
    gets(ss);
    while(s[i]!='\0'){
        if(s[i]==ss[0]){
            flag=1;
            j=0;
            while(ss[j]!='\0'){
                if(s[i+j]!=ss[j]){
                    flag=0;
                    break;
                    
                }
                j++;
            }
        }
        else{
            flag=0;
        }
        if(flag==0){
            i++;
            continue;
        }
        else{
            break;
        }
    }

    if(flag){
        printf("Substring found \n");
    }
    else{
        printf("Substring not found \n");
    }

    return 0;
    
   
}