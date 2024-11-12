#include <stdio.h>

#define MAX 8

int vertexcount = 0, top = -1;
int adjmatrix[MAX][MAX], visited[MAX], stack[MAX];

int pop();
void push(int);
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

	printf("enter vertex to start dfs: ");
	scanf("%d", &query);
    bfs(query);
}


void bfs(int query) {
	int vertex;
	visited[query] = 1;
	push(query);
	while (top != -1) {
		vertex = pop();
		printf("v%d ", vertex);
		for (int i = 0; i < vertexcount; i++) {
			if (adjmatrix[vertex][i] == 1 && visited[i] != 1) {
				visited[i] = 1;
				push(i);
			}
		}
	}
}

void push(int item) {
	if (top == MAX-1) {
		printf("stack full\n");
	} else {
		stack[++top] = item;
	}
}

int pop() {
	int item;
	if (top == -1) {
		printf("stack empty\n");
		return -1;
	} else {
		return stack[top--];
	}
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

