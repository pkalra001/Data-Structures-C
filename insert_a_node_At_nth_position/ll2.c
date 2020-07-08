//CProgram to insert a node at nth position in a linked list

#include<stdio.h>
#include<stdlib.h>

struct node_t{
  int data;                   //to store data
  struct node_t * next;       //pointer to the next node
};
typedef struct node_t node;

node * head;                 //pointer to the head node declared as a "global variable"

//this function allocates memory for a new node and returns a pointer to it
node * createNewNode(){       
  node * newNode = malloc(sizeof(*newNode));
  return newNode;
}
//this function inserts the data(d) at the position n
void insert(int d,int n){
  
  if(n==1){                                   
    node * newNode = createNewNode();
    newNode -> data = d;
    newNode -> next = head;
    head = newNode;    
  }
  else{
    node * newNode = createNewNode();    
    newNode -> data = d;    
    node * prev = head;    
    for(int i=0;i<(n-2);i++){
      prev = prev -> next;
    }
    node * toShift = prev -> next;    
    prev -> next = newNode;
    newNode -> next = toShift;        
  }
}
//this function prints all the elements in the linked list
void print(){

  node * print = head;
  while(print!= NULL){
    printf("%d",print -> data);
    print = print -> next;
  }
  printf("\n");
}
//function to free the allocated memory
void freeMem(){
  while(head!=NULL){
    node * temp = head;
    head = head ->next;
    free(temp);
  }
}
int main(){

  head = NULL;
  //There can be non permissible cases for insertion where the user tries to insert at an invalid position and an error needs to be printed in that case but we are not considering those cases here
  insert(2,1); //list:2
  print();
  insert(8,2); //list:28
  print();
  insert(4,1); //list:428
  print();
  insert(6,2); //list:4628
  print();
  freeMem(); 
  return 0;
}
