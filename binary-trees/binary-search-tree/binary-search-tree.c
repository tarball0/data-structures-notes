#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

node *root = NULL, *search_parent = NULL;

void insert(node **, int);
void delete(int);
node *inordersuccessor(node *);
node *search(node **, node **, int);
node *createnode(int);
void display_inorder(node *);

int main() {
    int opt, item, loop = 1;
    node *ret = NULL;
    printf("MENU\n1. insert\n2. search\n3. delete\n4. exit\n");
    while (loop) {
        printf("option: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("enter item to insert: ");
            scanf("%d", &item);
            insert(&root, item);
            display_inorder(root);
            printf("\n");
            break;

        case 2:
            printf("enter item to search: ");
            scanf("%d", &item);
            ret = search(NULL, &root, item);
            if (ret != NULL) {
                printf("found!\n");
            } else {
                printf("not found\n");
            }
			break;

		case 3:
			printf("enter element to delete: ");
			scanf("%d", &item);
			delete(item);
			display_inorder(root);
			printf("\n");
			break;

        case 4:
            loop = 0;
            break;
        }
    }
}

node *createnode(int data) {
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

void insert(node **ptr, int item) {
    if (*ptr == NULL) {
        node *new = createnode(item);
        *ptr = new;
    } else if (item > (*ptr)->data) {
        insert(&(*ptr)->right, item);
    } else if (item < (*ptr)->data) {
        insert(&(*ptr)->left, item);
    } else if (item == (*ptr)->data) {
		printf("item exists\n");
    }

}

node *search(node **parent, node **ptr, int query) {
    if (*ptr == NULL) {
        return NULL;
    }
    if ((*ptr)->data == query) {
		if (parent == NULL) {
			search_parent = NULL;
			return *ptr;
		} else {
			search_parent = *parent;
			return *ptr;
		}
    } else if (query < (*ptr)->data) {
        return search(ptr, &(*ptr)->left, query);
    } else {
        return search(ptr, &(*ptr)->right, query);
    }
}

void delete(int item) {
    node *ptr = search(NULL, &root, item);

    if (ptr == NULL) {
        printf("not found\n");
    } else if (ptr == root){
		if (ptr->left == NULL && ptr->right == NULL)  {
			free(ptr);
			root = NULL;
		} else if (ptr->left != NULL && ptr->right == NULL) {
			root = ptr->left;
			free(ptr);
		} else if (ptr->right != NULL && ptr->left == NULL) {
			root = ptr->right;
			free(ptr);
		}

    } else if (ptr->left == NULL && ptr->right == NULL) {
        if (search_parent->left == ptr) {
            search_parent->left = NULL;
        } else if (search_parent->right == ptr) {
            search_parent->right = NULL;
        }
        free(ptr);
    } else if (ptr->left != NULL && ptr->right == NULL) {
        if (search_parent->left == ptr) {
            search_parent->left = ptr->left;
        } else if (search_parent->right == ptr) {
            search_parent->right = ptr->left;
        }
        free(ptr);
    } else if (ptr->left == NULL && ptr->right != NULL) {
        if (search_parent->left == ptr) {
            search_parent->left = ptr->right;
        } else if (search_parent->right == ptr) {
            search_parent->right = ptr->right;
        }
        free(ptr);
    } else {
        node *successor = inordersuccessor(ptr);
		printf("inorder successor: %d\n", successor->data);
		int x = successor->data;
		delete(successor->data);
		ptr->data = x;
    }

}

node *inordersuccessor(node *ptr) {
    ptr = ptr->right;
    while (ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr;
}

void display_inorder(node *ptr) {
    if (ptr == NULL) {
        return;
    }
    display_inorder(ptr->left);
    printf("%d ", ptr->data);
    display_inorder(ptr->right);
}
