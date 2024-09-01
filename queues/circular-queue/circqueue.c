#include <stdio.h>

#define SIZE 8

int queue[SIZE];
int top = -1, bot = -1;

void enqueue(int);
void dequeue();
void display();

int main() {

    int item, opt, exit = 0;

    while (exit != 1) {
        printf("enter option:\n1: enqueue\n2: dequeue\n3: exit\noption: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("enter element: ");
            scanf("%d", &item);
            enqueue(item);
            display();
            break;

        case 2:
            dequeue();
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
    return 0;
}

void enqueue(int value) {
    if (top == (bot + 1) % SIZE) {
        printf("full queue\n");
    }

    else if (top == -1 && bot == -1) {
        bot = 0;
        top = 0;
        queue[bot] = value;
    }

    else {
        bot = (bot + 1) % SIZE;
        queue[bot] = value;
    }
}

void dequeue() {
    if (top == -1 && bot == -1) {
        printf("empty queue\n");
    } else if (top == bot) {
        top = -1;
        bot = -1;
    } else
        top = (top + 1) % SIZE;
}

void display() {
    if (top == -1 && bot == -1){
        printf("empty queue\n");
		return;
	}
    printf("[");
    if (top <= bot) {
        for (int i = top; i <= bot; i++) {
            printf("%d", queue[i]);
            if (i != bot) {
                printf(", ");
            }
        }
    }

    else {
        for (int i = top; i < SIZE; i++) {
            printf("%d", queue[i]);
            if (i != bot) {
                printf(", ");
            }
        }
        for (int i = 0; i <= bot; i++) {
            printf("%d", queue[i]);
            if (i != bot) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}
