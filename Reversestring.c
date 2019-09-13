#include<stdio.h>


int main(){
    char s[100], rev[100];
    int i=0, len=0;
    printf("Enter string");
    gets(s);
    while(s[i]!='\0'){
        i++;
        }
    len = i;
    for(i=0;i<len;i++){
        rev[i] = s[len-i-1];
    }
    printf("\n Reversed string is \n");
    puts(rev);

    return 0;
}

