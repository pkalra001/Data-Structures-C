//implementation of queue using arrays.This queue will be used to save pointers(memory addresses) of nodes of a bst which will be eventually used for the level order traversal of the tree
#include<stdio.h>
#include<stdlib.h>
#include "queue_with_array.h"


//fuction to check if the array is empty
int isEmpty(){
  if((rear == -1) && (front == -1)){
    return 1;
  }
  else{
    return 0;
  }
}
//function to check if the array is full
int isFull(){
  if(((rear+1)%n) == front){  //circular array
    return 1;
  }
  else{
    return 0;
  }
}
//function to add a pointer to the rear end of the array
void enqueue(void * x){
  if(isEmpty()){
    rear=0;
    front=0;
  }
  else{
    rear=(rear+1)%n; //using the concept of circular array to save the memory
    if(isFull()){  //if the array is full twice the original memory is allocated to the array
      n*=2;
      A = realloc(A,n*(sizeof(*A)));
    }
  }
  A[rear] = x;
}
//function to remove an element from the front end of the array
void dequeue(){
  if(isEmpty()){
    printf("No elements to dequeue.\n");
    return;
  }
  else if(rear == front){    //when there is only one(first) element in the array
    rear = -1;
    front = -1;
  }
  else{
    front=(front +1)%n;  //concept of the circular array
  }
}
//function to return the front element of the array
void * Front(){
  if(!isEmpty()){
    return A[front];
  }
  else{
    printf("The list is empty\n");
    return NULL;
  }
}
//prints the array
void print(){
  if(!isEmpty()){
    for(int i = front;i<=rear;i=(i+1)%n){
      printf("%p ",A[i]);
    }
  }
  else{
    printf("The list is empty\n");
  }
  printf("\n");
}
