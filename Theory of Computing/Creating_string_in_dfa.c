#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char* generator(char *alphabets){
    int i,length = rand()%10+1;
    int length_alp = strlen(alphabets);
    char *str = (char*) malloc((length+1)*sizeof(char));
    for(i=0;i<length;i++){
        str[i] = alphabets[rand()%length_alp];
    }
    str[i] = '\0';
    return str;
}
int main(){
    srand(time(0));
    char alphabets[]="abc";
    char *str = generator(alphabets);
    printf("%s\n",str);
    free(str);
    return 0;
}