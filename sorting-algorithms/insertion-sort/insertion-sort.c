#include <stdio.h>

#define MAX 8

int sort(int[], int);
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

int sort(int array[MAX], int n) {
		int current, j;
	for (int i = 1; i < n; i++) {
		current = array[i];
		j = i - 1;

		while (j > -1 && current < array[j]) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = current;
	}
	return 0;
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
		if (i != n-1) {
			printf(", ");
		}
	}
	printf("]");
	return 0;
}
