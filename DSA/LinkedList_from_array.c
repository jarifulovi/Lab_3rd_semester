#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createNode(int val){
    struct node* temp;
    temp =  (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}
void createLinkedList(struct node** head,int* arr,int size){  // stack like list
    if(size<1) return;
    *head = createNode(arr[0]);
    struct node* curr;
    curr = *head;
    for(int i=1;i<size;i++){
        curr->next = createNode(arr[i]);
        curr = curr->next;
    }
}
void reverseAddingLinkedList(struct node** head,int* arr,int size){  // queue like list
    if(size<1) return;
   
    *head = createNode(arr[0]);
    struct node* curr;
    for(int i=1;i<size;i++){
        curr = createNode(arr[i]);
        curr->next = *head;
        *head = curr;
    }

}
void reverseLinkedList(struct node** head){
    if((*head)==NULL||(*head)->next==NULL) return;
 
    struct node* curr = *head;
    struct node* pre = NULL;
    struct node* next = NULL;
    while(curr!=NULL){        // reverse the curr and store the next for further iteration
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    *head = pre;  // curr will end up in null so pre should be the starting point
}

void eraseLinkedList(struct node** head){
    struct node* curr = *head;
    while (curr!=NULL)
    {
        struct node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    
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
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Linked List : ");
    createLinkedList(&head,arr,size);
    printLinkedList(head);

    printf("\nReverse order Linked List : ");
    reverseLinkedList(&head);
    printLinkedList(head);
    eraseLinkedList(&head);

    printf("\nReverse adding Linked List : ");
    reverseAddingLinkedList(&head,arr,size);
    printLinkedList(head);
}