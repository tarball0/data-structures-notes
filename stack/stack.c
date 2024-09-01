#include <stdio.h>

#define SIZE 8

int push(int);
int pop();
void display();

int stack[SIZE] = {0}, top = -1;

int main() {
    int item, opt, exit = 0;

    while (exit != 1) {
        printf("enter option:\n1: push\n2: pop\n3: exit\noption: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            if (top == SIZE - 1) {
                printf("stack full\n");
                break;
            }

            printf("enter element: ");
            scanf("%d", &item);
            push(item);
            display();
            break;

        case 2:
            pop();
            display();
            break;

        case 3:
            exit = 1;
            break;

        default:
            printf("error :(\n");
            break;
        }
    }
}

int push(int element) {
    if (top != SIZE - 1) {
        top++;
        stack[top] = element;
        return 0;
    }
    return 1;
}

int pop() {
    if (top != -1) {
        top--;
        return 0;
    } else
        return 1;
}

void display() {
    if (top == -1)
        printf("stack empty\n");

    else {
        printf("[");
        for (int i = 0; i <= top; i++) {
            printf("%d", stack[i]);
            if (i != top) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}
