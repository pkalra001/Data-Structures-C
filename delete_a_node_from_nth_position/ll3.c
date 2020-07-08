//C program to delete a node from nth position in linked list
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
//This function takes the node number and delete it from the list
void delete(int n){
  if(n==1){
    node * temp = head;
    head = head->next;
    free(temp);
  }
  else{
    node * prev = head;
    for(int i=0;i<(n-2);i++){
      prev = prev ->next;
    }
    node * toDelete = prev ->next;
    node * nextToDel = toDelete ->next;
    prev ->next = nextToDel;
    free(toDelete);
  }
}
    
  
  
int main(){

  head =NULL;  
  printf("Currently the list looks like this:\n");
  insert(2);
  insert(45);
  insert(99);
  insert(21);
  print();//prints the list: 21 99 45 2
  int n;
  printf("Enter the node number to be deleted in the range [1,4]\n");
  scanf("%d",&n);
  delete(n);
  printf("Now the list looks like:\n");
  print();  //prints the list after deletion
  freeMem();
  return 0;
}
