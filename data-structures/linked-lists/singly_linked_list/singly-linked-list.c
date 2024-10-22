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
            delete (element);
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
    } else {
        new->next = head;
        head = new;
    }
}

void insertend() {
    node *new = createnode();
    if (head == NULL) {
        head = new;
        new->next = NULL;
    } else {
        node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}

void insertafter(int value) {
    if (head == NULL) {
        printf("empty linked list\n");
    } else {
        node *ptr = head;
        while (ptr->next != NULL) {
            if (ptr->data == value) {
                break;
            }
            ptr = ptr->next;
        }
        if (ptr->next == NULL && ptr->data != value) {
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
    } else {
        node *ptr = head;
        head = ptr->next;
        free(ptr);
    }
}

void deleteend() {
    if (head == NULL) {
        printf("list is empty\n");
    } else {
        node *ptr = head;
        node *prev = NULL;
        while (ptr->next != NULL) {
            prev = ptr;
            ptr = ptr->next;
        }
        free(ptr);
        prev->next = NULL;
    }
}

void delete(int item) {
    if (head == NULL) {
        printf("empty linked list\n");
    } else {
        node *ptr = head;
        node *prev = NULL;
        while (ptr != NULL) {
            if (ptr->data == item) {
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            printf("element not found\n");
        } else if (prev == NULL) {
            deletefront();
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
    while (ptr != NULL) {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
