#include<stdio.h>
struct node{
    char exp;
    struct node* next;
}*head;



void pop(char ch){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->exp = ch;
    newnode->next = head;
    head = newnode;
}
void push(){
    struct node* temp = head->next;
    free(head);
    head = temp;
}
int Stack_operation(char expression){



}
int main(){
    struct node* head = NULL;
    char expression[100];
    scanf("%s",expression);
    Stack_operation(expression);




}
