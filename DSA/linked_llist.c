#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[20];
    int roll;
    struct node *next;
};
void linked_list(struct node *p){
    while(p!=NULL){
        printf("Name : %s | roll : %d\n",p -> name,p -> roll);
        p = p -> next;
    }
}

int main(){
    struct node *head;
    struct node *one=NULL;
    struct node *two=NULL;
    struct node *three=NULL;
    struct node *four=NULL;
    struct node *five=NULL;

    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three =(struct node*)malloc(sizeof(struct node));
    four =(struct node*)malloc(sizeof(struct node));
    five =(struct node*)malloc(sizeof(struct node));

    one -> roll = 1;
    two -> roll = 2;
    three -> roll = 3;
    four -> roll = 4;
    five -> roll = 5;

    strcpy(one->name,"ovi");
    strcpy(two->name,"nahid");
    strcpy(three->name,"munna");
    strcpy(four->name,"kazi");
    strcpy(five->name,"badhon");

    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = NULL;
    head = one;

    linked_list(head);
return 0;
}

