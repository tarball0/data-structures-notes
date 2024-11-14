#include <stdio.h>
#include <stdlib.h>

#define MAX 16

struct node {
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;


int tree[MAX];
int query; 
node *search_location = NULL, *search_location_parent = NULL;


node *createnode();
void build(node *);
void display_inorder(node *);
void search(node *, node *);
void insert(int);
void delete();

int main() {
	int input;
	node *root = createnode();

	build(root);
	display_inorder(root);
	printf("\n");
	printf("enter item to search for: ");
	scanf("%d", &query);
	search(NULL, root);
	if (search_location != NULL) {
		printf("found\n");
		printf("enter element to insert: ");
		scanf("%d", &input);
		insert(input);
	} else {
		printf("not found\n");
	}

	display_inorder(root);
	printf("enter item to delete: ");
	scanf("%d", &query);
	search(NULL, root);
	delete();
	display_inorder(root);
}

void build(node *root) {
    printf("enter value: ");
    scanf("%d", &root->data);
    int opt;
    printf("enter 1 to create left child for %d or 0 otherwise: ", root->data);
    scanf("%d", &opt);
	if (opt) {
		node *child = createnode();
		root->left = child;
		build(root->left);
	}

    printf("enter 1 to create right child for %d or 0 otherwise: ", root->data);
    scanf("%d", &opt);
	if (opt) {
		node *child = createnode();
		root->right = child;
		build(root->right);
	}
}

void search(node *parent, node *ptr) {
	if (ptr != NULL) {
		if (ptr->data == query) {
			search_location = ptr;
			search_location_parent = parent;
		} else {
			search(ptr, ptr->left);
			search(ptr, ptr->right);
		}
	
	}
}

void insert(int input) {
	int opt;
	printf("insert %d as child of %d? (1=R, 0=L): ", input, query);
	scanf("%d", &opt);
	if (opt == 0) {
		if (search_location->left == NULL) {
			node *new = createnode();
			new->data = input;
			search_location->left = new;
		} else {
			printf("left child exists\n");
		}
	} else if (opt == 1) {
		if (search_location->right == NULL) {
			node *new = createnode();
			new->data = input;
			search_location->right = new;
		} else {
			printf("right child exists\n");
		}
	}
	search_location = NULL;
	
}

void delete(){
	if (search_location != NULL) {
		if (search_location->right != NULL || search_location->left != NULL) {
			printf("not a leaf node\n");
			return;
		}
		if (search_location_parent->left == search_location) {
			search_location_parent->left = NULL;
		} else if (search_location_parent->right == search_location) {
			search_location_parent->right = NULL;
		}
		free(search_location);
		printf("deleted\n");
	} else {
		printf("not found\n");
	}
}

node *createnode() {
	node *new = (node *)malloc(sizeof(node));
	new->left = new->right = NULL;
	return new;
}

void display_inorder(node *root) {
	if (root != NULL) {
		display_inorder(root->left);
		printf("%d ", root->data);
		display_inorder(root->right);
	}
}
