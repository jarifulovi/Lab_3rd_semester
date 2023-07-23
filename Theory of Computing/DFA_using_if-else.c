#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// ends with 00
int DFA(char * str){
    char state = 'a';
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='1') state = 'a';
        else{
            if(state=='b'||state=='c') state = 'c';
            else state = 'b';
        }
        printf("%c ",state);
    }
    if(state=='c') return 1;
    else return 0;
}
int DFA02(char *str){
    char state = 'a';
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='0') state = 'b';
        else{
            if(state=='b') state = 'c';
            else state = 'a';
        }
        printf("%c ",state);
    }
    if(state=='c') return 1;
    else return 0;
}

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

int main(){
    srand(time(0));
    char *str = generator();
    printf("%s\n",str);
    if(DFA02(str)) printf("\nThe string is accepted\n");
    else printf("\nThe string is rejected\n");

    return 0;
}