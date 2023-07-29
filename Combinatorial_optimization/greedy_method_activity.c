#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int print_activity(int* start,int *finish,int length){
    int ans = 0;
    printf("%d ",ans);
    for(int i=1;i<length;i++){
        if(start[i]>=finish[ans]){  // like this s1 = 11, f0 = 10, so 1 started after 0 finish
            ans = i;
            printf("%d ",ans);
        }

    }
}

int main(){
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int length = sizeof(start)/sizeof(int);
    //qsort(finish,length,sizeof(int),cmpfunc);
    print_activity(start,finish,length);
    return 0;
}