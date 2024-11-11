 /* Input 2 linked list. Sort them. Merge the sorted lists. Sort this merged linked list. Then print it in reverse. Do using doubly linked list */

 #include <stdio.h>
 #include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* llink;
    struct Node* rlink;
}Node;

Node *head1 = NULL;
Node *head2 = NULL;

Node *createNode(Node *head){
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

Node *listRead(Node *head){
    Node *ptr = createNode(head);
    if (!head) head = ptr;
    else{
        head->llink = ptr;
        ptr->rlink = head;
        head = ptr;
    }
    return head;
}

Node *listSort(Node *head){
    int num;
    Node *temp1 = head;
    while(temp1){
        Node *temp2 = head;
        while(temp2){
            if(temp1->data < temp2->data){
                num = temp1->data;
                temp1->data = temp2->data;
                temp2->data = num;
            }
            temp2=temp2->rlink;
        }
        temp1=temp1->rlink;
    }
}

void listMerge(){
    Node *temp = head1;
    while(temp->rlink){
        temp=temp->rlink;
    }
    head2->llink = temp;
    temp->rlink = head2;
}

void listDisplay(Node *head){
    Node *temp = head;
    while(temp){
        printf("%d", temp->data);
        temp = temp->rlink;
        if(temp) printf(", ");
    }
}

void listDisplayReverse(){
    Node *temp=head1;
    while(temp->rlink){
        temp=temp->rlink;
    }
    while(temp){
        printf("%d", temp->data);
        temp=temp->llink;
        if(temp) printf(", ");
    }
}

void main(){
    int n1, n2;
    printf("Enter number of terms for two linked lists: ");
    scanf("%d%d", &n1, &n2);
    printf("Enter elements of first linked list: \n");
    for(int i = 0; i < n1; i++) head1 = listRead(head1);
    printf("Unsorted first linked list: ");
    listDisplay(head1);
    printf("\nSorted first linked list: ");
    listSort(head1);
    listDisplay(head1);
    printf("\nEnter elements of second linked list: \n");
    for(int i = 0; i < n2; i++) head2 = listRead(head2);
    printf("Unsorted second linked list: ");
    listDisplay(head2);
    printf("\nSorted second linked list: ");
    listSort(head2);
    listDisplay(head2);
    printf("\nMerged List: ");
    listMerge();
    listDisplay(head1);
    printf("\nSorted Merged List: ");
    listSort(head1);
    listDisplay(head1);
    printf("\nSorted Merged List in Reverse: ");
    listDisplayReverse();
}
