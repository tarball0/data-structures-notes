/* Find maximum value of even numbers from a singly linked list */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* llink;
    struct Node* rlink;
}Node;

Node *head = NULL;

Node *createNode(){
    Node *new = malloc(sizeof(Node));
    if(new){
        printf("Enter data: ");
        scanf("%d", &(new->data));
        new->llink = NULL;
        new->rlink = NULL;
        return new;
    }
    else{
        printf("Memory allocation failed");
        exit(0);
    }
}

void *listRead(){
    Node *ptr = createNode();
    if (!head) head = ptr;
    else{
        head->llink = ptr;
        ptr->rlink = head;
        head = ptr;
    }
}

void listDisplay(){
    Node *temp = head;
    while(temp){
        printf("%d", temp->data);
        temp = temp->rlink;
        if(temp) printf(", ");
    }
}

int findEvenMax(){
    Node *temp = head;
    int max=-1;
    while(temp->rlink){
        if(!(temp->data % 2) && temp->data > max) max = temp->data;
        temp = temp->rlink;
    }
    return max;
}

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) listRead();
    printf("\nList: ");
    listDisplay();
    printf("\nMax value even number: %d", findEvenMax());
}
