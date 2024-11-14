#include <stdio.h>

int main() {
    int arr[16], n, temp;

    printf("number of elements in array: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("sorted array: {");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf("}\n");
    return 0;
}
