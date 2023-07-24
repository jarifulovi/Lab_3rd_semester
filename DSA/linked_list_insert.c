#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void insert_first(struct node** head,struct node* first,struct node* one){
    *head = first;
    first -> next = one;
}
void insert_last(struct node* last,struct node* three){
    three -> next = last;
    last -> next = NULL;
}



void print_linked_list(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p -> next;
    }
    printf("\n");
}
int main(){
    struct node* head;
    struct node* one=NULL;
    struct node* two=NULL;
    struct node* three=NULL;
    struct node* first = NULL;
    struct node* last = NULL;

    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three = (struct node*)malloc(sizeof(struct node));
    first = (struct node*)malloc(sizeof(struct node));
    last = (struct node*)malloc(sizeof(struct node));

    one -> data= 1;
    two -> data = 2;
    three -> data = 3;
    first -> data = 0;
    last -> data = 4;

    one -> next = two;
    two -> next = three;
    three -> next= NULL;
    head = one;

    printf("After the start insertion\n");
    insert_first(&head,first,one);
    print_linked_list(first);
    printf("After the last insertion\n");
    insert_last(last,three);
    print_linked_list(head);
}

