#include <ctype.h>
#include <stdio.h>

char queue[32], stack[32];
int front = -1, rear = -1;
int top = -1;

void push(char);
void enqueue(char);
char pop();
void display();
void convert(char[]);
int isoperator(char);
int precedenceof(char);

int main() {
    char input[32];
    printf("enter infix expression: ");
    fgets(input, 32, stdin);
    convert(input);
    display();
}

void enqueue(char c) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = c;
}

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

void display() {
    if (front == -1) {
        printf("empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%c", queue[i]);
    }
}

int isoperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedenceof(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return -1;
    }
}

void convert(char input[]) {
    int i = 0;
    char c;
    while (input[i] != '\0') {
        c = input[i];
		if (c == ' ') {
			i++;
			continue;
		}
        if (isalnum(c)) {
            enqueue(c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (stack[top] != '(') {
                enqueue(pop());
            }
            pop();
        } else if (isoperator(c)) {
            if (stack[top] == '(' || top == -1) {
                push(c);
            } else {
                while (precedenceof(stack[top]) >= precedenceof(c)) {
                    enqueue(pop());
                    if (stack[top] == '(' || top == -1) {
                        break;
                    }
                }
                push(c);
            }
        }
        i++;
    }

    while (top != -1) {
        enqueue(pop());
    }
}
