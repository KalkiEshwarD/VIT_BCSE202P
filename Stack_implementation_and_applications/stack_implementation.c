#include <stdio.h>
#include <stdlib.h>
#include "stack_implementation.h"

struct Stack* create_stack(unsigned max_cap)
{
    /*
    Creating a function called create_stack which returns a Stack structure pointer.
    It takes in an input of the maximum capacity of the stack which is to be created.
    */
    struct Stack *my_stack = malloc(sizeof(struct Stack)); // Using malloc to create space for a Stack. This memory is pointing to a 
    my_stack->top = -1; // Using top, member of stack and assigning it the value of -1 as no elements are present in stack.
    my_stack->max_cap = max_cap;
    my_stack->array = malloc(max_cap * sizeof(int));    // allocating memory to array which we will use to store elements

    return my_stack;
}


int is_empty(struct Stack *input_stack)
{
    /*
    Creating a function is_empty which we shall use to check if a given stack is empty
    The input of this function is a pointer to the stack structure.
    */
    int curr_top = input_stack->top;    
    if (curr_top == -1) { 
        return 1;
    } else {
        return 0;
    }
}

int is_full(struct Stack *input_stack)
{
    /*
    Creating a function is_full which we shall use to check if a given stack is full
    The input of this function is a pointer to the stack structure.
    */
    int curr_top = input_stack->top;
    unsigned int max_cap = input_stack->max_cap;
    if (curr_top == max_cap - 1) {
        return 1;
    } else {
        return 0;
    }
}

int top(struct Stack *input_stack)
{
    /*
    The top function is used to print the last element that was pushed to the stack.
    */
    return input_stack->array[input_stack->top];
}

int push(struct Stack *input_stack, int item)
{
    /*
    Push is used to push an item to the stack.
    */
    if (!is_full(input_stack)) {
        input_stack->top += 1;
        input_stack->array[input_stack->top] = item;
        return 0;
    } else {
        printf("Error!\n");
        return -1;
    }
    
}


int pop(struct Stack *input_stack)
{
    /*
    Pop is used to remove the last filled element to stack.
    */
    if (!is_empty(input_stack)) {
        int item = input_stack->array[input_stack->top];
        input_stack->array[input_stack->top] = '\0';
        input_stack->top -= 1;
        return item;
    } else {
        printf("Error!\n");
        return -1;
    }
    
}
