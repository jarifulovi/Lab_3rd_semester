#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void print_list(struct node* ptr){
    printf("Linked list :\n");
    while(ptr!=NULL){
        printf("%d ",ptr-> data);
        ptr = ptr -> next;
    }
    printf("\n");
}
void insert_list(struct node** head,struct node* insert,struct node* first){
    insert-> next = first;
     (*head) = insert;
}
void delete_list(struct node** head){
    *head = (*head )-> next;
}
int main(){
    struct node* head;
    struct node* first=NULL;
    struct node* second=NULL;
    struct node* third=NULL;
    struct node* fourth=NULL;
    struct node* insert=NULL;
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));
    insert = (struct node*)malloc(sizeof(struct node));
    first -> data = 1;
    second -> data= 2;
    third -> data = 3;
    fourth -> data = 4;
    insert -> data = 0;
    first->next= second;
    second->next = third;
    third->next= fourth;
    fourth->next = NULL;
    head = first;
    print_list(head);
    insert_list(&head,insert,first);
    printf("After inserting in the first\n");
    print_list(head);
    delete_list(&head);
    printf("After deleting the first\n");
    print_list(head);
}
