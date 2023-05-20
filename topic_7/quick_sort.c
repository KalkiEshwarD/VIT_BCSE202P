#include <stdio.h>

void swap(int *a, int *b)
{
    /*
        DESCRIPTION: A function to swap two numbers.
        NOTE: Changes value of variable out of scope.
    */
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high)
{
    int pivot = high;
    
    int j = low - 1;
    int k = high;

    for(int i = low; i < high; i++) {
        if (arr[i] <= arr[pivot]) {
            swap(arr + ++j, arr + i); 
        }
    }

    swap(arr + j + 1, arr + pivot);
    return j + 1;
}

void quick_sort(int *arr, int low, int high)
{
    if (low < high) {
        int pivot;

        pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}


int main()
{
    int arr[10] = { 41, 20, 84, 67, 85, 79, 18, 36, 72, 29 };
    int size = 10;

    printf("INPUT ARRAY: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    
    quick_sort(arr, 0, size - 1);
    
    printf("OUTPUT ARRAY: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
 
    return 0;
}
