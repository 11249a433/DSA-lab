#include <stdio.h>

int search(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;   // return index if found
    }
    return -1;          // return -1 if not found
}

int main()
{
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    int index = search(arr, n, target);

    if (index == -1)
        printf("Element %d not found\n", target);
    else
        printf("Element %d found at position %d\n", target, index + 1);

    return 0;
}