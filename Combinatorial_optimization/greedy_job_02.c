#include<stdio.h>
struct job{
    char name;
    int deadline;
    int profit;
};
void swap(struct job** a,struct job** b){
    struct job* t = *a;
    *a = *b;
    *b = t;
}
int max(struct job* jobs,int length){
    int m = 0;
    for(int i=0;i<length;i++){
        if(m<jobs[i].deadline) m = jobs[i].deadline;
    }
    return m;
}
void sort(struct job* jobs,int length){
    int i,j;
    for(int i=0;i<length-1;i++){
        for(int j=0;j<length-i-1;j++){
            if(jobs[j].profit<jobs[j+1].profit){
                struct job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}
void jobsequencing(struct job* jobs,int length){
    sort(jobs,length);
    int m = max(jobs,length);
    char ans[m];
    for(int i=0;i<m;i++) ans[i] = '0';
    int max_profit = 0;
    for(int i=0;i<length;i++){
        int index = jobs[i].deadline -1;
        for(int j=index;j>=0;j--){
            if(ans[j]=='0'){ 
                ans[j] = jobs[i].name;
                max_profit+=jobs[i].profit;break;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(ans[i]!='0') printf("%c ",ans[i]);
    }
}

int main(){
    struct job jobs[] ={
        {'a',4,20},
        {'b',1,10},
        {'c',1,40},
        {'d',1,30},
       
    };
    jobsequencing(jobs,4);
    return 0;
}