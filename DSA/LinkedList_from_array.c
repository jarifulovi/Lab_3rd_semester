#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createNode(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}
void createLinkList(struct node** head,int *arr,int size){
    if(size<1) return;
    struct node* first = NULL;
    first = (struct node*)malloc(sizeof(struct node));
    first = createNode(arr[0]);
    struct node* curr = first;
    for(int i=1;i<size;i++){
        curr->next = createNode(arr[i]);
        curr = curr->next;
    }
    (*head) = first;
}
void reverseLinkedList(struct node** head,int* arr,int size){
    if(size<1) return;
    struct node* first = NULL;
    first = (struct node*)malloc(sizeof(struct node));
    first = createNode(arr[0]);
    struct node* curr;
    for(int i=1;i<size;i++){
    curr = createNode(arr[i]);
    curr->next = first;
    first = curr;
    }
    (*head) = first;
}
void printLinkedList(struct node* head){
    struct node* curr = head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
}
int main(){
    struct node* head;
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Linked List :\n");
    createLinkList(&head,arr,size);
    printLinkedList(head);
    printf("\nLinked List in reverse order :\n");
    reverseLinkedList(&head,arr,size);
    printLinkedList(head);
    printf("\n");
}