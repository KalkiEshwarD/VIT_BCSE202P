#include <stdio.h>

/*
    The indexing of this program begins at 1.
*/

int *insertion_sort(int *arr, int size)
{
    /*
        DESCRIPTION:    The insertion sort works begins its iteration from left to right with parameter 'i' at start index 1.
                        Then for every element that is to the left of the iteration, another iteration cycle begins from right to left beginning at the index 'i'.
                        If the element previous to j is greater than j, then there is a swap between the elements. The iteration stops after at the iteration j = 0.
                        At j = 0, the code gets executed once and exits.
    */
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main()
{
    int arr[10] = {38, 11, 63, 10, 18, 14, 46, 25, 55, 58};
    int size = 10;
    int *result = insertion_sort(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    return 0;
}
