/* credit: George */

#include <ctype.h>
#include <stdio.h>

int S[50], top = -1;

void PUSH(int item) {
    if (top != 49)
        S[++top] = item;
}

int POP() { return S[top--]; }

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int operate(int a, char c, int b) {
    switch (c) {
    case '+':
        return (a + b);
        break;
    case '-':
        return (a - b);
        break;
    case '*':
        return (a * b);
        break;
    case '/':
        return (a / b);
        break;
    }
    return 0;
}

int evaluate(char A[]) {
    int i = 0, op1, op2, in = 0;
    char ch;
    while (A[i] != '\0') {
        ch = A[i];
        if (isdigit(ch)) {
            in = in * 10 + (A[i] - '0');
            if (A[i + 1] == ' ') {
                PUSH(in);
                in = 0;
            }

        } else if (isOperator(ch)) {
            op2 = POP();
            op1 = POP();
            PUSH(operate(op1, ch, op2));
        }
        i++;
    }
    return POP();
}

int main() {
    char A[50];
    printf("Enter Postfix Expression\n");
    fgets(A, 50, stdin);
    printf("%d", evaluate(A));
    return 0;
}
