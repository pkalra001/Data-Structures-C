//C program to insert a node at the beginning of the linked list

#include<stdio.h>
#include<stdlib.h>


struct node_t{

  int data;                           
  struct node_t * next;
};
typedef struct node_t node;

node * head;                 // head will be used as a pointerto the head node and is declared as a global variable

//This function takes the data d, puts it in a newly created node and places the node in the beginning of the linked list
void insert(int d){

  node * temp = malloc(sizeof(*temp));
  temp -> data = d;
  temp -> next = head;
  head = temp;
}
//This function prints the linked list 
void print(){
  node * ptr = head;
  printf("The list looks like:");    
  while(ptr!=NULL){
    printf("%d ",ptr ->data);
    ptr = ptr -> next;
  }
  printf("\n");
}
//This function frees the allocated memory
void freeMem(){
  while(head!=NULL){
    node * temp = head;
    head = head ->next;
    free(temp);
  }
}

int main(){

  head =NULL;
  int n,p;
  printf("How many numbers do you want to enter in the linked list?\n");
  scanf("%d",&n);
  printf("Please enter the numbers\n");
  for(int i=0;i<n;i++){
    scanf("%d",&p);
    insert(p);
    print();
  }
  freeMem();
  return 0;
}
