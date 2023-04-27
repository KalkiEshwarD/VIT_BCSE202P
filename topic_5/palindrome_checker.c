#include <stdio.h>
#include "../Topic 2/stack_implementation.h"
#include "linked_list_implementation.h"


int palindrome_checker(struct Node *head)
{
    /*
        INPUT: --head-- [It is the pointer to the first node of a linked list]
        OUTPUT: {0, 1} [0 if the elements do not form a palindrome and 1 if they form a palindrome.] 
        
        DEPENDENCIES:   HEADERS{linked_list_implementation.h, stack_implementation.h} 
        DESCRIPTION:    This is a function that is used to find out if the elements in a linked list form a palindrome or not.
    */
    int size = 1;
    struct Node *following_node = head;

    do {
        size++;
        following_node = following_node->next_node;
    } while (following_node->next_node != NULL);

    struct Stack *stack0 = create_stack(size);
    struct Node *fol_node = head;
    do {
        push(stack0, fol_node->data);
        fol_node = fol_node->next_node;
    } while (fol_node->next_node != NULL);
    push(stack0, fol_node->data);

    struct Node *comp_node = head;
    do {
        int item = pop(stack0);
        if (item == comp_node->data) {
        } else {
            return 0;
        }
        comp_node = comp_node->next_node;
    } while (is_empty(stack0) != 1);
    
    return 1;
}

int main()
{   
    // Creating a few nodes and linking them with create_node method.   
    struct Node *n0 = create_node(NULL, 1);
    struct Node *n1 = create_node(n0, 2);
    struct Node *n2 = create_node(n1, 3);
    struct Node *n3 = create_node(n2, 2);
    struct Node *n4 = create_node(n3, 1);
    
    int result = palindrome_checker(n0);
    if (result == 1) {
        printf("They form a palindrome!");
    } else {
        printf("They do not form a palindrome!");
    }

    return 0;
}
