# Polynomial Linked List Operations

This program performs various operations on polynomials represented as linked lists. It includes functionalities to create, add, and multiply polynomials. The program is written in C and demonstrates the use of linked lists to manage polynomial terms.

## Features

- **Create Polynomial**: Read polynomial terms from user input and create a linked list representation.
- **Print Polynomial**: Display the polynomial in a human-readable format.
- **Add Polynomials**: Add two polynomials and return the resultant polynomial.
- **Multiply Polynomials**: Multiply two polynomials and return the resultant polynomial.

## File Structure

```
poly_ll.c
```

## Functions

- `struct node* createNode(int coeff, int expo)`: Creates a new polynomial node.
- `struct node* insert(struct node* head, int coeff, int expo)`: Inserts a term into the polynomial linked list in sorted order.
- `void printPolynomial(struct node* head)`: Prints the polynomial linked list.
- `struct node* readPolynomial()`: Reads a polynomial from user input.
- `struct node* addPolynomials(struct node* head1, struct node* head2)`: Adds two polynomials.
- `struct node* multiplyPolynomials(struct node* head1, struct node* head2)`: Multiplies two polynomials.

## Usage

1. **Compile the Program**:
    ```sh
    gcc poly_ll.c -o poly_ll
    ```

2. **Run the Program**:
    ```sh
    ./poly_ll
    ```

3. **Follow the Prompts**:
    - Enter the number of terms for each polynomial.
    - Enter the coefficient and exponent for each term.
    - The program will display the entered polynomials, their sum, and their product.

## Example

```
Enter the first polynomial:
Enter the number of terms in the polynomial: 2
Enter coefficient and exponent for term 1: 3 2
Enter coefficient and exponent for term 2: 5 1
Enter the second polynomial:
Enter the number of terms in the polynomial: 2
Enter coefficient and exponent for term 1: 4 1
Enter coefficient and exponent for term 2: 2 0
First polynomial: 3x^2 + 5x^1 
Second polynomial: 4x^1 + 2x^0 
Result of polynomial addition: 3x^2 + 9x^1 + 2x^0 
Result of polynomial multiplication: 12x^3 + 26x^2 + 10x^1 
```

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

