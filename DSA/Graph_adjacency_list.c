#include<stdio.h>
#include<stdlib.h>
struct node{
    int vertex;
    struct node* next;
};

struct Graph{
    struct  node* adjlist[6];
    int visited[6];
};
struct queue{
    int vertices[6];
    int front;
    int rear;
};
struct node* createNode(int v){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode-> vertex = v;
    newnode-> next = NULL;
    return newnode;
}
void addEdge(struct Graph* g,int out,int in){
    struct node* newnode = createNode(in);
    newnode-> next = g-> adjlist[out];
    g->adjlist[out] = newnode;
    //struct node* newnode2 = createNode(out);
    //newnode2-> next = g-> adjlist[in];
    //g->adjlist[in] = newnode2;
}
void print_graph(struct Graph* g){
    for(int i=0;i<6;i++){
        struct node* temp = g->adjlist[i];  // for traversing the linear adjlist
        printf("Vertex %d : ",i);
        while(temp!=NULL) {
            printf("%d ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");

    }
}
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
int isEmpty(struct queue* q){
    if(q->front>q->rear){
        return 1;
    }
    else return 0;
}
void bfs(struct  Graph* g,int start){
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    int visited[6]={0,0,0,0,0,0};
    visited[start] = 1;
    enqueue(q,start);
    while(!isEmpty(q)){
        int current = q->vertices[q->front];
        struct node* temp =  g->adjlist[current];

        while(temp!=NULL){
            if(visited[temp->vertex]==0){
                visited[temp->vertex] = 1;
                enqueue(q,temp->vertex);
            }
            temp = temp->next;
        }
        printf("%d ",q->vertices[q->front]);
        dequeue(q);

    }

}
void dfs(struct Graph* g,int start,struct node* t){
    struct node* temp =   g->adjlist[start];
    g->visited[start] = 1;
    printf("%d ",start);

    while(temp!=NULL){
        if(g->visited[temp->vertex]==0){

            dfs(g,temp->vertex,t);
        }
        temp = temp->next;
    }
    for(int i=0;i<6;i++){
        if(g->visited[i]==0) dfs(g,i,t);
    }
}

int main(){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    for(int i=0;i<6;i++){
        graph-> adjlist[i] = NULL;
        graph->visited[i] = 0;
    }
    struct node* topology = (struct node*) malloc(sizeof(struct node));
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,1);
    addEdge(graph,3,4);
    addEdge(graph,4,5);
    addEdge(graph,5,3);

    print_graph(graph);
    //bfs(graph,0);
    dfs(graph,0,topology);
    free(graph);
    return 0;
}
