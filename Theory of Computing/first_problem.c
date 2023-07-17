#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char* generator(){
    
    int i,length = rand()%10+1;
    char *str = (char*) malloc((length+1)*sizeof(char));
    for(i=0;i<length;i++){
        if(rand()%2==0) str[i] = '0';
        else str[i] = '1';
    }
    str[i] = '\0';
    return str;
}
int* str_length(char** str){
    int *length = (int*)malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        length[i] = 0;
        for(int j=0;j<str[i][j]!='\0';j++) length[i]++;
    }
    return length;

}
int check(char* str){
    int flag = 1;
    for(int i=0;i<str[i]!='\0';i++){
        if(!(str[i]=='1'||str[i]=='0')) flag = 0;
    }
    return flag;
}
char* concate(char* str1,int l1,char* str2,int l2){
    char *con_str = (char*)malloc((l1+l2+1)*sizeof(char));
    int k=0;
    for(int i=0;i<l1;i++) con_str[k++] = str1[i];
    for(int i=0;i<l2;i++) con_str[k++] = str2[i];
    con_str[k] = '\0';
    return con_str;
}
int main(){
    char *str[5];
    srand(time(0));
    for(int i=0;i<5;i++) str[i] = generator();
    for(int i=0;i<5;i++) printf("%s\n",str[i]);
    int *length = str_length(str);
    printf("The length of all strings\n");
    for(int i=0;i<5;i++) printf("%d\n",length[i]);
  //  char* new_str = generator();
    char new_str[] = "10101ui";
    if(check(new_str)) printf("%s is alphabet\n",new_str);
    else printf("%s is not alphabet\n",new_str);
    
    char *concated_str = concate(str[0],length[0],str[2],length[2]);
    printf("The concated string is %s\n",concated_str);

}