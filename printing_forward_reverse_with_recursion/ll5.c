//C program to print a list in linked list in forward and backward order using recursion
#include<stdio.h>
#include<stdlib.h>


struct node_t{      // declaring node of the linked list as a structure

  int data;
  struct node_t * next;
};
typedef struct node_t node;

node * head;      //pointer to the head node declared as a global variable

//this function makes a new node with the passed data(d) and inserts it at the beginning of the linked list
void insert(int d){

  if(head == NULL){
    node * temp = malloc(sizeof(*temp));
    temp -> data = d;
    temp -> next = head;
    head = temp;
  }
  else{
    node * temp = malloc(sizeof(*temp));
    temp -> data = d;
    temp -> next = head;
    head = temp;
  }
}
//this function prints the linked list in forward direction using recursion
void forwardPrint(node * p){
  if(p == NULL){        //exit condition for the recursion
    printf("\n");
    return;
  }
  printf("%d ",p -> data);
  forwardPrint(p -> next);
}
//this function prints the linked list in the backward direction using recursion
void backwardPrint(node * q){
  if(q == NULL){    //exit condition for the recursion
    return;
  }  
  backwardPrint(q -> next);
  printf("%d ",q -> data);
  if(q==head){     //if statement to print new line after the last number
    printf("\n");
  }
}
//function to free the allocated memory
void freeMem(){
  while(head!=NULL){
    node*temp = head;
    head = head ->next;
    free(temp);
  }
}
int main(){
  head = NULL;
  insert(34); //list:34
  insert(67); //list:67 34
  insert(22); //list:22 67 34
  insert(90); //list:90 22 67 34
  forwardPrint(head);
  backwardPrint(head);
  freeMem();
  return 0;
}
  
