#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int i,j,arr[n];
    printf("Enter %d elements:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unique elements in the array: ");
    for (i = 0; i < n; i++) {
        int isUnique = 1; 

        for ( j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = 0; 
                break;
            }
        }

        if (isUnique) {
            printf("%d ", arr[i]);
        }
    }

}
