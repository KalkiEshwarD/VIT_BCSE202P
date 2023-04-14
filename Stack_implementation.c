/*
Including all necessary packages for the program to work.
*/
#include <stdio.h>
#include <stdlib.h>

/*
Creating a structure called Stack.
Creating three members in the stack group.
An integer called top, which keeps track of the level until which the stack has been filled
An unsigned (positive integer) max_cap which is teh maximum capacity of the stack.
*/
struct Stack {
    int top;
    unsigned int max_cap;
    int *array; // This is an array pointer. 
};

/*
Creating a function called create_stack which returns a Stack structure pointer.
It takes in an input of the maximum capacity of the stack which is to be created.
*/
struct Stack* create_stack(unsigned max_cap)
{
    struct Stack *my_stack = malloc(sizeof(struct Stack)); // Using malloc to create space for a Stack. This memory is pointing to a 
    my_stack->top = -1; // Using top, member of stack and assigning it the value of -1 as no elements are present in stack.
    my_stack->max_cap = max_cap;
    my_stack->array = malloc(max_cap * sizeof(int));    // allocating memory to array which we will use to store elements

    return my_stack;
}

/*
Creating a function is_empty which we shall use to check if a given stack is empty
The input of this function is a pointer to the stack structure.
*/
int is_empty(struct Stack *input_stack)
{
    int curr_top = input_stack->top;    
    if (curr_top == -1) { 
        return 1;
    } else {
        return 0;
    }
}

/*
Creating a function is_full which we shall use to check if a given stack is full
The input of this function is a pointer to the stack structure.
*/
int is_full(struct Stack *input_stack)
{
    int curr_top = input_stack->top;
    unsigned int max_cap = input_stack->max_cap;
    if (curr_top == max_cap - 1) {
        return 1;
    } else {
        return 0;
    }
}

/*
The top function is used to print the last index that was filled*/
int top(struct Stack *input_stack)
{
    printf("Top: %d\n", input_stack->top);
    return input_stack->top;
}

/*
Push is used to push an item to the stack.
*/
int push(struct Stack *input_stack, int item)
{
    if (!is_full(input_stack)) {
        input_stack->top += 1;
        input_stack->array[input_stack->top] = item;
        printf("Pushed %d onto stack\n", item);
        return 0;
    } else {
        printf("Error!\n");
        return -1;
    }
    
}

/*
Pop is used to remove the last filled element to stack.
*/
int pop(struct Stack *input_stack)
{
    if (!is_empty(input_stack)) {
        int item = input_stack->array[input_stack->top];
        input_stack->array[input_stack->top] = '\0';
        input_stack->top -= 1;
        printf("Popped %d from the stack\n", item);
        return 0;
    } else {
        printf("Error!\n");
        return -1;
    }
    
}

/*
Creating a stack of size 3 and then preforming a few operations.
*/
int main()
{
    struct Stack *stack0 = create_stack(3);
    if (is_empty(stack0) == 1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
    push(stack0, 3);
    top(stack0);
    push(stack0, 2);
    top(stack0);
    push(stack0, 3);
    if (is_full(stack0) == 1) {
        printf("Stack is full\n");
    } else {
        printf("Stack is not full\n");
    }
    top(stack0);
    pop(stack0);
    top(stack0);
    pop(stack0);
    top(stack0);
    pop(stack0);
    top(stack0);
    if (is_empty(stack0) == 1) {
        printf("Stack is emtpy\n");
    } else {
        printf("Stack is not empty\n");
    }
    return 0;
}
