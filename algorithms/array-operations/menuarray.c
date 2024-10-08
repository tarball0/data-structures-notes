#include "stdio.h"

void display_array(int arr[64], int n);

int main (){
	int arr[64];
	int element, position, opt, n, forever = 1;
	printf("------INPUT ARRAY------\n\n");
	printf("enter number of elements (limit: 32): ");
	scanf("%d", &n);
	
	if (n < 32){
		for (int i = 0; i < n; i++){
			printf("enter element %d: ", i);
			scanf("%d", &arr[i]);
		}
	}
	else printf("too large! limit: 32\n");
	
	printf("------MENU-----\n\n");
	printf("1. insert at start\n2. insert at end\n3. insert at position\n");
	printf("4. delete from start\n5. delete from end\n6. delete from position\n7. delete element\n8. display array\n9. exit");
	
	while(forever){
		printf("\nenter option: ");
		scanf("%d", &opt);
	
		switch(opt){
			case 1:
				printf("enter element to insert: ");
				scanf("%d", &element);
				for (int i = n-1; i >= 0; i--){
					arr[i+1] = arr[i];
				}
				arr[0] = element;
				n++;	
				break;
				
			case 2:
				printf("enter element to insert: ");
				scanf("%d", &element);
				arr[n] = element;
				n++;
				break;
				
			case 3:
				printf("enter element to insert: ");
				scanf("%d", &element);
				printf("enter position: ");
				scanf("%d", &position);
				for (int i = n-1; i >= position; i--){
					arr[i+1] = arr[i];
				}
				arr[position] = element;
				n++;
				break;
				
			case 4:
				for (int i = 0; i < n - 1; i++){
					arr[i] = arr[i+1];
				}
				n--;
				printf("deleted!\n");
				break;
				
			case 5:
				n--;
				printf("deleted!\n");
				break;
				
			case 6:	
				printf("enter position to delete: ");
				scanf("%d", &position);
				for (int i = position; i < n - 1; i++){
					arr[i] = arr[i+1];
				}
				n--;
				printf("deleted!\n");
				break;
			
			case 7:
				printf("enter element to delete: ");
				scanf("%d", &element);
				
				for(int i = 0; i < n; i++){
					if (arr[i] == element){
						position = i;
					}
				}
					
					
				for (int i = position; i < n - 1; i++){
					arr[i] = arr[i+1];
				}
				
				n--;
				printf("deleted!\n");
				break;
				
				
			case 8:
				printf("\n");
				for (int i = 0; i < n; i++){
					printf("%d ", arr[i]);
				}
				printf("\n");
				break;
				
			case 9:
				forever = 0;
				break;
				
			default:
				printf("invalid option\n");
				break;
			
				
				
		}
	}
	return 0;
}


