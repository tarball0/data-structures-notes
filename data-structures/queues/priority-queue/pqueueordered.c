#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct qelements{
    int data;
    int priority;
}data;

data pq[MAX];
int front = -1, rear = -1;
int size = 0;

void enqueue(){

    if(rear == MAX - 1){
        printf("Queue is full\n");
        return;
    }
    
    if (rear == -1)
    {
        front = rear = 0;
    }

    else{

        rear++;

    }

    printf("Enter the data: ");
    scanf("%d", &pq[rear].data);
    printf("Enter the priority: ");
    scanf("%d", &pq[rear].priority);

    for (int i = rear; i > front; i--) {
        if (pq[i].priority < pq[i-1].priority) {
            data temp = pq[i];
            pq[i] = pq[i-1];
            pq[i-1] = temp;
        } else {

            break;
        }
    }
    return;
}

void dequeue(){

    if (front == -1){

        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted element is %d\n", pq[front].data);

    if (front == rear){

        front = rear = -1;
    }

    else{

        front++;
    }
}

void display(){

    if (front == -1){

        printf("Queue is Empty\n");
        return;
    }

    else{

        if (front == rear){

            printf("Element: ");
            printf("%d ", pq[front].data);
            printf("\nPriority: ");
            printf("%d ", pq[front].priority);
        }

        else{

            printf("Element: ");
            for (int i = front; i <= rear; i++)
            {
                    printf("%d ", pq[i].data);
            }
            printf("\nPriority: ");
            for (int i = front; i <= rear; i++)
            {
                    printf("%d ", pq[i].priority);
       
            }
        }

    printf("\n");
    }
}

int main()
{

    printf("\n### MENU ###\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    int choice = 0;

    do
    {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);  

         switch (choice)
         {

         case 1:
            enqueue();
            break;

         case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

         default:
            printf("Invalid choice\n");
            break;
         }  
    } while (choice != 4);
    

    return 0;
}
