//this program check if a binary tree is a binary search tree or not
#include<stdio.h>
#include<stdlib.h>
#define INT_MIN -2147483648   //macro for minimum possible value of an int
#define INT_MAX 2147483648   //macro for maximum possible value of an int
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
//this function is the actual function which checks if the tree is a binary search tree. It uses recursion and works on the concept that for every node in a binary search tree all the elements in its left subtree have values between INT_MIN & data in the node and all the elements in its right subtree has values between data in the node& INT_MAX.
int isBST_util(bstNode * temp,int min,int max){
  if(temp == NULL){
    return 1;
  }
  if((temp -> data > min) && ((temp -> data) < max) && (isBST_util(temp -> left,INT_MIN,temp -> data)) && (isBST_util(temp -> left,INT_MIN,temp -> data))){
    return 1;
  }
  else{
    return 0;
  }
}
//function to be called from the main to check if a binary tree is a binary a search tree or not
int isBST(){
  return isBST_util(root,INT_MIN,INT_MAX);
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
  int a = isBST();
  if(a == 1){
    printf("It is a BST\n");
  }
  else{
    printf("It is a BST\n");
  }
  free_tree(root);
  return 0;
}
