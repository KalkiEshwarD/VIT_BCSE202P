#include <stdio.h>

int factorial(int n)
{
    /*
        INPUT: --n-- [integer]
        OUTPUT: --fact, {1}-- [integer]

        DEPENDENCIES: Nil
        DESCRIPTION: This is a recursive function that is used to compute the factorial of a number.
    */

    if (n == 1) { 
        return 1;
    } else if (n == 0) {
        return 1;
    } else if(n < 0) {
        return -1;
    }

    int fact = n * factorial(n - 1);

    return fact;
}

int main()
{
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);
    int result = factorial(num);
    printf("Factorial of %d = %d\n", num, result);
    
    return 0;
}
