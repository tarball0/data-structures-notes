/* credit: George */

#include <ctype.h>
#include <stdio.h>
// int n = 50;
char S[50], Q[50];
int top = -1, f = -1, r = -1;

void enq(char x) {
  if (f == -1) {
    f = 0;
    r = 0;
    Q[r] = x;
  }

  else {
    r++;
    Q[r] = x;
  }
}

void display(char Q[]) {
  int i;
  if (f == -1) {
    printf("EMPTY!\n");
  } else {
    for (i = f; i <= r; i++) {
      printf(" %c ", Q[i]);
    }
    printf("\n");
  }
}

void push(char x) {
  if (top != 49) {
    top++;
    S[top] = x;
  }
}
int pop() { return (S[top--]); }

int isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int prec(char c) {
  if (c == '+' || c == '-') {
    return 1;
  } else if (c == '*' || c == '/') {
    return 2;
  } else if (c == '^') {
    return 3;
  } else
    return -1;
}

void convert(char A[]) {
  int i = 0;
  char ch;
  while (A[i] != '\0') {
    ch = A[i];
    if (isalnum(ch)) {
      enq(ch);
    } else if (ch == '(') {
      push(ch);
    } else if (ch == ')') {
      while (S[top] != '(') {
        enq(pop());
      }
      pop();
    } else if (isOperator(ch)) {
      if (S[top] == '(' || top == -1) {
        push(ch);
      } else {
        while (prec(S[top] >= prec(ch))) {
          enq(pop());
          if (S[top] == '(' || top == -1) {
            break;
          }
        }
        push(ch);
      }
    }
    i++;
  }
  while (top != -1) {
    enq(pop());
  }
}

int main() {
  char A[50];
  printf("Enter expression: ");
  scanf("%s", A);
  convert(A);
  display(Q);
  return 0;
}
