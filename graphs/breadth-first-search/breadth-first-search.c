#include <stdio.h>

#define MAX 8

int vertexcount = 0, front = -1, rear = -1;
int adjmatrix[MAX][MAX], visited[MAX], queue[MAX];

int dequeue();
void enqueue(int);
void initialize();
void display();
void bfs(int);

int main() {
	int query;
    while (vertexcount == 0) {
        printf("enter number of vertices: ");
        scanf("%d", &vertexcount);
		if (vertexcount < MAX) {
			break;
		} else {
			printf("size should be greater than %d, try again\n", MAX);
		}
    }
    initialize();
	printf("adjacency matrix: \n");
	display();

	printf("enter vertex to start bfs: ");
	scanf("%d", &query);
    bfs(query);
}


void bfs(int query) {
	int vertex;
	visited[query] = 1;
	enqueue(query);
	while (front != -1) {
		vertex = dequeue();
		printf("v%d ", vertex);
		for (int i = 0; i < vertexcount; i++) {
			if (adjmatrix[vertex][i] == 1 && visited[i] != 1) {
				visited[i] = 1;
				enqueue(i);
			}
		}
	}
}

void enqueue(int item) {
	if (front == 0 && rear == MAX-1) {
		printf("queue full\n");
	} else if (front == -1 && rear == -1) {
		front = rear = 0;
	} else {
		rear++;
	}
	queue[rear] = item;
}

int dequeue() {
	int item;
	if (front == -1 && rear == -1) {
		printf("queue empty\n");
		return -1;
	} else if (front == rear) {
		item = queue[front];
		front = rear = -1;
	} else {
		item = queue[front];
		front++;
	}
	return item;
}

void initialize() {
    int opt;
    for (int i = 0; i < vertexcount; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertexcount; j++) {
            if (i == j) {
                continue;
            }
            printf("is vertex %d connected to %d? (1/0): ", i, j);
            scanf("%d", &opt);
            if (opt == 1) {
                adjmatrix[i][j] = 1;
            } else {
                adjmatrix[i][j] = 0;
            }
        }
    }
}

void display() {
	for (int i = 0; i < vertexcount; i++) {
		for (int j = 0; j < vertexcount; j++) {
			printf("%d  ", adjmatrix[i][j]);
		}
		printf("\n");
	}
}

