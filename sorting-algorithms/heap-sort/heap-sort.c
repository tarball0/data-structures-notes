#include <stdio.h>

#define MAX 8

void sort(int[], int);
void heapify(int[], int, int);
int read(int[], int);
int display(int[], int);

int main() {
    int n, array[MAX];
    printf("enter number of items (< %d): ", MAX);
    scanf("%d", &n);
    read(array, n);
    sort(array, n);
    display(array, n);
    return 0;
}

void sort(int array[MAX], int n) {
	int temp;
	for (int i = (n/2)-1; i >= 0; i--) {
		heapify(array, n, i);
	}
	for (int i = n-1; i >= 0; i--) {
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		heapify(array, i, 0);
	}
}

void heapify(int array[MAX], int n, int root) {
	int temp;
	int left = (root*2)+1;
	int right = (root*2)+2;
	int max = root;

	if (left < n && array[left] > array[max]) {
		max = left;
	}

	if (right < n && array[right] > array[max]) {
		max = right;
	}

	if (max != root) {
		temp = array[max];
		array[max] = array[root];
		array[root] = temp;
		heapify(array, n, max);
	}
}


int read(int array[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("enter item no. %d: ", i);
        scanf("%d", &array[i]);
    }
    return 0;
}

int display(int array[MAX], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]");
    return 0;
}

