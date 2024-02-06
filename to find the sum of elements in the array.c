
#include <stdio.h>

int main() {
    int n, count = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int i,j,arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for ( i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break; 
            }
        }
    }

    printf("Number of duplicate elements: %d\n", count);

}
