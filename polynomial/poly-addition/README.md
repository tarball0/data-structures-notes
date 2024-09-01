# Polynomial Addition using arrays

* Create struct with coefficient and exponent
* declare functions to accept display and add the polynomial

```c
int accept(polynomial[]);
void display(polynomial[], int);
int add(polynomial[], int, polynomial[], int, polynomial[]);
```

* create 3 seperate struct arrays
* accept first 2 struct arrays using the accept function

```c
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
```

## Adding
* there are three main conditions to be evaluated `(while n1 < t1 && n2 < t2)`
1. if the exponents are equal
2. if the exponent of the first if greater
3. if the exponent of the second is greater

* once the first while loop breaks, iterate through the remaining elements in the larger polynomial

## Display
* display from index 0 to number of terms in sum
