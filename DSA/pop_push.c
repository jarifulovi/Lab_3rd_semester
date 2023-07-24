#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*top;



void push(int num) {
    struct node *temp;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->data = num;

    if (top == NULL) {
        top = temp;
        top->next = NULL;
    } else {
        temp->next = top;
        top = temp;
    }
}

void pop() {

    struct node *temp;
        temp = top;
        top = top->next;
        printf("Popped out: %d\n", temp->data);
        free(temp);
}


void printStack(struct node *ptr) {
  while (ptr != NULL) {
     printf("%d ", ptr->data);
     ptr = ptr->next;
  }
  printf("\n");
}

void main() {

   top=NULL;
    push(1);
    push(2);
    push(3);
   printf("Linked List:\n");
   printStack(top);

   pop();
   printStack(top);

   return;
}
