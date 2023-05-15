#include <stdio.h>

int fibonacci(int n)
{
    /*
        INPUT: --n-- [integer]
        OUTPUT: --{fibonacci(n -1) + fibonacci(n -2), 1}-- [integer] Returns multiple values.

        DEPENDENCIES: Nil
        DESCRIPTION: This is a recursive function. It returns the value of term n of the fibonacci series.
    */

    if (n == 1) {
        return 1;
    } else if(n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);
    int result = fibonacci(num);
    printf("Term %d of Fibonacci = %d\n", num, result);  
 

    return 0;
}
