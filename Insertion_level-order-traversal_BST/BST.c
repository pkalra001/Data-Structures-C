#include<stdio.h>
#include<stdlib.h>
#include "queue_with_array.h"

struct bstNode_t{   //each node of the bst tree is declared as a struct with three fields
  int data;         //stores the data which is integer in this case
  struct bstNode_t * left;     //it saves the address of the left node in the subtree
  struct bstNode_t * right;    //it saves the address of the right node in the subtree
};
typedef struct bstNode_t bstNode;

bstNode * root;          //pointer to the root node of the tree
//function to create and return a new node with data as the passed value
bstNode * getNewNode(int value){
  bstNode * temp = malloc(sizeof(*temp));
  temp -> data = value;
  temp -> left = NULL;
  temp -> right = NULL;
  return temp;  
}
//function to insert a node with the passed value in the bst tree using recursion
bstNode * insert(bstNode * ptr,int value){
  if(ptr == NULL){              
    ptr = getNewNode(value);   
  }
  else if(value <= ptr->data){           
    ptr -> left = insert(ptr -> left,value);
  }
  else{
    ptr -> right = insert(ptr -> right,value);
  }
  return ptr;
}
//bst is printed with level order traversal using queue of node addesses
void PrintTree(){
  if(root == NULL){
    printf("No elements in the tree\n");
    return;
  }
  else{
    enqueue(root);
    while(!isEmpty()){
      bstNode * current = Front();
      printf("%d ",current -> data);
      if((current -> left)!= NULL){
	enqueue(current ->left);
      }
      if((current -> right)!= NULL){
      enqueue(current -> right);
      }
      dequeue();
    }
  }
  printf("\n");
}
//function to free the memory allocated for tree nodes using post-order traversal
void free_tree(bstNode * ptr){
  if(ptr!=NULL){
    free_tree(ptr->left);
    free_tree(ptr->right);
    free(ptr);
  }
}
int main(){
  n = 8; //initial size of the array used for the queue
  A = malloc(n*(sizeof(*A))); //allocated memory to the pointer to the array for queue
  rear = -1;  //rear & front are initialised to -1 which denotes empty array
  front = -1;
  root = NULL;
  //insertions are made with data from the image to confirm the correctness of the program
  root = insert(root,30);
  root = insert(root,15);
  root = insert(root,60);
  root = insert(root,45);
  root = insert(root,75);
  root = insert(root,22);
  root = insert(root,7);
  root = insert(root,27);
  root = insert(root,17);  
  PrintTree();
  free(A);
  free_tree(root);
  return 0;
}
