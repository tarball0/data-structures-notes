#include <stdio.h>
#define SIZE 8

typedef struct {
    int coeff;
    int exp;
} polynomial;

int accept(polynomial[]);
void display(polynomial[], int);
int add(polynomial[], int, polynomial[], int, polynomial[]);

int main() {
    polynomial poly1[SIZE], poly2[SIZE], sum[SIZE];
    int t1, t2, t3;
    printf("enter polynomial 1: \n");
    t1 = accept(poly1);
    printf("enter polynomial 2: \n");
    t2 = accept(poly2);

    display(poly1, t1);
    printf("+");
    display(poly2, t2);
    t3 = add(poly1, t1, poly2, t2, sum);
    display(sum, t3);
}

int accept(polynomial poly[]) {
    int terms;
    printf("enter number of terms: ");
    scanf("%d", &terms);

    for (int i = 0; i < terms; i++) {
        printf("enter coeff: ");
        scanf("%d", &poly[i].coeff);
        printf("enter exponent: ");
        scanf("%d", &poly[i].exp);
    }

    return terms;
}

void display(polynomial poly[], int terms) {
    printf("\n");
    for (int i = 0; i < terms; i++) {
        printf("%d", poly[i].coeff);
        if (poly[i].exp > 0)
            printf("x");
        if (poly[i].exp > 1)
            printf("^%d", poly[i].exp);
        if (i != terms - 1)
            printf(" + ");
    }
    printf("\n");
}

int add(polynomial p1[], int t1, polynomial p2[], int t2, polynomial sum[]) {
    int n1 = 0, n2 = 0, n3 = 0;
    while (n1 < t1 && n2 < t2) {
        if (p1[n1].exp == p2[n2].exp) {
            sum[n3].coeff = p1[n1].coeff + p2[n2].coeff;
            sum[n3].exp = p1[n1].exp;
            n1++;
            n2++;
            n3++;
        }

        else if (p1[n1].exp > p2[n2].exp) {
            sum[n3].coeff = p1[n1].coeff;
            sum[n3].exp = p1[n1].exp;
            n1++;
            n3++;
        }

        else {
            sum[n3].coeff = p2[n2].coeff;
            sum[n3].exp = p2[n2].exp;
            n2++;
            n3++;
        }
    }

    while (n1 < t1) {
        sum[n3].coeff = p1[n1].coeff;
        sum[n3].exp = p1[n1].exp;
        n1++;
        n3++;
    }

    while (n2 < t2) {
        sum[n3].coeff = p2[n2].coeff;
        sum[n3].exp = p2[n2].exp;
        n2++;
        n3++;
    }
    return n3;
}
