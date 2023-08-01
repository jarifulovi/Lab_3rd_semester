#include<stdio.h>
#include<stdlib.h>
int compareFinishingTime(const void* a, const void* b);
int numOfJobs;
struct job{
    char jobName[20];
    int start_time,finishing_time;
    int compatability;
};
int compareFinishingTime(const void* a, const void* b) {
    const struct job* jobA = (const struct job*)a;
    const struct job* jobB = (const struct job*)b;
    return jobA->finishing_time - jobB->finishing_time;
}
void readInput(struct job* jobs[]){
    scanf(" %d",&numOfJobs);
    for(int i=0;i<numOfJobs;i++){
        scanf("%s %d %d",jobs[i]->jobName,&jobs[i]->start_time,&jobs[i]->finishing_time);
        jobs[i]->compatability = 1;
    }
    for(int i=0;i<numOfJobs;i++){
        printf("%s %d %d %d\n",jobs[i]->jobName,jobs[i]->start_time,jobs[i]->finishing_time,jobs[i]->compatability);
    }
}
int recursion(struct job* jobs[],int length,int i){
    int m = i+1;
    while(m<length&&(jobs[m]->start_time<jobs[i]->finishing_time)){
        jobs[m]->compatability = 0;
        m++;
    }
    if(m<length){
        return recursion(jobs,numOfJobs,m);
    }
    return 0;
}
int main(){
    struct job* jobs[10];
    for (int i = 0; i < 10; i++) {
        jobs[i] = (struct job*)malloc(sizeof(struct job));
    }
    qsort(jobs, numOfJobs, sizeof(struct job), compareFinishingTime);
    freopen("input.text","r",stdin);
    readInput(jobs);
    recursion(jobs,numOfJobs,0);
    printf("The greedy solution :\n");
    for (int i = 0; i < numOfJobs; i++) {
        if(jobs[i]->compatability==1)
        printf("%s %d %d %d\n", jobs[i]->jobName, jobs[i]->start_time, jobs[i]->finishing_time, jobs[i]->compatability);
    }
    return 0;
}