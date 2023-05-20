#include <stdio.h>

int *bubble_sort(int *arr, int size)
{
    for (int i = size - 1 ; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;
}

int main()
{
    int arr[10] = { 61, 16, 45, 7, 58, 96, 82, 56, 75, 73 };
    int size = 10;
    int *result = bubble_sort(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    return 0;
}
