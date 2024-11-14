#include <stdio.h>

#define MAX 8

void sort(int[], int);
void merge(int[], int[], int[], int);
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
	if (n <= 1)
		return;

	int j = 0, leftarray[n/2], rightarray[n/2];
	for (int i = 0; i < n; i++) {
		if (i < n/2) {
			leftarray[i] = array[i];
		} else {
			rightarray[j] = array[i];
			j++;
		}
	}
	sort(leftarray, n/2);
	sort(rightarray, n/2);
	merge(leftarray, rightarray, array, n);
}

void merge(int leftarray[MAX], int rightarray[MAX], int array[MAX], int size) {
	int i = 0, l = 0, r = 0;
	int lsize = size/2;
	int rsize = size - lsize;

	while (l < lsize && r < rsize) {
		if (leftarray[l] < rightarray[r]) {
			array[i] = leftarray[l];
			i++;
			l++;
		} else {
			array[i] = rightarray[l];
			i++;
			r++;
		}
	}

	while (l < lsize) {
		array[i] = leftarray[l];
		i++;
		l++;
	}

	while (r < rsize) {
		array[i] = rightarray[r];
		i++;
		r++;
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
		if (i != n-1) {
			printf(", ");
		}
	}
	printf("]");
	return 0;
}
