#include<stdio.h>

int main(){
    char s[100];
    int i=0;
    printf("Enter string");
    gets(s);
    while(s[i]!='\0'){
       
        if(s[i]>='a'&&s[i]<='z'){
            s[i]-=32;
        }
        i++;

    }

    printf("Resultant string is \n");
    puts(s);

}