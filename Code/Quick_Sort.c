#include <stdio.h>

int partition(int *arr, int left, int right) {
    int x = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= x) {
            right--;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] <= x) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = x;
    return left;
}

void quickSort(int *arr, int left, int right) {
    int pos;
    if (left < right) {
        pos = partition(arr, left, right);
        quickSort(arr, left, pos - 1);
        quickSort(arr, pos + 1, right);
    }
}

int main() {
    int arr[] = {3, 4, 6, 1, 2, 4, 7};
    int length = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, length - 1);
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
