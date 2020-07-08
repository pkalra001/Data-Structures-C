//C program to reverse a linked list
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
//this function reverses the linked list
void reverse(){

  node * prev;  //this pointer will point at the node previous to the one who's link is to be reversed
  node * after; //this pointer will point at the next to the one who's link is to be reversed
  prev = head;  //the next five lines are for reversing the first node and point it to NULL
  head = head -> next;
  after = head -> next;
  prev -> next = NULL;
  head -> next = prev;
  while(after!= NULL){  //this loop reverses the other nodes
    prev = head;
    head = after;
    after = after -> next;
    head -> next = prev;
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
  insert(23);  //list:23
  insert(6);   //list:6 23
  insert(78);  //list:78 6 23
  insert(87);  //list:87 78 6 23
  insert(66);  //list:66 87 78 6 23
  printf("The list looks like this originally:\n");
  print();
  reverse();
  printf("After reversing the list looks like:\n");
  print();
  freeMem();
  return 0;
}
  
    
  
  
    
