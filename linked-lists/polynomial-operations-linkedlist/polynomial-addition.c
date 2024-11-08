#include <stdio.h>
#include <stdlib.h>

struct node {
    int expo;
    int coeff;
    struct node *next;
};
typedef struct node node;

node *input();
node *createnode(int, int);
void insert(node **, node **, node **);
void display(node *);
node *add(node *, node *);

int main() {
    printf("enter polynomial 1: \n");
    node *p1 = input();
	if (p1 == NULL) {
		return -1;
	}

    printf("enter polynomial 2: \n");
    node *p2 = input();
	if (p2 == NULL) {
		return -1;
	}
    printf("polynomial 1: ");
    display(p1);
    printf("polynomial 2: ");
    display(p2);
    node *p3 = add(p1, p2);
	printf("sum: ");
	display(p3);
    return 0;
}

node *add(node *p1, node *p2) {
    node *t1 = p1;
    node *t2 = p2;
    node *headr = NULL, *tailr = NULL;
	node *new;

    while (t1 != NULL && t2 != NULL) {
        if (t1->expo == t2->expo) {
            new = createnode((t1->coeff + t2->coeff), t1->expo);
			t1 = t1->next;
			t2 = t2->next;
        } else if (t1->expo > t2->expo) {
            new = createnode(t1->coeff, t1->expo);
			t1 = t1->next;
        } else if (t2->expo > t1->expo) {
            new = createnode(t2->coeff, t2->expo);
			t2 = t2->next;
        }
		insert(&headr, &tailr, &new);
    }

	while (t1 != NULL) {
		new = createnode(t1->coeff , t1->expo);
		insert(&headr, &tailr, &new);
		t1 = t1->next;
	}

	while (t2 != NULL) {
		new = createnode(t2->coeff, t2->expo);
		insert(&headr, &tailr, &new);
		t2 = t2->next;
	}
	return headr;
}

node *createnode(int coeff, int expo) {
    node *new = (node *)malloc(sizeof(node));
    new->coeff = coeff;
    new->expo = expo;
    new->next = NULL;
    return new;
}

node *input() {
    node *head = NULL, *tail = NULL;
    int n, exp, coeff;
    printf("enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("enter coeff: ");
        scanf("%d", &coeff);
        printf("enter expo: ");
        scanf("%d", &exp);
        node *new = createnode(coeff, exp);
        if (head == NULL && tail == NULL) {
			head = tail = new;
        } else if (head->expo < exp) {
        	new->next = head;
			head = new;
        } else if (tail->expo > exp) {
			tail->next = new;
			tail = tail->next;
        } else {
        	node *tmp = head;
			while (tmp->next != NULL) {
				if (tmp->next->expo < exp) {
					new->next = tmp->next;
					tmp->next = new;
					break;
				}
				tmp = tmp->next;
			}
        }
    }
    return head;
}

void insert(node **head, node **tail, node **new) {
    if (*head == NULL && *tail == NULL) {
        *head = *tail = *new;
    } else {
        (*tail)->next = *new;
        *tail = (*tail)->next;
    }
}

void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d^%d ", temp->coeff, temp->expo);
		if (temp->next != NULL) {
			printf("+ ");
		}
        temp = temp->next;
    }
	printf("\n");
}
