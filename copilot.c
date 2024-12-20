#include <stdio.h>

void insertElement(int arr[], int *n, int element, int index) {
    if (index < 0 || index >= *n) {
        printf("Invalid index\n");
        return;
    }

    for (int i = *n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = element;
    (*n)++;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5;
    int element = 10;
    int index = 2;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertElement(arr, &n, element, index);

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}