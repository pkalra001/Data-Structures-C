CFLAGS= -g -Wall -Werror -pedantic -std=gnu99
BST:queue_with_array.c queue_with_array.h BST.c
	gcc $(CFLAGS) -o BST queue_with_array.c queue_with_array.h BST.c
.PHONY= clean
clean:
	rm BST *.c~ *.h~
