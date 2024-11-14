#include <stdio.h>

#define MAX 8

void sort(int[], int, int);
int read(int[], int);
int display(int[], int);

int main() {
    int n, array[MAX];
    printf("enter number of items (< %d): ", MAX);
    scanf("%d", &n);
    read(array, n);
    sort(array, 0, n - 1);
    display(array, n);
    return 0;
}


void sort(int array[MAX], int start, int end) {
    if (end <= start)
        return;

    int temp;
    int pivot = array[end];
    int j = start;
    int i = start - 1;
    while (j < end) {
        if (array[j] < array[end]) {
            i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
        }
		j++;
    }
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	sort(array, start, i);
	sort(array, i+2, end);
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
