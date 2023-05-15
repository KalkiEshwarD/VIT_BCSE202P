#include <stdio.h>

int binary_search(int *arr, int high, int low, int item)
{
    /*
        INPUT:  --{arr, high, low, item}-- [integer pointer to an array, integer, integer integer], (integer pointer to sorted array, the upper index of array, the lower index of array, the item to be searched)
        OUTPUT: --{m, l + binary_search(arr +1, h, l item), -1}-- [integer, integer, integer] This returns the value of the index at which the element is present.

        DEPENDENCIES: Nil
        DESCRIPTION: This is a function that takes in a sorted index and item to be searched and then outputs the value of the index at which the item is present.
        NOTE: Function works only on sorted arrays.
    */
    int h = high, l = low;
    int m = ((int)h + (int)l) / 2;
    
    if (item == arr[m]) {
        return m;
    } else if (item > arr[m]) {
        l = m;
        return l + binary_search(arr + l, h, l, item);
    } else if (item < arr[m]) {
        h = m;
        return l + binary_search(arr, h, l, item);
    } else {
        return -1;
    }
}

int main()
{
    int list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int result = binary_search(list, 0, 9, 6);
    printf("INDEX = %d\n", result);

    return 0;
}
