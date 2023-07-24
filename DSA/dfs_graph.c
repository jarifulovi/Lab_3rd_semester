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
void dfs(struct Graph* g,int start){



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
}
