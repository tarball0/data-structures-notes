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
void reverse();
void sort();

int main() {
    int opt, exit = 0, element;
    printf("MENU:\n1. insert at front\n2. insert at end\n3. insert after "
           "element\n");
    printf("4. delete from front\n5. delete from end\n6. delete element\n7. "
           "reverse\n8. sort\n9. exit\n");
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
			reverse();
			display();
			break;
		case 8:
			sort();
			display();
			break;
        case 9:
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
        while (ptr != NULL) {
            if (ptr->data == value) {
				node *new = createnode();
				new->next = ptr->next;
				ptr->next = new;
                break;
            }
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            printf("not found\n");
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

void reverse() {
	if (head == NULL) {
		printf("empty list\n");
		return;
	}
	node *prev = NULL;
	node *current = head;
	node *next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

// using selection sort
void sort() {
	if (head == NULL) {
		printf("empty list\n");
		return;
	}
	int tmp;
	node *min;
	node *ptr1 = head;
	node *ptr2 = NULL;

	while (ptr1->next != NULL) {
		ptr2 = ptr1->next;
		min = ptr1;
		while (ptr2 != NULL) {
			if (ptr2->data < min->data) {
				min = ptr2;
			}
			ptr2 = ptr2->next;
		}
		tmp = ptr1->data;
		ptr1->data = min->data;
		min->data = tmp;

		ptr1 = ptr1->next;
	}
}

void display() {
    if (head == NULL) {
        printf("empty linked list\n");
        return;
    }
    node *ptr = head;
	printf("[");
    while (ptr != NULL) {
        printf("%d", ptr->data);
		if (ptr->next != NULL) {
			printf(", ");
		}
        ptr = ptr->next;
    }
	printf("]");
    printf("\n");
}
