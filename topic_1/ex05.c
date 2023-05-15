#include <stdio.h>


int max_finder(int array[], int size)
{
    /*
        INPUT: --array-- [integer pointer to an array]
        OUPUT: --max-- [integer] Maximum value of element present in integer
        
        DEPENDENCIES: Nil
        DESCRIPTION: This is a function that takes in integer pointer to an array as input and then outputs the maximum value of the integer.
    */

    int max = array[0];

    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}


int main()
{
    int num_array[] = { 1, 2, 43, 95, 76, 29, 83, 57 };

    int result = max_finder(num_array, 8);
    printf("Max of given array is: %d\n", result);


    return 0;
}
