//Array implementation of queue
#include<stdio.h>
#include<stdlib.h>
int n = 3; //initial size of the array
int * A; 
int rear = -1;  //rear & front are initialised to -1 which denotes empty array
int front = -1;
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
  if(((rear+1)%n) == front){
    return 1;
  }
  else{
    return 0;
  }
}
//function to add a number to the rear end of the array
void enqueue(int x){
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
int Front(){
  if(!isEmpty()){
    return A[front];
  }
  else{
    printf("The list is empty\n");
  }
}
//prints the array
void print(){  
  if(!isEmpty()){    
    for(int i = front;i<=rear;i=(i+1)%n){
    printf("%d ",A[i]);
    }
  }  
  else{
    printf("The list is empty\n");
  }
  printf("\n");
}
int main(){
  A = malloc(n * (sizeof(*A)));
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
  free(A); //freeing the allocated memory
  return 0;
}
