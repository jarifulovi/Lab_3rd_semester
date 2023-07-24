#include<stdio.h>
int d[6],time;
void dfs_visited(int graph[6][6],int start,int visited[6]){
    visited[start] = 1;
    time++;
    d[start] = time;
    printf("%d ",start);
    for(int i=0;i<6;i++){
        if(visited[i]==0 && graph[start][i]>0) dfs_visited(graph,i,visited);
    }


}
void dfs(int graph[6][6],int start,int arr[6]){
    int visited[6] = {0};
    for(int i=0;i<6;i++){
        if(visited[arr[i]]==0) dfs_visited(graph,arr[i],visited);
    }

}
void swap(int* a,int* b){
    int t;
    t = *a;
    *a = *b;
    *b = t;

}
int main(){
    int graph[6][6]={
        {1,0,1,1,0,0},
        {0,0,1,0,1,1},
        {0,0,1,0,0,1},
        {0,1,1,0,0,0},
        {1,0,0,0,0,0},
        {1,0,0,1,1,0},
    };
    int arr[6],time = 0;
    for(int i=0;i<6;i++){
        d[i] = 0;
        arr[i] = i;
    }
    printf("The first dfs traversal :\n");

    dfs(graph,0,arr);
    time = 0;
    for(int i=0;i<6;i++){
       // printf("\nNode : %d | Discovery time : %d",i,d[i]);
        d[i]--;
    }
    printf("\nThe first discovery time :\n");
    for(int i=0;i<6;i++){
        printf("%d ",d[i]+1);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            if(d[j]<d[j+1]){
                swap(&arr[d[j]],&arr[d[j+1]]);
                swap(&d[j],&d[j+1]);
            }
        }
    }

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(graph[i][j]==1){
                graph[i][j] = 0;
                graph[j][i] = 1;
            }
        }
    }
    printf("\n");
    printf("The second dfs traversal :\n");
    dfs(graph,arr[0],arr);
    printf("\nSecond discovery time :\n");
    for(int i=0;i<6;i++){
        printf("%d ",d[i]);
    }




}
