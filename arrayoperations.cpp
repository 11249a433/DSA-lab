#include <stdio.h>

void show(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5, pos, key, cap = 100;
    int result = -1;

    printf("Array: ");
    show(arr, n);

    // Searching
    key = 30;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            result = i;
            break;
        }
    }

    if (result != -1)
        printf("%d found at index %d\n", key, result);
    else
        printf("%d not found\n", key);

    // Insertion
    pos = 3;     // insert at index 3
    int ele = 60;

    if (n < cap) {
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = ele;
        n++;
    }

    printf("After insertion: ");
    show(arr, n);

    // Deletion
    pos = 2;  // delete index 2

    if (pos >= 0 && pos < n) {
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    printf("After deletion: ");
    show(arr, n);

    return 0;
}