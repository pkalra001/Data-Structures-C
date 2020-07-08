//implementation of stack using array
#include<stdio.h>
#include<stdlib.h>

int n = 2;      //no. of elements in the array at first
int * A = NULL; //array declared as a global variable
int top =-1;    //for empty list top is set as -1
//this function pushes the element d in the stack
void push(int d){
  top+=1;
  if(top == n){   //if the array is filled,it is reallocated with double space as before
    n*=2;
    A = realloc(A,n*(sizeof(*A)));
  }    
  A[top] = d;  
}
//this function sets the seceond last element as the top element which essentially means removing the last element
void pop(){
  if(top == -1){
    printf("No element to pop\n");
    return;
  }
  top-=1;
}
//this function returns the last element in the array i.e top element in the stack
int Top(){
  if(top == -1){
    printf("The stack is empty\n");
    return 0;
  }
  return (A[top]);
}
//This function returns true if the stack is empty,false otherwise
int isEmpty(){
  if(top == -1){
    return 1;
  }
  else{
    return 0;
  }
}
//function to prints all the elements in the stack
void print(){
  if(top==-1){
    printf("No elements to print\n");
    return;
  }
  for(int i= 0;i<=top;i++){
    printf("%d ",A[i]);
  }
  printf("\n");
}
//function to free all the allocated memory
void freeMem(){
  free(A);
}

int main(){
  A = malloc((n)*(sizeof(*A)));
  push(23);//stack:23
  print();
  push(45);//stack:23 45
  print();
  pop();//stack:23
  print();
  push(67);//stack:23 67
  print();
  printf("%d\n",Top());//top() = 67
  printf("%d\n",isEmpty());//isEmpty should return 0
  pop();//stack:23
  print();
  pop();//stack:<empty>
  print();
  printf("%d\n",isEmpty());//isEmpty should return 1
  freeMem();
  return 0;
}
