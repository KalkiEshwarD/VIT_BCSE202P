/*
Including all necessary packages for the program to work.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list_implementation.h"

struct Node {
    int data;
    struct Node *next_node; // This is a pointer to the next node. 
};

struct Node* create_node(struct Node *prev_node, int data)
{
    /*
        This is a node initializer which will help us create nodes.
    */
    struct Node *my_node = malloc(sizeof(struct Node));
    my_node->data = data;
    my_node->next_node = NULL;

    if (prev_node != NULL) {
        prev_node->next_node = my_node;
        
    }
    return my_node;
}

int display(struct Node *node)
{
    /*
        Using a function display to show all the elements present in the linked list.
    */
    printf("%d->", node->data);
    if (node->next_node != NULL) {      // if the next node pointer is not null, then the program proceedes to the next node, else it prints null.
        display(node->next_node);
        return 0;
    } else {
        printf("NULL");
        return 0;
    }
}

struct Node* insert_node(struct Node *node0, int data, unsigned int n)
{
    /*
        Using a function insert node to insert a node in the nth position of the list.
    */
    struct Node *my_node = malloc(sizeof(struct Node));

    int k = 0;
    struct Node* following_node = node0;
    if (n == 0) {
        my_node->data = data;
        my_node->next_node = following_node;
        return my_node;
    }
    while (k <= n) {
        if (n == k) {
            my_node->data = data;
            my_node->next_node = following_node;
            return my_node;
        } else if (n - k == 1) {
            struct Node *node2 = following_node->next_node;
            following_node->next_node = my_node;
            my_node->next_node = node2;
            return node0;
        }
        k++;
        if (following_node->next_node != NULL) {
            following_node = following_node->next_node;
        } else {
            printf("Error!\n");
            printf("Node out of bounds!\n");
            return my_node;
        }
    }


    return node0;
}

int delete_node(struct Node *node0, unsigned int n)
{
    /*
        This is a function that is used to delete the nth node in the linked list.
    */
    int k = 0;
    struct Node* curr_node = node0;
    
    if (n == 0) {
        free(curr_node);
        return 0;
    }
    while (k <= n) {
        if (k == n) {
            free(curr_node);
            return 0;
        } else if (n - k == 1) {
            curr_node->next_node = curr_node->next_node->next_node;
            return 0;
        }
        k++;
        curr_node = curr_node->next_node;
    }
}

struct Node* search_item(struct Node *node0, int item)
{
    /*
        This is a function that returns the first node that is found with the specified item
    */   
    struct Node *following_node = node0;
    if (following_node->data == item) {
        return following_node;
    } else {
        while (following_node->data != item) {
            if (following_node->next_node != NULL) {
                following_node = following_node->next_node;
            } else {
                printf("Item not found!\n");
                return node0;
            }
        }

        printf("Item found!\n");
        return following_node;
    }
}
