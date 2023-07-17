#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char* generator(){
    int i,length = rand()%3+1;
    char *str = (char*) malloc((length+1)*sizeof(char));
    for(i=0;i<length;i++){
        if(rand()%2==0) str[i] = '0';
        else str[i] = '1';
    }
    str[i] = '\0';
    return str;
}
int check_palindrome(char* str){
    int flag = 1;
    for(int i=0,j=strlen(str)-1;i<strlen(str)/2;i++,j--){
        if(str[i]!=str[j]) flag = 0;
    }
    return flag;
}
int main(){
    srand(time(0));
    char* str = generator();
    printf("%s\n",str);
    int length = strlen(str);
    if(check_palindrome(str)) printf("The string is a palindrome\n");
    else printf("The string is not a palindrome\n");
    
    return 0;
}