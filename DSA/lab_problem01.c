#include<stdio.h>
int max(int *array,int l){
    int m = array[l/2];
    for(int i=l/2;i<l;i++){
        if(m<array[i]) m = array[i];
    }
    return m;
}
int find_value(int *array,int x){
    int l = sizeof(array)/sizeof(int);
    for(int i=0;i<l;i++){
        if(array[i]==x){
                printf("The value has been found\n");
                return 0;
        }
    }
    printf("The value is not found in the array\n");
    return 0;
}
int main(){
int array[10];
printf("Enter values : \n");
for(int i=0;i<10;i++) scanf("%d",&array[i]);

int length = sizeof(array)/sizeof(int);
if(length%2==1) length++;
int maximum = max(array,length);
int count[maximum];
for(int i=0;i<maximum;i++) count [i] = 0;
for(int i=length/2;i<length;i++){
    count[array[i]]++;
}
for(int i=0;i<maximum;i++){
    if(count[i]){
        array[i+length/2] = i;
        count[i]--;
        i--;
    }
}
//printf("\n%d\n",maximum);
printf("The sorted array : \n");
for(int i=0;i<length;i++) printf("%d ",array[i]);
int x;
printf("\nEnter the value to search\n");
scanf("%d",&x);
find_value(array,x);
}


