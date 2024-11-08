#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

node *head = NULL;

node *createnode();
void insertfront();
void insertend();
void insertafter(int);
void deletefront();
void deleteend();
void delete(int);
void display();

int main() {
    int opt, exit = 0, element;
    printf("MENU:\n1. insert at front\n2. insert at end\n3. insert after "
           "element\n");
    printf("4. delete from front\n5. delete from end\n6. delete element\n7. "
           "exit\n");
    while (!exit) {
        printf("enter option: ");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            insertfront();
            display();
            break;
        case 2:
            insertend();
            display();
            break;
        case 3:
            printf("enter element to insert after: ");
            scanf("%d", &element);
            insertafter(element);
            display();
            break;
        case 4:
            deletefront();
            display();
            break;
        case 5:
            deleteend();
            display();
            break;
        case 6:
            printf("enter element to delete: ");
            scanf("%d", &element);
            delete(element);
            display();
            break;
        case 7:
            exit = 1;
            break;
        default:
            printf("invalid option\n");
        }
    }
}

node *createnode() {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("enter data in node: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

void insertfront() {
    node *new = createnode();
    if (head == NULL) {
        head = new;
        new->next = head;  // Point to itself for first node
    } else {
        node *ptr = head;
        // Find the last node
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        new->next = head;
        head = new;
        ptr->next = head;  // Last node points to new head
    }
}

void insertend() {
    node *new = createnode();
    if (head == NULL) {
        head = new;
        new->next = head;  // Point to itself for first node
    } else {
        node *ptr = head;
        // Find the last node
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        ptr->next = new;
        new->next = head;  // New last node points back to head
    }
}

void insertafter(int value) {
    if (head == NULL) {
        printf("empty linked list\n");
    } else {
        node *ptr = head;
        // Search for the value
		while (ptr->next != head) {
			if (ptr->data == value) {
				break;
			}
			ptr = ptr->next;
		}

        if (ptr->data != value) {
            printf("not found\n");
        } else {
            node *new = createnode();
            new->next = ptr->next;
            ptr->next = new;
        }
    }
}

void deletefront() {
    if (head == NULL) {
        printf("list is empty\n");
    } else if (head->next == head) {
        // Only one node in the list
        free(head);
        head = NULL;
    } else {
        node *ptr = head;
        // Find the last node
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        node *temp = head;
        head = head->next;
        ptr->next = head;  // Last node points to new head
        free(temp);
    }
}

void deleteend() {
    if (head == NULL) {
        printf("list is empty\n");
    } else if (head->next == head) {
        // Only one node in the list
        free(head);
        head = NULL;
    } else {
        node *ptr = head;
        node *prev = NULL;
        // Find the last node
        while (ptr->next != head) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = head;  // Second-to-last node points to head
        free(ptr);
    }
}

void delete(int item) {
    if (head == NULL) {
        printf("empty linked list\n");
    } else {
        node *ptr = head;
        node *prev = NULL;
        
        // Handle first node separately
        if (ptr->data == item) {
            deletefront();
            return;
        }
        
        // Search for the item
        do {
            if (ptr->data == item) {
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        } while (ptr != head);

        if (ptr == head) {
            printf("element not found\n");
        } else {
            prev->next = ptr->next;
            free(ptr);
        }
    }
}

void display() {
    if (head == NULL) {
        printf("empty linked list\n");
        return;
    }
    node *ptr = head;
    do {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
