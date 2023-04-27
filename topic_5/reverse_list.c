#include <stdio.h>
#include "linked_list_implementation.h"

struct Node *reverse_list(struct Node *head)
{
    /*
        INPUT:  --head-- [The pointer to the head node of a linked list]
        OUTPUT: --{prev_node / curr_node / prev_node} [These are the elements that are returned when the size of linked list is 1, 2 and greater than 2.]

        DEPENDENDENCIES:    HEADERS{linked_list_implementation.c}
        DESCRIPTION:    This is a function that is used to reverse the elements of a linked list using iterative process, for this, we will be using three nodes.
                        The nodes being prev_node, curr_node and following_node. The next_node attribute of the curr_node is assigned the previous_node pointer.
                        The following node is used to keep the count going.
                        The iterative process begins after covering a few base cases when the size is 1 and 2.
    */
    struct Node *counter_node = head;
    unsigned int size = 0;
    while (counter_node != NULL) {
        size++;
        counter_node = counter_node->next_node;
    }

    if (size == 1) {
        struct Node *prev_node = head;
        return prev_node; 
    } else if (size == 2) {
        struct Node *prev_node = head;
        struct Node *curr_node = head->next_node;
        prev_node->next_node = NULL;
        curr_node->next_node = prev_node;

        return curr_node;
    }

    struct Node *prev_node = head;
    struct Node *curr_node = head->next_node;   
    prev_node->next_node = NULL;
    
    struct Node *following_node = curr_node->next_node;

    
    do {
        curr_node->next_node = prev_node;
        prev_node = curr_node;

        curr_node = following_node;
        following_node = following_node->next_node;
    }
    while (following_node != NULL);
    
    curr_node->next_node = prev_node;
    prev_node = curr_node;

    curr_node = following_node;       
    head = prev_node;
    return head;
}

int main()
{
    // Creating a few nodes
    struct Node *n0 = create_node(NULL, 0);
    struct Node *n1 = create_node(n0, 1);
    struct Node *n2 = create_node(n1, 2);
    struct Node *n3 = create_node(n2, 3);
    struct Node *n4 = create_node(n3, 4);
    struct Node *n5 = create_node(n4, 5);
    struct Node *head = n0;

    head = reverse_list(head);
    display(head);  // The method that is used to display all the elements of the linked list.

    return 0;
    
}
