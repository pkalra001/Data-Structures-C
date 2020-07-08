//C program to reverse a linked list using recursion
#include<stdio.h>
#include<stdlib.h>

struct node_t{      // declaring node as a structure

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
//this function prints the linked list
void print(){
  node * print = head;
  while(print != NULL){
    printf("%d ",print -> data);
    print = print -> next;
  }
  printf("\n");
}
//this function reverses the linked list using recursion
void reverse(node * p){
  if(p -> next == NULL){ //exit condition for the recursion
    head = p;    //setting head equal to the last node of the list
    return;
  }
  reverse(p -> next);
  node * q = p -> next;
  q -> next =p;
  p -> next = NULL;
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
  insert(56);//list:56
  insert(88);//list:88 56
  insert(21);//list:21 88 56
  insert(72);//list:72 21 88 56
  print();
  reverse(head);
  print();
  freeMem();
  return 0;
}
