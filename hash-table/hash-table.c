#include <stdio.h>

void insert(int[], int, int);
void display(int[], int);

int main() {
	int tablesize, itemcount, item;
	printf("enter size of hash table: " );
	scanf("%d", &tablesize);
	int hashtable[tablesize];
	for (int i = 0; i < tablesize; i++) {
		hashtable[i] = -1;
	}
	
	printf("enter number of items: " );
	scanf("%d", &itemcount);

	printf("\n");
	for (int i = 0; i < itemcount; i++) {
		printf("enter item no %d: ", i);
		scanf("%d", &item);
		insert(hashtable, item, tablesize);
	}

	printf("\n");
	display(hashtable, tablesize);
}

void insert(int hashtable[], int item, int tablesize) {
	int start_index = item%tablesize;
	int index = start_index;
	while (hashtable[index] != -1) {
		index = (index+1)%tablesize;
		if (index == start_index) {
			printf("table is full\n");
			return;
		}
	}
	hashtable[index] = item;
}

void display(int hashtable[], int tablesize) {
	for (int i = 0; i < tablesize; i++) {
		printf("index %d: ", i);
		if (hashtable[i] == -1) {
			printf("empty\n");
		} else {
			printf("%d\n", hashtable[i]);
		}
	}
}
