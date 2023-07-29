#include<stdio.h>
void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
void swapc(char* a,char *b){
    char t = *a;
    *a = *b;
    *b = t;
}
void sort(int* deadlines,int* profit,char* jobs,int length){
    int i,j;
    for(int i=0;i<length;i++){
        for(int j=0;j<length-i;j++){
            if(profit[j]<profit[j+1]){
                swap(&profit[j],&profit[j+1]);
                swap(&deadlines[j],&deadlines[j+1]);
                swapc(&jobs[j],&jobs[j+1]);
            }
        }
    }

}
int max(int* deadlines,int length){
    int m = -1;
    for(int i=0;i<length;i++){
        if(deadlines[i]>m) m = deadlines[i];
    }
    return m;
}

int main(){
    int deadlines[] = {2,1,2,1,3},profit[] = {100,19,27,25,15};
    char jobs[] = "abcde";
    int length = sizeof(profit)/sizeof(int);
    sort(deadlines,profit,jobs,length);
    //for(int i=0;i<length;i++)
    //printf("%d %d %c\n",deadlines[i],profit[i],jobs[i]);
    int m = max(deadlines,length);
    char ans[m];
    for(int i=0;i<m;i++) ans[i] = '0';
    int max_profit = profit[0];
    ans[deadlines[0]-1] = jobs[0];
    for(int i=1;i<length;i++){
        int index = deadlines[i]-1;
        for(int j=index;j>=0;j--){
                if(ans[j]=='0'){ 
                    ans[j] = jobs[i];
                    max_profit+=profit[i];break;
                    }
            }
    }
    for(int i=0;i<m;i++) printf("%c ",ans[i]);
    return 0;
}