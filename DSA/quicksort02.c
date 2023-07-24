#include<stdio.h>
void swap(int* arr1,int* arr2){
    int temp;
    temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;

}

int partition(int* arr,int f,int l){
    int i,j,p;
    p = arr[l];
    i = f-1;
    for(j=f;j<l;j++){
        if(arr[j]<=p){
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[l]);
    return (i+1);

}
int quicksort(int* arr,int f,int l){
    /*printf("The array iteration : ");
    for(int j=0;j<5;j++) printf("%d ",arr[j]);
    printf("\n");*/

    int p;
    if(f<l){
        p = partition(arr,f,l);
       // printf("The pivot value is : %d\n",p);
        quicksort(arr,f,p-1);
        quicksort(arr,p+1,l);
    }
    return 0;

}



int main(){
    int i;
    int arr[10]={4,2,5,1,3,4,8,7,1,2};

    quicksort(arr,0,9);
    printf("Sorted numbers are : \n");
    for(i=0;i<10;i++)
    printf("%d ",arr[i]);

    return 0;
}
