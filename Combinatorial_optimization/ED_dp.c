#include<stdio.h>
#include<string.h>
#define Diag 1
#define UP 3
#define Left 2

int min(int a,int b,int c){
    if(c<=a&&c<=b) return c;
    else if(a<=b&&a<=c) return a;
    else if(b<=a&&b<=c) return b;
}
void print_table(int table[7][6],int m,int n){
    printf("m and n is %d %d\n",m,n);
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++) printf("%d ",table[i][j]);
        printf("\n");
    }
}

int ED(char* str1,char* str2,int m,int n){
    int table[m+1][n+1],flag[m+1][n+1];
    for(int i=0;i<=n;i++){
        table[0][i] = i;
        flag[0][i] = Left;
    }
    for(int j=0;j<=m;j++){
        table[j][0] = j;
        flag[j][0] = UP;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1]) table[i][j] = table[i-1][j-1];
            else{
                table[i][j] = min(table[i-1][j-1],table[i-1][j],table[i][j-1])+1;
                if(table[i][j]==table[i-1][j-1]) flag[i][j] = Diag;
                else if(table[i][j]==table[i-1][j]) flag[i][j] = UP;
                else if(table[i][j]==table[i][j-1]) flag[i][j] = Left;
            }
        }
    }
    print_table(table,m,n);
    return table[m][n];
}
int main(){
    char str1[] = "heater";
    char str2[] = "speak";
    int m = sizeof(str1)/sizeof(char);
    int n = sizeof(str2)/sizeof(char);
    int length = ED(str1,str2,m-1,n-1);
    printf("\nThe ed length is %d\n",length);
    return 0;
}
