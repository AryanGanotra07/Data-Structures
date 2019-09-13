#include<stdio.h>

int main(){
    char s1[100], s2[100], result[200];
    int i=0,j=0;
    printf("Enter string one:");
    gets(s1);
    printf("Enter string two:");
    gets(s2);
    while(s1[i]!='\0'){
        result[i] = s1[i];
        i++;
    }
    while(s2[j]!='\0'){
        result[i+j]=s2[j];
        j++;
    }
    result[i+j] = '\0';
    printf("\n Resultant string is: \n");
    puts(result);

    return 0;
}