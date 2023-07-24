#include<stdio.h>
void swap(int* arr1,int* arr2){
    int temp;
    temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;

}
int partition(int* arr,int f,int l){
    int i=f,j=l;
    while(i<j){
        while(arr[i]<arr[l]&&(i<l)) i++;
        while(arr[j]>arr[l]&&(j>f)) j--;
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[j],&arr[l]);
    return j;
}
int quicksort(int* arr,int f,int l){
    int p;
    if(f<l){
        p = partition(arr,f,l);
        quicksort(arr,f,p-1);
        quicksort(arr,p+1,l);
    }
    return 0;

}



int main(){
    int i;
    int arr[10]={11,9,8,7,16,5,14,32,2,1};

    quicksort(arr,0,9);
    for(i=0;i<10;i++)
    printf("%d ",arr[i]);

    return 0;
}
