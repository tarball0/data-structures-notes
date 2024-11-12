/* This program uses the unordered array method
 * which means that insertion is done as usual
 * but deletion is done according to priority
 */

#include <stdio.h>

#define SIZE 8

typedef struct {
    int val;
    int pri;
} priqueue;

priqueue queue[SIZE];
int front = -1, rear = -1;

void enqueue(int, int);
void dequeue();
void display();
int highpri();

int main() {
    int opt, value, priority, loop = 1;
    printf("MENU\n1. enqueue\n2. dequeue\n3. exit\n ");
    while (loop) {
        printf("option: ");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            printf("enter value: ");
            scanf("%d", &value);
            printf("enter priority: ");
            scanf("%d", &priority);
            enqueue(value, priority);
            display();
            break;

        case 2:
            dequeue();
            display();
            break;

        case 3:
            loop = 0;
            break;
        }
    }
}

void enqueue(int item, int priority) {
    if (front == 0 && rear == SIZE - 1) {
        printf("queue is full\n");
    }

    else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear].val = item;
        queue[rear].pri = priority;
    }

    else if (rear == SIZE - 1) {
        for (int i = front; i <= rear; i++) {
            queue[i - 1].val = queue[i].val;
            queue[i - 1].pri = queue[i].pri;
        }
        front--;

        queue[rear].val = item;
        queue[rear].pri = priority;
    }

    else {
        rear++;
        queue[rear].val = item;
        queue[rear].pri = priority;
    }
}

void dequeue() {
    if (rear == -1 && front == -1) {
        printf("queue is empty\n");
    }

    else if (rear == front) {
        front = -1;
        rear = -1;
    }

    else {
        int hipri = highpri();
        printf("dequeued %d\n", queue[hipri].val);
        for (int i = hipri; i <= rear; i++) {
            queue[i].val = queue[i + 1].val;
            queue[i].pri = queue[i + 1].pri;
        }
        rear--;
    }
}

int highpri() {
    int high = 0, index = -1;
    for (int i = front; i <= rear; i++) {
        if (queue[i].pri >= high) {
            high = queue[i].pri;
            index = i;
        }
    }
    return index;
}

void display() {
    if (rear == -1 && front == -1) {
        printf("empty queue\n");
    }

    else {
        printf("[");
        for (int i = front; i <= rear; i++) {
            printf("(%d,%d)", queue[i].val, queue[i].pri);
            if (i != rear) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}
