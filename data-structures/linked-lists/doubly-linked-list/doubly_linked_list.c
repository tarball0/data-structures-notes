#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{

    struct Node* Llink;
    int data;
    struct Node* Rlink;
} Node;

Node* head = NULL;

Node* createNode(){

    Node* node = malloc(sizeof(Node));

    if (node == NULL){

        printf("Node creation failed");
		return NULL;
    }

    else{

        printf("Enter Element: ");
        scanf("%d", &(node -> data));
        node -> Llink = node -> Rlink = NULL;

        return node;
    }
}

void displayList(){

    if (head == NULL){

        printf("List is Empty");
        return;
    }

    Node* temp = head;

    printf("\nElements: ");

//    printf("%d ", head -> data);			// why?
//    temp = temp -> Rlink;

    while (temp != NULL){
        
        printf("%d ", temp -> data);
        temp = temp -> Rlink;
    }
    return;
}

void insertFront(){

    Node* new = createNode();

    if (head == NULL){

        head = new;
    }

    else{
        
        head -> Llink = new;
        new -> Rlink = head;
        head = new;
    }
    
}

void insertEnd(){

    Node* new = createNode();

    if (head == NULL){

        head = new;
    }

    else{
        
       Node* temp = head;
       while (temp -> Rlink != NULL){

            temp = temp -> Rlink;
       }
        
       new -> Llink = temp;
       temp -> Rlink = new;
    }
}

void insertSpecific(){

    if (head == NULL){

        //printf("List has no Elements");
        return;
    }

    int key, flag = 0;

    printf("Enter element after which new data is to be inserted: ");
    scanf("%d", &key);

    Node* new = createNode();

    if (head -> data == key){

        if (head -> Rlink == NULL){

            new -> Llink = head;
            head -> Rlink = new;
        }

        else{

            new -> Rlink = head -> Rlink;
            new -> Llink = head;
            head -> Rlink = new;
        }

        flag = 1;
    }

    else{

        Node* temp = head;

        while (temp -> data != key && temp -> Rlink != NULL){

            temp = temp -> Rlink;
        }

        if (temp -> data == key){

            if (temp -> Rlink != NULL){

                temp -> Rlink -> Llink = new;
                new -> Rlink = temp -> Rlink;
                new -> Llink = temp;
                temp -> Rlink = new;
            }

            else{

                temp -> Rlink = new;
                new -> Llink = temp;
            }

            flag = 1;
        }
    }
}

void deleteFront(){

    if (head == NULL){

        //printf("List has no Elements");
        return;
    }

    else{
        
        Node* temp;
        temp = head;
        
        if (head -> Rlink != NULL){

            head -> Rlink -> Llink = NULL;
        }

        head = head -> Rlink;

        free(temp);
    }
}

void deleteEnd(){

    if (head == NULL){

        //printf("List has no Elements");
        return;
    }
    
    else{

        Node* temp = head;
        
        while (temp -> Rlink != NULL){
            
            temp = temp -> Rlink;
        }
        
        if (temp -> Llink == NULL){

            head = NULL;
        }

        else{

            temp -> Llink -> Rlink = NULL;
        }
        
        free(temp);
    }
}

void deleteSpecific(){

    if (head == NULL){

        //printf("List has no Elements");
        return;
    }

    Node* temp;
    int key;
    
    printf("Enter element to be deleted: ");
    scanf("%d", &key);

    if (head -> data == key){

        if (head -> Rlink == NULL)
        {
            
            free(head);
            head = NULL;
        }

        else{

            head -> Rlink -> Llink = NULL;
            temp = head;
            head = head -> Rlink;
            free(temp);
        }
        
    }

    else{

        temp = head;

        while (temp -> data != key && temp -> Rlink != NULL){

            temp = temp -> Rlink;
        }

        if (temp -> data == key){

            if (temp -> Rlink == NULL){
                
                temp -> Llink -> Rlink = NULL;
            }
            
            else{

                temp -> Rlink -> Llink = temp -> Llink;
                temp -> Llink -> Rlink = temp -> Rlink;
            }

            free(temp);
        }

        else{

            printf("Specified element is absent from the List");
        }

    }
}

void searchElement(){

    if (head == NULL){

        printf("List has no Elements");
        return;
    }

    else{

        Node* temp = head;
        int key, i = 0;

        printf("Enter element to be searched: ");
        scanf("%d", &key);
        
        while (temp -> data != key && temp -> Rlink != NULL){

            temp = temp -> Rlink;
            i++;
        }

        if (temp -> data == key){
        
            printf("Element found at position %d", i + 1);
        }

        else{

            printf("Element not found");
        }
    }
}

int main(){


    int choice;

    printf("\n#### MENU ####\n");
	printf("\n1.Insert at Front");
	printf("\n2.Insert at End");
	printf("\n3.Insert after Element");
	printf("\n4.Delete from Front");
	printf("\n5.Delete from End");
	printf("\n6.Delete Specific Element");
	printf("\n7.Search Element");
	printf("\n8.Display Elements");
	printf("\n9.Exit");

    while (choice != 9) {
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            insertFront();
            displayList();
            break;

        case 2:
            insertEnd();
            displayList();
            break;

        case 3:
            insertSpecific();
            displayList();
            break;

        case 4:
            deleteFront();
            displayList();
            break;

        case 5:
            deleteEnd();
            displayList();
            break;

        case 6:
            deleteSpecific();
            displayList();
            break;

        case 7:
            searchElement();
            break;

        case 8:
            displayList();
            break;

        default:
            break;
        }
    }
    
    return 0;
}
