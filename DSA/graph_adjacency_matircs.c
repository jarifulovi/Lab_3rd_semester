#include<stdio.h>
#include<stdlib.h>
struct queue{
    int vertices[6];
    int front;
    int rear;
};
void enqueue(struct queue* q,int vertex){
    if(q->front==-1&&q->rear==-1){
        q->front = q->rear = 0;
        q->vertices[q->rear] = vertex;
    }
    else{
        q->rear++;
        q->vertices[q->rear] = vertex;
    }
}
void dequeue(struct queue* q){
        q->front++;
}
void bfs(int g[6][6],int start){
    int visited[6] ={0};
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->front= -1;
    q->rear = -1;
    visited[start] = 1;
    enqueue(q,start);

    while(q->front<=q->rear){
        int current = q->vertices[q->front];
        int j;
        for(j=0;j<6;j++){
            if(visited[j]==0 && g[current][j]>0){
                visited[j] = 1;
                enqueue(q,j);
            }
        }

        printf("%d ",q->vertices[q->front]);
        dequeue(q);
    }
}
    int main(){
    int graph[6][6] ={
        {0,1,1,0,0,0},
        {1,0,1,1,0,1},
        {1,1,0,0,0,0},
        {0,1,0,0,1,0},
        {0,0,0,1,0,0},
        {0,1,0,0,0,0}
    };
    bfs(graph,0);
    return 0;
}
