#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial node
struct node {
    int coeff;         // Coefficient of the term
    int expo;          // Exponent of the term
    struct node *link; // Pointer to the next term
};

// Function to create a new polynomial node
struct node *createNode(int coeff, int expo) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->link = NULL;
    return newNode;
}

// Function to insert a term into the polynomial linked list
struct node *insert(struct node *head, int coeff, int expo) {
    struct node *newNode = createNode(coeff, expo);
    if (head == NULL) {
        return newNode;
    }

    // Insert in sorted order based on exponent
    if (expo > head->expo) {
        newNode->link = head;
        return newNode;
    }

    struct node *current = head;
    while (current->link != NULL && current->link->expo > expo) {

        current = current->link;
    }
    newNode->link = current->link;
    current->link = newNode;
    return head;
}

// Function to print the polynomial linked list
void printPolynomial(struct node *head) {
    while (head != NULL) {
        printf("%dx^%d ", head->coeff, head->expo);
        head = head->link;
        if (head != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

// Function to read a polynomial from user input
struct node *readPolynomial() {
    struct node *head = NULL;
    int numTerms, coeff, expo;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &numTerms);

    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

// Function to add two polynomials
struct node *addPolynomials(struct node *head1, struct node *head2) {
    struct node *head3 = NULL; // Resultant polynomial

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    while (ptr1 != NULL || ptr2 != NULL) {
        if (ptr1 == NULL) {
            // If all terms from the first polynomial are added, take terms from
            // the second polynomial
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        } else if (ptr2 == NULL) {
            // If all terms from the second polynomial are added, take terms
            // from the first polynomial
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;

        } else if (ptr1->expo == ptr2->expo) {
            // If the exponents are equal, add the coefficients
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        } else if (ptr1->expo > ptr2->expo) {
            // If the exponent of the first polynomial is greater, take it
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        } else {
            // If the exponent of the second polynomial is greater, take it
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    return head3;
}

// Function to multiply two polynomials
struct node *multiplyPolynomials(struct node *head1, struct node *head2) {
    struct node *head3 = NULL; // Resultant polynomial

    struct node *ptr1 = head1;
    while (ptr1 != NULL) {
        struct node *ptr2 = head2;
        while (ptr2 != NULL) {

            int res1 = ptr1->coeff * ptr2->coeff; // Multiply coefficients
            int res2 = ptr1->expo + ptr2->expo;   // Add exponents
            head3 = insert(head3, res1, res2);    // Insert result into head3
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
    return head3;
}

// Example usage
int main() {
    struct node *poly1 = NULL; // First polynomial
    struct node *poly2 = NULL; // Second polynomial

    printf("Enter the first polynomial:\n");
    poly1 = readPolynomial();

    printf("Enter the second polynomial:\n");
    poly2 = readPolynomial();

    printf("First polynomial: ");
    printPolynomial(poly1);

    printf("Second polynomial: ");
    printPolynomial(poly2);

    // Add the two polynomials
    struct node *sum = addPolynomials(poly1, poly2);
    printf("Result of polynomial addition: ");
    printPolynomial(sum);

    // Multiply the two polynomials
    struct node *result = multiplyPolynomials(poly1, poly2);
    printf("Result of polynomial multiplication: ");
    printPolynomial(result);

    return 0;
}
