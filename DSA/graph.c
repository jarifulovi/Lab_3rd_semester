#include<stdio.h>
void in_zero(int array[][8]){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++) array[i][j]=0;
    }
}
void addEdge(int array[][8],char A,char B,int weight){
    int i,j;
    i = A-65;
    j = B-65;
    array[i][j] = weight;
}
void print_graph(int array[][8]){
    int i,j;
     for(i=0;i<8;i++){
        for(j=0;j<8;j++) printf("%d ",array[i][j]);
        printf("\n");
     }
}
int main(){
    int matrics[8][8];
    in_zero(matrics);

    addEdge(matrics,'A','B',4);
    addEdge(matrics,'C','B',8);
    addEdge(matrics,'C','B',5);
    addEdge(matrics,'B','D',3);
    addEdge(matrics,'E','B',1);
    addEdge(matrics,'C','E',9);
    addEdge(matrics,'D','E',4);
    addEdge(matrics,'F','D',2);
    addEdge(matrics,'F','E',6);
    print_graph(matrics);

    bfs();


}
