#include<stdio.h>
#include<stdlib.h>
int Max(int* array,int length){
    int maximum;
    maximum = array[0];
    for(int i=0;i<length;i++){
        if(array[i]>maximum) maximum = array[i];
    }
    return maximum;
}
int Min(int* array,int length){
    int minimun;
    minimun = array[0];
    for(int i=0;i<length;i++){
        if(array[i]<minimun) minimun = array[i];
    }
    return minimun;
}

int main(){
    int i,j,array[]={-7,1,4,3,6,7,3,6};
    int max,min,shift,length=sizeof(array)/sizeof(int);
    max = Max(array,length);
    min = Min(array,length);
    if(min<0){   // see if there are negative values or not
        shift = abs(min);
        for(i=0;i<length;i++) array[i]+=shift;  // shift the values if min is negative value
    }
    int count[max+1];
    for(i=0;i<max+1;i++) count[i]=0;  // initialize all the count values to zero

    for(i=0;i<length;i++){
        count[array[i]]++;
    }
    printf("The counted array: ");
    for(i=0;i<max+1;i++)  printf(" %d ",count[i]);

    for(i=0,j=0;i<max+1;i++){
        if(count[i]){
            array[j]=i;
            count[i]--;
            j++;
        }
        if(count[i]) i--;
    }
    if(min<0){
        for(i=0;i<length;i++) array[i]-=shift; // undo the shift if the min was negative
    }
    printf("\nThe sorted array:");
    for(i=0;i<length;i++)  printf(" %d ",array[i]);
    return 0;
}
