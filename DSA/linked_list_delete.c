#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void print_list(struct node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}
void delete_first(struct node** head){
    struct node* delete = *head;
    *head = (*head) -> next;
    free(delete);
}
void delete_last(struct node** head){
    struct node* current = *head;
    if((current)->next == NULL){
        free(current);
        current = NULL;
        return;
    }
    while(current->next->next!=NULL) current = current -> next;
    free(current -> next);
    current -> next = NULL;

}
void delete_between(struct node* head,int value){
    struct node* previous = head;
    struct node* current = head -> next;
    if(previous->data==value){
        delete_first(&head);
        return;
    }
    while((current->data!=value)&&(current!=NULL)){
        previous = current;
        current =  current -> next;
    }
    if(current!= NULL){
        previous -> next = current -> next;
        free(current);
    }
}
int main(){
    struct node* head = NULL;
    struct node* one = NULL;
    struct node* two = NULL;
    struct node* three = NULL;
    struct node* four = NULL;
    struct node* first = NULL;
    struct node* last = NULL;
    struct node* between = NULL;
    one = (struct node*) malloc(sizeof(struct node));
    two = (struct node*) malloc(sizeof(struct node));
    three = (struct node*) malloc(sizeof(struct node));
    four = (struct node*) malloc(sizeof(struct node));
    first = (struct node*) malloc(sizeof(struct node));
    last = (struct node*) malloc(sizeof(struct node));
    between = (struct node*) malloc(sizeof(struct node));

    first -> data = 0;
    one -> data = 1;
    two -> data = 2;
    three -> data = 3;
    between -> data = 4;
    four -> data = 5;
    last -> data = 100;

    first -> next = one;
    one -> next = two;
    two -> next = three;
    three -> next = between;
    between -> next = four;
    four -> next = last;
    last -> next = NULL;

    head = first;

    printf("Main node values\n");
    print_list(head);
    printf("Deleting the first node\n");
    delete_first(&head);
    print_list(head);
    printf("Deleting the last node\n");
    delete_last(&head);
    print_list(head);
    printf("Deleting any node through value\n");
    delete_between(head,2);
    print_list(head);
return 0;
}
