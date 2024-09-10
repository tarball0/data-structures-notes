#include <stdio.h>

int main() {
	int arr[32];
	int query, n, top, mid, bot, prev = 0, new;
	printf("enter array length: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("enter array value %d: ", i);
		scanf("%d", &new);
		if (!(prev <= new)) {
			printf("entered list must be sorted\n");
			return 1;
		}
		else {
			prev = new;
			arr[i] = new;
		}
	}
	printf("enter search element: ");
	scanf("%d", &query);
	
	bot = 0;
	top = n;

	while(1){
		mid = (bot+top)/2;

		if (arr[mid] == query) {
			printf("found at %d\n", mid);
			break;
		}
		else if (arr[mid] < query) {
			bot = mid+1;
			continue;
		}
		else if (arr[mid] > query) {
			top = mid-1;
			continue;
		} 
		else return 1;
	}
	return 0;
}
