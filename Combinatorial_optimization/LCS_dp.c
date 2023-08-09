#include<stdio.h>
#include<string.h>
#define Diag 1
#define UP 3
#define Left 2

void print_lcs(char str[],int table[7][8],int flag[7][8],int i,int j){
    if(i==0||j==0)  return;
    if(flag[i][j]==Diag){
        print_lcs(str,table,flag,i-1,j-1);
        printf("%c ",str[i-1]);
    }
    else if(flag[i][j]==UP){
        print_lcs(str,table,flag,i-1,j);
    }
    else if(flag[i][j]==Left) print_lcs(str,table,flag,i,j-1);

}
int lcs(char str[],char str2[],int m,int n){
    int table[m][n],flag[m][n];
    for(int i=0;i<m;i++){
        table[i][0] = 0;
        flag[i][0] = 0;
    }
    for(int j=0;j<n;j++){
        table[0][j] = 0;
        flag[0][j] = 0;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(str[i-1]==str2[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
                flag[i][j] = Diag;
            }
            else if(table[i-1][j]>table[i][j-1]){
                table[i][j] = table[i-1][j];
                flag[i][j] = UP;
            }
            else{
                table[i][j] = table[i][j-1];
                flag[i][j] = Left;
            }
        }
    }
    print_lcs(str,table,flag,m-1,n-1);
    return table[m-1][n-1];
}
int main(){
    char str[] = "aggtab";
    char str2[] = "gxtxayb";
    int m = sizeof(str)/sizeof(char);
    int n = sizeof(str2)/sizeof(char);
    int length = lcs(str,str2,m,n);
    printf("\nThe lcs length is %d\n",length);
    return 0;
}