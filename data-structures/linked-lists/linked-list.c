#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
} ;

typedef struct node node;

int main(){
	node n1;
	node* HEAD = &n1;
	n1.value = 13;
	n1.next = NULL;
	printf("%d", n1.value);
	return 0;
}
