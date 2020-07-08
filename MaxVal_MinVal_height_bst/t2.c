//program to find the minimum & maximum element in a binary search tree and also the height of a binary tree(which will work for a binary search tree of course)
#include<stdio.h>
#include<stdlib.h>

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
//function to find the minimum element in a binary search tree. In this function recursion is used to go as left as possible in the tree which is where the min element is situated
int findMax(bstNode * temp){
  if(temp == NULL){
    printf("No elements in the tree\n");
    return -1;
  }
  else if(temp -> right == NULL){
    return temp-> data;
  }
  findMax(temp -> right);
}
//function to find the maximum element in a binary search tree. In this function recursion is used to go as right as possible in the tree which is where the max element is situated
int findMin(bstNode * temp){
  if(temp == NULL){
    printf("No elements in the tree\n");
    return -1;
  }
  else if(temp -> left == NULL){
    return temp -> data;
  }
  findMin(temp -> left);
}
//this function returns the maximum of the passed in two integers
int max(int a,int b){
  if(a<b){
    return b;
  }
  else{
    return a;
  }
}
//function to find the height of a binary tree.The concept used here is that the height of a node is maximum of the height of its two subtrees added 1. Recursion has been used to apply the same.
int findHeight(bstNode * temp){
  if(temp == NULL){    
    return -1;
  }  
  return(max(findHeight(temp -> left),findHeight(temp -> right)) + 1);
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
  printf("Max value = %d\n",findMax(root));
  printf("Min value = %d\n",findMin(root));
  printf("Height of the tree is = %d\n",findHeight(root));
  free_tree(root);
  return 0;
}
