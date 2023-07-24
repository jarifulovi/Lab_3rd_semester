#include<stdio.h>
#include<string.h>

#define S 11
#define N 20
int places[S][N];
int ret = 0;

int getIndex(char place[N]){
    int i;
    for(i=0;i<S;i++){
        if(!strcmp(place,places[i])) return i;
    }
    return -1;
}
int checkCafe(char place[N],char cafe[N]){
    if(!strcmp(place,cafe)){
        return 1;
    }
    return 0;

}
void dfs_visited(int graph[S][S],int visited[S],int start,char cafe){
    visited[start] = 1;
    printf("%s,",places[start]);
    if(checkCafe(places[start],cafe)) ret = 1;
    if(ret==1) return;
    for(int i=0;i<S;i++){
        if(visited[i]==0&&graph[start][i]>0) dfs_visited(graph,visited,i,cafe);
    }
}

void dfs(int graph[S][S],char start_place){
    int start = getIndex(start_place);
    int visited[S]={0};
    printf("All the paths :\n");
    dfs_visited(graph,visited,start,"Social Science Building");
    printf("\n");
    dfs_visited(graph,visited,start,"Curzon Hall");
     printf("\n");
    dfs_visited(graph,visited,start,"FBS");
     printf("\n");
    dfs_visited(graph,visited,start,"TSC");


}
int main(){
    int graph[S][S];
    printf("Add all the places :\n");
    for(int i=0;i<S;i++) scanf("%s",places[i]);
    int routes;
    printf("Enter the number of routes :\n");
    scanf("%d",&routes);
    for(int i=0;i<routes;i++){
        char from[N],to[N];
        printf("From :\n");
        scanf("%s",from);
        printf("To :\n");
        scanf("%s",to);
        int in,out;
        in = getIndex(from);
        out = getIndex(to);
        if(in==-1 || out==-1){
            printf("Invalid country name\n");
            i--;continue;
        }
        graph[in][out] = 1;
    }
    dfs(graph,"iit");
return 0;
}
