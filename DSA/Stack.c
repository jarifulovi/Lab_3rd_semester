#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*top;



void push(int num) {
    struct node *temp;
    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->data = num;
    temp->next = top;
    top = temp;
}

void pop() {

    struct node *temp;
        temp = top;
        top = top->next;
        printf("Popped out : %d\n", temp->data);
        free(temp);
}


void printStack(struct node *nodePtr) {
    printf("Stack : ");
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf(" ");
  }
  printf("\n");
}

void main() {

   top=NULL;
   push(1);
   push(2);
   push(3);
   push(4);

   printf("Linked List:\n");
   printStack(top);

   pop();
   pop();
   printStack(top);

   return;
}
