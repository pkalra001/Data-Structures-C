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
void print_inorder(bstNode * temp){
  if(temp==NULL){
    return;
  }
  print_inorder(temp->left);
  printf("%d ",temp -> data);
  print_inorder(temp->right);
}
bstNode * find(bstNode * temp,int value){
  if(temp == NULL){
    return NULL;
  }
  if(value < temp->data){
    find(temp -> left,value);
  }
  else if(value > temp->data){
    find(temp -> right,value);
  }
  else{
    return temp;
  }
}
bstNode * findMin(bstNode * temp){
  if(temp->left == NULL){
    return temp;
  }
  else{
    findMin(temp -> left);
  }
}
bstNode * inor_succ(bstNode * temp,int value){
  temp = find(root,value);
  if(temp == NULL){
    printf("%d is not there in the tree\n",value);
    exit(EXIT_FAILURE);
  }
  if(temp->right!=NULL){    
    return findMin(temp -> right);
  }
  else{
    bstNode * ancestor = root;
    bstNode * successor = NULL;
    while(ancestor!=temp){
      if(value < ancestor->data){
	successor = ancestor;
	ancestor = ancestor->left;
      }
      else{
	ancestor = ancestor->right;
      }
    }
    return successor;
  }
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
  root = insert(root,26);
  root = insert(root,29);
  print_inorder(root);
  printf("\n");
  int f = 76;
  bstNode * temp = inor_succ(root,f);
  if(temp!=NULL){
    printf("Successor of %d is %d\n",f,temp->data);
  }
  else{
    printf("There is no successor of %d\n",f);
  }
  free_tree(root);
  return 0;
}
