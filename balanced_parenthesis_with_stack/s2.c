//Check for balanced parenthesis using stack
#include<stdio.h>
#include<stdlib.h>

int n = 10; //initial size of the stack
char * A;   //array for the stack declared as a global variable
int top =-1; //top is intialized as -1 denoting empty stack

//this function adds the passed character on the stack/array
void push(char c){
  top+=1;
  if(top == n){  //if the array is full,twice as much memory is reallocated to it
    n*=2;
    A = realloc(A,n*(sizeof(*A)));
  }
  A[top] = c;
}
//this function removes the topmost element of the stack
void pop(){
  if(top==-1){
    printf("No elements to pop\n");
    return;
  }
  top-=1;
}
//this function returns the topmost character in the stack
char Top(){
  return A[top];
}
//this function returns true is the stack is empty else false
int isEmpty(){
  if(top==-1){
    return 1;
  }
  else{
    return 0;
  }
}
//this function returns 1 if the passed in close bracket matches with the last element in the stacke else 0
int isMatching(char c){
  if(c==')'){
    if(Top() == '('){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if(c=='}'){
    if(Top() == '{'){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    if(Top() == '['){
      return 1;
    }
    else{
      return 0;
    }
  }
}

int main(){
  //Tested on all of the strings below
  //char str[] = "({)}";//not balanced
  //char str[]= "()[";//not balanced
  //char str[] = "{()}";//balanced
  //char str[] = "[{}]";//balanced
  char str[] = "{{{[]()()}}}";//balanced
  int i =0;
  A = malloc(n*(sizeof(*A)));
  while(str[i]!='\0'){
    if((str[i] == '(')||(str[i] == '{')||(str[i] == '[')){ //pushing if it's an open bracket
      push(str[i]);
    }    
    else if((str[i] == ')')||(str[i] == '}')||(str[i] == ']')){ 
      if((isEmpty())||(!isMatching(str[i]))){     //if the bracket is a closing one but either stack is empty or its not matching the previous open bracket in the stack then the string is not balanced
	printf("Not balanced\n");
	return 0;
      }
      else{
	pop(); //its matching the previous bracket,so that one is popped off the stack
      }
    }
    i++;    
  }
  if(isEmpty()==1){                //after traversing through the whole string if the stack is empty, then the string is balanced
    printf("Balanced\n");
  }
  else{
    printf("Not balanced\n");    //else its not balanced
  }
  free(A);
  return 0;
}
  
