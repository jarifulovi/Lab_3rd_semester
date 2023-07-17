#include<stdio.h>
long f[100];
long int fib(int num){
    if(num==0 ||num==1) return num;
    if(f[num]==-1){
        long ans = fib(num-1)+fib(num-2);
        f[num] = ans;
        return ans;
    }
    else return f[num];
}
int main(){
    int num = 45;
    for(int i=0;i<100;i++) f[i] = -1;
    fib(45);
    long ans = f[num];
    printf("%ld\n",ans);
    return 0;
}