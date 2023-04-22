#ifndef STACK_IMPLEMENTATION_H
#define STACK_IMPLEMENTATION_H

struct Stack {
    /*
    Creating a structure called Stack.
    Creating three members in the stack group.
    An integer called top, which keeps track of the level until which the stack has been filled
    An unsigned (positive integer) max_cap which is teh maximum capacity of the stack.
    */
    int top;
    unsigned int max_cap;
    char *array; // This is an array pointer. 
};

struct Stack* create_stack(unsigned max_cap);
int is_empty(struct Stack *input_stack);
int is_full(struct Stack *input_stack);
int top(struct Stack *input_stack);
int pop(struct Stack *input_stack);
int push(struct Stack *input_stack, char item);
int free_stack(struct Stack *input_stack);

#endif
