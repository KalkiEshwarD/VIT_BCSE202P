// Including packages that are required for the program to work, as well as the custom header stack_implementation
#include <stdio.h>
#include "stack_implementation.h"   // custom built



void stack_game()
{
    /*
        INPUT:  Nil
        OUTOUT: void

        DEPENDENCIES: HEADER{stack_implementation.h}
        DESCRIPTION:    This is a stack game where a function takes integer input in the form of integers seperated by space.
                        Player A uses the numbers that were provided first.
                        Player B uses the numbers that were provided latest.
                        The player who has the lower card on comparison, must forfeit their card and proceed to the next card
                        The player who loses all of his cards loses the game.
    */
    int n;
    scanf("%d", &n);
    
    // creating two stacks stack_A and stack_B
    struct Stack *stack_A = create_stack(n);
    struct Stack *stack_B = create_stack(n);
    int result_list[n];
    
    // Taking in inputs to stack B
    int arr[n];
    int item;
    for (int i = 0; i < n; i++) {
        scanf("%d", &item);
        arr[i] = item;          // Storing items in array to supply to stack A.
        push(stack_B, item);
    }
    // Taking in inputs to stack A
    for (int j = n - 1; j > -1; j--) {
        push(stack_A, arr[j]);
    }

    //  The game begins with the results of each comparison being stored in an integer array called result_list.
    int loop = 0;
    while (is_empty(stack_A) != 1 && is_empty(stack_B) != 1) {
        int item_a = top(stack_A);
        int item_b = top(stack_B);

        if (item_a > item_b) {
            pop(stack_B);
            result_list[loop] = 1;
        } else if (item_a < item_b) {
            pop(stack_A);
            result_list[loop] = 2;
        } else {
            pop(stack_A);
            pop(stack_B);
            result_list[loop] = 0;
        }
        loop++;
    }

    // Printing the result list.
    for (int k = 0; k < loop; k++) {
        printf("%d ", result_list[k]);
    }
}

int main()
{
    stack_game();

    return 0;
}
