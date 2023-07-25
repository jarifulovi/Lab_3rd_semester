#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 4
struct node* createNode(int fre,char character);
struct node{
    int frequency;
    char ch;
    struct  node* left;
    struct node* right;

};
void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
struct node* createNode(int fre,char character){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode-> frequency = fre;
    newnode->ch = character;
    newnode-> right = NULL;
    newnode->left = NULL;
    return newnode;
}

struct node* huffman_tree(struct node* arr[],int n){
    while(n>1){
        int min1 = 0;
        int min2 = 1;
        if(arr[min1]->frequency > arr[min2]->frequency){
            min1 = 1; min2 = 0;
        }
        for(int i=2;i<n;i++){
            if(arr[i]->frequency<arr[min1]->frequency){
                min2 = min1;
                min1 = i;
            }
            else if(arr[i]->frequency<arr[min2]->frequency){
                min2 = i;
            }
        }
        struct node* newnode = createNode(arr[min1]->frequency+arr[min2]->frequency,'\0');
        newnode->left = arr[min1];
        newnode->right = arr[min2];

        arr[min1] = newnode;
        arr[min2] = arr[n-1];

        n--;
    }
    return arr[0];
}

void printCode(struct node* root, int codes[], int index) {
    if (root->left) {
        codes[index] = 0;
        printCode(root->left, codes, index + 1);
    }
    if (root->right) {
        codes[index] = 1;
        printCode(root->right, codes, index + 1);
    }
    if (!(root->left || root->right)) {
        printf("The Huffman code for %c is: ", root->ch);
        for (int i = 0; i < index; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}

int main(){
    int frequency[SIZE] = {5,1,6,3};
    char characters[SIZE+1] = "abcd";
    struct node* arr[SIZE];
    // creating array of nodes
    for(int i=0;i<SIZE;i++){
        arr[i] = createNode(frequency[i],characters[i]);
    }
    // printing all the nodes
    for(int i=0;i<SIZE;i++){
        printf("\n%dth node :\n",i);
        printf("Frequency : %d\nCharacter : %c\n",arr[i]->frequency,arr[i]->ch);
    }

    int codes[SIZE]={0};
    // creating Huffman code tree
    struct node* root = huffman_tree(arr,SIZE);
    // printing the codes
    printCode(root,codes,0);
    free(root);
    return 0;
}
