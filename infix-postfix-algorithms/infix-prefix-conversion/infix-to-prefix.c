#include <ctype.h>
#include <stdio.h>
#include <string.h>

char queue[32], stack[32];
int top = -1, front = -1, rear = -1;

void revstring(char[], int);
void convert(char[]);
void push(char);
void enqueue(char);
char pop();
int isoperator(char);
int precedenceof(char);

int main() {
    char input[32];
    printf("enter infix expression: ");
    fgets(input, 32, stdin);
	input[strlen(input) -1] = '\0';
    int len = strlen(input);
    revstring(input, len);
    convert(input);
	len = strlen(queue);
	revstring(queue, len);
	printf("%s", queue);
    return 0;
}

void convert(char input[]) {
	int i = 0;
	char c;
	while (input[i] != '\0') {
		c = input[i];
		if (c == ' ') {
			i++;
			continue;
		} else if (isalnum(c)) {
			enqueue(c);
		} else if (c == ')') {
			push(c);
		} else if (c == '(') {
			while (stack[top] != ')') {
				enqueue(pop());
			}
			pop();
		} else if (isoperator(c)) {
			if (stack[top] == ')' || top == -1) {
				push(c);
			} else {
				while (precedenceof(stack[top] > precedenceof(c))) {
					enqueue(pop());

					if (stack[top] == ')' || top == -1) {
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

void revstring(char input[], int len) {
    char tmp;
    for (int i = 0; i < len / 2; i++) {
        tmp = input[i];
        input[i] = input[len - 1 - i];
        input[len - 1 - i] = tmp;
    }
}

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

void enqueue(char c) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = c;
}

int isoperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
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
