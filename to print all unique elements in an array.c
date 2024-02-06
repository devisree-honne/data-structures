#include <stdio.h>

int main() {
    int n,i, position, newValue;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n + 1];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to insert the new element (1 to %d): ", n + 1);
    scanf("%d", &position);
    if (position < 1 || position > n + 1) {
        printf("Invalid position. Please enter a position between 1 and %d.\n", n + 1);
        return 1; 
    }

    printf("Enter the new element value: ");
    scanf("%d", &newValue);

    for ( i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = newValue;

    printf("Array after insertion:\n");
    for (i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

}

