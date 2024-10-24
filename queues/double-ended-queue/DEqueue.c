#include <stdio.h>

#define SIZE 8

void inject(int);
void eject();
void push(int);
void pop();
void display();

int queue[SIZE], front = -1, rear = -1;

int main() {
    int item, opt, exit = 0;

    while (exit != 1) {
        printf("enter option:\n1: push\n2: pop\n3: inject\n4: eject\n5: "
               "exit\noption: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
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
            printf("enter element: ");
            scanf("%d", &item);
            inject(item);
            display();
            break;

        case 4:
            eject();
            display();
            break;

        case 5:
            exit = 1;
            break;

        default:
            printf("error :(\n");
            break;
        }
    }
    return 0;
}

void push(int item) {
    if (front == 0 && rear == SIZE - 1)
        printf("DQ is full\n");

    else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[front] = item;
    }

    else if (front > 0) {
        front--;
        queue[front] = item;
    }

    else {
        for (int i = rear; i >= 0; i--) {
            queue[i + 1] = queue[i];
        }
        queue[front] = item;
        rear++;
    }
}

void inject(int item) {
    if (front == 0 && rear == SIZE - 1)
        printf("DQ is full\n");

    else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = item;
    }

    else if (rear < SIZE - 1) {
        rear++;
        queue[rear] = item;
    }

    else {
        for (int i = front; i <= rear; i++) {
            queue[i - 1] = queue[i];
        }
        queue[rear] = item;
        front--;
    }
}

void pop() {
    if (front == -1 && rear == -1) {
        printf("queue is empty\n");
    }

    else if (front == rear) {
        front = -1;
        rear = -1;
    }

    else {
        front++;
    }
}

void eject() {
    if (front == -1 && rear == -1) {
        printf("queue is empty\n");
    }

    else if (front == rear) {
        front = -1;
        rear = -1;
    }

    else {
        rear--;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("queue is empty\n");
    }

    else {
        printf("[");
        for (int i = front; i <= rear; i++) {
            printf("%d", queue[i]);
            if (i != rear)
                printf(", ");
        }
        printf("]\n");
    }
}
