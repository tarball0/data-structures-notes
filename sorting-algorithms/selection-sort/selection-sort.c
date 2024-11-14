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
	for (int i = 0; i < n-1; i++) {
		int min = i, temp;
		for (int j = i+1; j < n; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
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
