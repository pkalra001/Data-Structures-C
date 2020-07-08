//linked list implementation of queue
#include<stdio.h>
#include<stdlib.h>

struct node_t{  //node of the linked list declared as a global variable
  int value;
  struct node_t * next;
};
typedef struct node_t node;
node * front; //pointer to the front part of the list
node * rear;  //pointer to the rear end of the list
//function to check if the list is empty
int isEmpty(){
  if((front == NULL) && (rear == NULL)){    
    return 1;
  }
  else{
    return 0;
  }
}
//funtion to return the front element of the list
int Front(){
  return front -> value;
}
//function to add a node at the rear end with value as the passed integer 
void enqueue(int x){
  if(isEmpty()){    
    node * temp = malloc(sizeof(*temp));
    temp -> value = x;
    temp -> next = NULL;
    front = temp;
    rear = temp;
  }
  else{
    node * temp = malloc(sizeof(*temp));
    temp -> value = x;
    temp -> next = NULL;
    rear -> next = temp;
    rear = temp;
  }
}
//function to remove a node from the front end of the list
void dequeue(){
  if(front == NULL){    
    printf("No elements to dequeue\n");
    return;
  }
  else if(rear == front){ //if there is only one element in the list
    free(front);
    rear = NULL;
    front = NULL;
  }
  else{
    node * temp1 = front;
    front = front -> next;
    free(temp1);
  }   
}
//function to print the list
void print(){  
  node * pr = front;
  if(front == NULL){
    printf("no elements to print\n");
    return;
  }
  while(pr!= NULL){
    printf("%d ",pr -> value);
    pr = pr -> next;
  }
  printf("\n");
}
//function to free the allocated memory
void freeMem(){
  node * fr;
  while(front!=NULL){
    fr = front;
    front = front -> next;
    free(fr);
  }
}
    
int main(){
  front = NULL;
  rear = NULL;
  enqueue(23);//list:23
  print();
  enqueue(12);//list:23 12
  print();
  printf("%d\n",Front());//23
  enqueue(78);//23 12 78
  print();
  printf("%d\n",Front());//23
  enqueue(45);//23 12 78 45
  print();
  printf("%d\n",Front()); //23
  dequeue();//12 78 45
  print();
  printf("%d\n",Front());//12
  dequeue();//78 45
  print();
  dequeue();//45
  print();
  dequeue();//list will be empty
  print();
  freeMem();
  return 0;
}
