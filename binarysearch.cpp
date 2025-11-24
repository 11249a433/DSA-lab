#include <stdio.h>

int binary_search(int arr[], int target, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 7, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int low = 0;
    int high = n - 1;

    int index = binary_search(arr, target, low, high);

    printf("%d\n", index);

    return 0;
}