#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of values: ");
    scanf("%d", &n);

    int i,arr[n];

    printf("Enter %d values:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Values in reverse order are: ");
    for ( i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

}
