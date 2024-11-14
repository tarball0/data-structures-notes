#include <stdio.h>

#define MAX 16

int tree[MAX];
int query, search_location = 0;

void build(int);
void display();
void search(int);
void insert(int);
void delete();

int main() {
	int input;
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }

	build(1);
	display();
	printf("enter item to search for: ");
	scanf("%d", &query);
	search(1);
	if (search_location != 0) {
		printf("found at location %d\n", search_location);
		printf("enter element to insert: ");
		scanf("%d", &input);
		insert(input);
	} else {
		printf("not found\n");
	}
	display();
	delete();
	display();
}

void build(int root) {
    if (root > MAX) {
        printf("limit reached\n");
        return;
    }
    printf("enter value: ");
    scanf("%d", &tree[root]);
    int opt;
    printf("enter 1 to create left child for %d or 0 otherwise: ", tree[root]);
    scanf("%d", &opt);
	if (opt) {
		build(root*2);
	}

    printf("enter 1 to create right child for %d or 0 otherwise: ", tree[root]);
    scanf("%d", &opt);
	if (opt) {
		build(root*2 + 1);
	}
}

void search(int loc) {
	if (loc <= MAX) {
		if (tree[loc] == query) {
			search_location = loc;
		} else {
			search(loc*2);
			search((loc*2)+1);
		}
	}
}

void insert(int input) {
	int opt;
	printf("insert %d as child of %d? (1=R, 0=L): ", input, query);
	scanf("%d", &opt);
	if (opt == 0) {
		if (tree[search_location*2] == -1) {
			tree[search_location*2] = input;
		} else {
			printf("left child exists\n");
		}
	} else if (opt == 1) {
		if (tree[search_location*2 + 1] == -1) {
			tree[search_location*2 + 1] = input;
		} else {
			printf("right child exists\n");
		}
	}
	
}

void delete(){
	printf("enter item to delete: ");
	scanf("%d", &query);
	search(1);
	if (search_location != 0) {
		if (tree[search_location*2] != -1 || tree[search_location*2+1] != -1) {
			printf("not a leaf node\n");
			return;
		}
		tree[search_location] = -1;
		printf("deleted\n");
	} else {
		printf("not found\n");
	}
}

void display() {
    for (int i = 0; i < MAX; i++) {
		if (tree[i] != -1) {
			printf("%d", tree[i]);
		} else {
			printf("_");
		}
	}
	printf("\n");
}
