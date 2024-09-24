#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int data;
    struct node *next;
} node;

node *head = NULL;

/* 							CHANGES:
 * changed some int functions to void functions since there weren't
 * return statements in all control paths, which could cause undefined behaviour.
 * return would still work with void though.
 *
 * menu outside the for-loop (you only need to see the menu once mf)
 *
 * also turned it into top down cause it's neater, :)))))
 */

node *createNode();
void searchElement();
void insertElement();
void insertFront();
void insertEnd();
void displayList();
void deleteElement();
void deleteEnd();
void deleteFront();

int main() {

    int choice = 0;

	printf("\n#### MENU ####\n");
	printf("\n1.Insert at Front");
	printf("\n2.Insert at End");
	printf("\n3.Insert after Element");
	printf("\n4.Delete from Front");
	printf("\n5.Delete from End");
	printf("\n6.Delete Element");
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
            insertElement();
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
            deleteElement();
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
}

node *createNode() {

    node *new = malloc(sizeof(node));

    if (new == NULL)
        printf("Memory is Full");

    printf("\nEnter Element to be entered: ");
    scanf("%d", &new->data);
    new->next = NULL;
    return new;
}

void displayList() {

    if (head == NULL)
        printf("\nList is Empty\n");

    else {

        node *temp = head;

        printf("\nElements: ");
        while (temp->next != NULL) {

            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("%d \n", temp->data);
    }
}

void insertFront() {

    node *ptr = createNode();
    ptr->next = head;
    head = ptr;
}

void insertEnd() {

    node *ptr = createNode(), *temp = head;

    while (temp->next != NULL) {

        temp = temp->next;
    }

    temp->next = ptr;
}

void insertElement() {

    node *ptr = createNode(), *temp = head;
    int elem, flag = 0;

    if (head == NULL)
        return;

    printf("\nEnter existing element: ");
    scanf("%d", &elem);

    while (temp->next != NULL) {

        if (temp->data == elem) {

            flag++;
            break;
        }
        temp = temp->next;
    }

    if (flag != 0 || temp->data == elem) {

        ptr->next = temp->next;
        temp->next = ptr;
    }

    else
        printf("\nSpecified Element is Absent\n");
}

void deleteFront() {

    if (head != NULL) {

        node *temp = head;
        head = temp->next;
        free(temp);
    }
}

void deleteEnd() {

    if (head == NULL) {
    }

    else if (head->next == NULL) {

        node *temp = head;
        head = NULL;
        free(temp);
    }

    else {
        node *temp, *ptr;

        temp = head;
        ptr = temp;

        while (temp->next != NULL) {

            ptr = temp;
            temp = temp->next;
        }

        ptr->next = NULL;
        free(temp);
    }
}

void deleteElement() {

    node *temp = head;
    node *ptr;
    int elem, flag = 0;

    if (head == NULL)
        return;

    else if (head->next == NULL) {

        printf("\nEnter element to be deleted: ");
        scanf("%d", &elem);

        if (head->data == elem) {

            temp = head;
            head = NULL;
            printf("\nDeleted Element: %d", temp->data);
            free(temp);
            return;
        }

        else
            printf("\nElement not found");
        return;
    }

    printf("\nEnter element to be deleted: ");
    scanf("%d", &elem);

    while (temp->next != NULL) {

        if (temp->data == elem) {

            flag++;
            break;
        }
        ptr = temp;
        temp = temp->next;
    }

    if (flag != 0 || temp->data == elem) {

        ptr->next = temp->next;
        printf("\nDeleted Element: %d", temp->data);
        free(temp);
    }

    else
        printf("\nElement not found");
}

void searchElement() {

    node *temp = head;
    int elem, loc = 1, flag = 0;

    printf("\nEnter element to be searched: ");
    scanf("%d", &elem);

    while (temp->next != NULL) {

        if (temp->data == elem) {

            flag++;
            break;
        }
        temp = temp->next;
        loc++;
    }

    if (flag != 0 || temp->data == elem) {

        printf("\nElement found at location %d", loc);

    }

    else
        printf("\nElement not found");
}
