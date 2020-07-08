//Header file for the queue of pointers with array
int n; //initial size of the array
void ** A;   //pointer to the array of pointer which will store the addresses of nodes
int rear;  //rear & front are initialised to -1 which denotes empty array
int front;


int isEmpty();
int isFull();
void enqueue(void * x);
void dequeue();
void * Front();
void print();
