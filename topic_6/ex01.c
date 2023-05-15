#include <stdio.h>

int linear_search(int *array_pointer, int size, int item)
{
    /*
        INPUT:  --{arr_pointer, size, item}-- [integer pointer to an array, integer, integer], (integer pointer to sorted array, the size of array, the item to be searched)
        OUTPUT: --i-- This returns the value of the index at which the element is present.

        DEPENDENCIES: Nil
        DESCRIPTION: This is a function that takes in an array, its size and the item to be search and outputs the index of of the first occurence of the item in array..
    */
    for (int i = 0; i < size; i++) {
        if (array_pointer[i] == item) {
            return i;
        }
    }

    return -1;
}

int main()
{
    int list[10] = {5, 6, 7, 8, 9, 1, 4, 3, 2, 0};

    int result = linear_search(list, 10, 9);
    printf("INDEX = %d\n", result);

    return 0;
}
