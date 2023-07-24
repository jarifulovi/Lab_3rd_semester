#include<stdio.h>
#include<stdlib.h>
struct node{
    char name[20];
    int roll;
    struct node *next;
    struct node *previous;
};
void print_linked_list(struct node *p){
    while(p!=NULL){
        printf("Name : %s | roll : %d\n",p -> name,p -> roll);
        p = p -> next;
    }
}
void print_reverse_list(struct node* p){
    printf("\nLinked list in reverse order :\n\n");
    while(p->next!=NULL) p = p->next;
    while(p-> previous!=NULL){
        printf("Name : %s | roll : %d\n",p->name,p->roll);
        p = p -> previous;
    }
    printf("Name : %s | roll : %d\n",p->name,p->roll);

}
void delete(struct node* ptr,struct node** head){
    printf("\nAfter deleting the node :\n\n");
    if(ptr->previous == NULL){
    ptr -> next -> previous = NULL;
    *head = ptr->next;
    free(ptr);
    }
    else if(ptr->next==NULL){
        ptr -> previous -> next = NULL;
        free(ptr);
    }
    else{
        ptr -> next -> previous = ptr -> previous;
        ptr -> previous -> next = ptr -> next;
        free(ptr);
    }

}
void insert(struct node* ptr,struct node* pre,struct node** head){
    if(pre==NULL){
       while((*head)->next!=NULL) (*head) = (*head)-> next;
       (*head) -> next = ptr -> previous;
       ptr -> next = NULL;
    }
    else if(pre->previous==NULL){
        ptr -> previous = NULL;
        ptr -> next = (*head);
    }
    else{
        ptr -> previous = pre -> previous;
        pre -> previous = ptr;
        ptr -> next = pre;
        pre -> previous -> next = ptr;
    }

}
int main(){
    struct node *head;
    struct node *one=NULL;
    struct node *two=NULL;
    struct node *three=NULL;
    struct node *four=NULL;
    struct node *five=NULL;
    struct node* n = NULL;

    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three =(struct node*)malloc(sizeof(struct node));
    four =(struct node*)malloc(sizeof(struct node));
    five =(struct node*)malloc(sizeof(struct node));
    n =(struct node*)malloc(sizeof(struct node));

    one -> roll = 1;
    two -> roll = 2;
    three -> roll = 3;
    four -> roll = 4;
    five -> roll = 5;
    n -> roll = 100;

    strcpy(one->name,"ovi");
    strcpy(two->name,"nahid");
    strcpy(three->name,"munna");
    strcpy(four->name,"kazi");
    strcpy(five->name,"badhon");
    strcpy(n-> name,"new");

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = NULL;

    five -> previous = four;
    four -> previous = three;
    three ->  previous = two;
    two -> previous = one;
    one -> previous = NULL;
    head = one;

    print_linked_list(head);
    print_reverse_list(head);
    delete(one,&head);
    print_linked_list(head);
    insert(n,one,&head);
    print_linked_list(head);

return 0;
}
