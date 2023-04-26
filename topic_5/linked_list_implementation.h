#ifndef LINKED_LIST_IMPLEMENTATION_H
#define LINKED_LIST_IMPLEMENTATION_H

struct Node {
    int data;
    struct Node *next_node; // This is a pointer to the next node. 
};

struct Node* create_node(struct Node *prev_node, int data);
int display(struct Node *node);
struct Node* insert_node(struct Node *node0, int data, unsigned int n);
int delete_node1(struct Node *node0, unsigned int n);
struct Node* search_item(struct Node *node0, int item);

#endif
