#include<stdio.h>
int max(int* array,int length){
    int i,j,maximum=array[0];
    for(i=0;i<length;i++){
        if(maximum<array[i]) maximum=array[i];
    }
    return maximum;

}
int main(){
    int i,j,k=0,array[] = {2,2,6,5,3,6,6,8,10};
    int high,length=9;
    high = max(array,length);
    int count[high+1];
    for(i=0;i<=high;i++) count[i]=0;
    for(i=0;i<=high;i++){
        for(j=0;j<length;j++){
            if(array[j]==(i)) count[i]=++k;
        }
        k=0;
    }
    printf("The counted array : \n");
    for(i=0;i<=high;i++) printf("%d ",count[i]);
    for(i=0;i<=high;i++){
        for(j=0;j<count[i];j++){
            array[k]=i; k++;
        }
    }
    printf("\nThe sorted array :\n");
    for(i=0;i<length;i++) printf("%d ",array[i]);

return 0;
}
