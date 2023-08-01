#include<stdio.h>
#include<stdlib.h>
int compareFinishingTime(const void* a, const void* b);
int numOfJobs;
struct job{
    char jobName[20];
    int start_time,finishing_time;
    int compatability;
}jobs[100];

int compareFinishingTime(const void* a, const void* b) {
    const struct job* jobA = (const struct job*)a;
    const struct job* jobB = (const struct job*)b;
    return jobA->finishing_time - jobB->finishing_time;
}
void readInput(){
    scanf(" %d",&numOfJobs);
    for(int i=0;i<numOfJobs;i++){
        scanf("%s %d %d",jobs[i].jobName,&jobs[i].start_time,&jobs[i].finishing_time);
        jobs[i].compatability = 1;
    }
    for(int i=0;i<numOfJobs;i++){
        printf("%s %d %d %d\n",jobs[i].jobName,jobs[i].start_time,jobs[i].finishing_time,jobs[i].compatability);
    }
}
int main(){
    freopen("input.text","r",stdin);
    readInput();
    qsort(jobs, numOfJobs, sizeof(struct job), compareFinishingTime);
    printf("After sort \n");
    int curr = 0;
    for(int i=1;i<numOfJobs;i++){
        if(jobs[i].start_time<=jobs[curr].finishing_time) jobs[i].compatability = 0;
        else{
            curr = i;
        }
    }
    for (int i = 0; i < numOfJobs; i++) {
        if(jobs[i].compatability==1)
        printf("%s %d %d %d\n", jobs[i].jobName, jobs[i].start_time, jobs[i].finishing_time, jobs[i].compatability);
    }
    return 0;
}