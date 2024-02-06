#include <stdio.h>
#include <stdio.h>

int main() {
    int n,i,index;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return 1; 
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the index to delete the element (0 to %d): ", n - 1);
    scanf("%d", &index);

    if (index < 0 || index >= n) {
        printf("Invalid index. Please enter an index between 0 and %d.\n", n - 1);
        return 1; 
    }

    for ( i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
}
	
    printf("Array after deletion: \n");
    for ( i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

}

