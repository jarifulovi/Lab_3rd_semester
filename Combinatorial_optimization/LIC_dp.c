#include<stdio.h>
int max(int a,int b){
    if(a>b) return a;
    return b;
}
int max_lic(int arr[],int n){
    int max_index = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[max_index]){
            max_index = i;
        }
    }
    return max_index;
}
void print_lic(int arr[],int arr_lic[],int n){
    int max_index = max_lic(arr_lic,n);
    int ans[arr_lic[max_index]];
    ans[arr_lic[max_index]-1] = arr[max_index];
    for(int i=max_index;i>0;i--){
        if(arr_lic[i]>arr_lic[i-1]) ans[arr_lic[i-1]-1] = arr[i-1];
    }
    for(int i=0;i<arr_lic[max_index];i++) printf("%d ",ans[i]);
}
int lic(int arr[],int n){
    int length = 1;
    int arr_lic[n];
    for(int i=0;i<n;i++) arr_lic[i] = 1;
    for(int i=1;i<n;i++){
        for(int j = 0;j < i;j++){
            if(arr[j]<arr[i]) arr_lic[i] = max(arr_lic[j]+1,arr_lic[i]);
        }
        if(arr_lic[i]>length) length = arr_lic[i];
    }
    printf("The longest increasing subsequence is : ");
    print_lic(arr,arr_lic,n);
    return length;
}
int main(){
    int array[] = {9,2,5,3,7,11,8,10,13,6};
    int n = sizeof(array)/sizeof(int);
    int length  =  lic(array,n);
    printf("\nThe longest increasing subsequence length is : %d\n",length);
    return 0;
}