#include <stdio.h>

void swap(int *num1, int *num2)
{
    /*
        INPUT: --{num1, num2}-- [integer pointer, integer pointer]
        OUTPUT: Nil 

        DEPENDENCIES: Nil
        DESCRIPTION: This is a function that swaps the value of two variables given the variables' pointers.
        NOTE: Function changes value of variable which is out of scope.
    */

    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


int main()
{
    int n1, n2;
    printf("Enter first number: ");
    scanf("%d", &n1);
    printf("Enter second number: ");
    scanf("%d", &n2);

    printf("Swapping values.\n");
    swap(&n1, &n2);

    printf("Value of first number: %d \nValue of second number: %d", n1, n2);
    

    return 0;
}
