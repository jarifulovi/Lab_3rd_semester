#include<stdio.h>
#include<limits.h>
#define MAX_SIZE 10

int m[MAX_SIZE][MAX_SIZE] = {0};
int s[MAX_SIZE][MAX_SIZE] = {0};
void print_optimal_parens(int s[MAX_SIZE][MAX_SIZE],int i,int j){
    if(i==j) printf("%c",i+'A'-1);
    else{
        printf("(");
        print_optimal_parens(s,i,s[i][j]);
        print_optimal_parens(s,s[i][j]+1,j);
        printf(")");
    }
}
void matrixChainOrder(int p[],int n){
    for(int i=1;i<=n;i++){
        m[i][i] = 0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i;k<=j-1;k++){
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
int main(){
    int p[] = {1,2,3,4,3};
    int n = sizeof(p)/sizeof(int) - 1;
    matrixChainOrder(p,n);
    printf("Matrix m :\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) printf("%d ",m[i][j]);
        printf("\n");
    }
    printf("Matrix s :\n");
    for(int i=1;i<=n-1;i++){
        for(int j=2;j<=n;j++) printf("%d ",s[i][j]);
        printf("\n");
    }
    printf("The minimum multiplication : %d\n",m[1][n]);
    printf("The optimal parenthesis : ");
    print_optimal_parens(s,1,n);
    return 0;
}