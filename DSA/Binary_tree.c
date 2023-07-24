#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left_child;
    struct node* right_child;
};
struct node* createNode(int value){
    struct node* temp;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->left_child = NULL;
    temp->right_child = NULL;
    return temp;
}
void insert_right(struct node* root,int x){
    struct node* temp;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->left_child = NULL;
    temp->right_child = NULL;
    root->right_child = temp;
}
void insert_left(struct node* root,int x){
    struct node* temp;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->left_child = NULL;
    temp->right_child = NULL;
    root->left_child = temp;
}

void insert(struct node* root, int x) {
    while(root != NULL) {
        if(x > root->data) {
            if(root->right_child == NULL) {
                insert_right(root, x);
                return;
            }
            root = root->right_child;
        } else {
            if(root->left_child == NULL) {
                insert_left(root, x);
                return;
            }
            root = root->left_child;
        }
    }
}
void insert_recursion(struct node** root,int x){
    if(*root==NULL){
        *root = createNode(x);
    }
    else if(x>=(*root)->data){
           insert_recursion(&(*root)->right_child,x);
    }
    else{
           insert_recursion(&(*root)->left_child,x);
    }

}
void print_tree(struct node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d\n", root->data);
    print_tree(root->left_child);
    print_tree(root->right_child);
}
int search(struct node* root,int x,int* ans){
    if(root==NULL){
        return ans;
    }
    if(root->data!=x){
       (*ans)++;
    }
    search(root->left_child,x,&ans);
    printf("%d\n",root->data);
    search(root->right_child,x,&ans);
    return ans;

}
int main(){
    int array[] = {16,22,37,21,12,6,5,23,27};
    int length = sizeof(array)/sizeof(int);
    struct node* root=NULL;
    for(int i=0;i<length;i++){
        insert_recursion(&root,array[i]);
    }
    int ans=1;
    printf("It will take %d search to find %d\n",search(root,23,&ans),23);

}
