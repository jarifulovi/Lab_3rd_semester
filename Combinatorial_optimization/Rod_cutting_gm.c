#include<stdio.h>
int max(int a,int b){
    if(a>b) return a;
    return b;
}
int rod_cutting(int price[],int n){
    int dp[n+1];
    int cuts[n+1];
    dp[0] = 0;
    cuts[0] = 0;
    int max_profit = 0;
    for(int i=1;i<n+1;i++){
        max_profit = 0;
        for(int j=0;j<i;j++){
            if(max_profit<price[j]+dp[i-j-1]){
                max_profit = price[j]+dp[i-j-1];
                cuts[i] = j+1;
            }
        }
        dp[i] = max_profit;
    }
    int remainingLength = n;
    while (remainingLength > 0) {
            printf("Cut at position %d\n", cuts[remainingLength]);
            remainingLength -= cuts[remainingLength];
    }
    

    return max_profit;
}
int main(){
    int price[] = {1, 3, 4, 5, 7, 9, 10, 11};
    int n = sizeof(price)/sizeof(int);
    int max_profit = rod_cutting(price,n);
    printf("\nThe maximum profit is %d\n",max_profit);
   
    // Print or process the cuts array to display the optimal way to cut the rod
    return 0;
}