#include <stdio.h>

int main() {
	int arr[32];
	int query, found, n, pos;
	printf("enter array length: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("enter array value %d: ", i);
		scanf("%d", &arr[i]);
	}
	printf("enter search element: ");
	scanf("%d", &query);

	for (int i = 0; i < n; i++) {
		if (arr[i] == query){
			found = 1;
			pos = i;
			break;
		}
	}

	if (found) printf("found at position %d\n", pos);
	else printf("not found\n");

	return 0;
}


