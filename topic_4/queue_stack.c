#include <stdio.h>
#include "stack_implementation.h"   // custom built
#include <stdlib.h>

struct Queue {
    /*
        Queue implementation usign two stacks.
        This process is done by having the first element that was enqueued always at the top of stack1.
        Thus, for dequeing, stack1 can simply be poped.
    */
    unsigned int max_cap;       // This is the maximum capacity of the queue.
    int rear;                   // This attribute will help us keep track of how full the queue is.
    struct Stack *stack1;       // This is the primary stack that will hold all the elements.
    struct Stack *stack2;       // This is the auxillary stack that we will use to rearrange stack1.
};


struct Queue* create_queue(unsigned int max_cap) 
{
    /*
        INPUT:  unsigned int --max_cap--
        OUTPUT: Queue pointer object --my_queue--

        DEPENDENCIES:   HEADERS{stdlib.h, stack_implementation.h}
        DESCRIPTION:    This function simply is the initialization of a queue object.
    */
    struct Queue *my_queue = malloc(sizeof(struct Queue));      // Allocating memory to the queue.
    my_queue->max_cap = max_cap;                                // Assigning the value of maximum capacity to the max_cap attribute of queue.
    my_queue->rear = -1;                                        // We are currently assigning rear as -1 as there are no elements in the queue.
    my_queue->stack1 = create_stack(max_cap);                   // Creating the two stacks that we will use.
    my_queue->stack2 = create_stack(max_cap);            

    return my_queue;
}

int queue_is_empty(struct Queue *input_queue)
{
    /*
        INPUT: --input_queue-- [Queue pointer object]
        OUTPUT: --{1, 0}-- [1 if successful process, 0 if unsuccessful]

        DEPENDENCIES:   HEADERS{stack_implementation.h}
        DESCRIPTION:    This is a function that is used to check if the queue is empty.
                        We can use this funciton to check if the queue is empty.
                        This uses the is_empty method present in stack_implementation.c to check if it is empty. 
    */
    if (is_empty(input_queue->stack1) == 1) { 
        return 1;
    } else {
        return 0;
    }
}

int queue_is_full(struct Queue *input_queue)
{
    /*
        INPUT:  --input_queue-- [Queue pointer object]
        OUTPUT: --{1, 0}-- [1 if successful operation, 0 if unsuccessful]

        DEPENDENCIES:   Nil
        DESCRIPTION:    This is used to check if the queue is full using the rear attribute of the queue.
    */
    int curr_rear = input_queue->rear;
    unsigned int max_cap = input_queue->max_cap;
    
    if (curr_rear == max_cap - 1) {
        return 1;
    } else {
        return 0;
    }
}

int enqueue(struct Queue *input_queue, int item)
{
    /*
        INPUT:  --input_queue-- [Queue object pointer]; --item-- [integer item that is to be enqueued]
        OUTPUT: --{0}-- [Returns 0 if the process is successful]

        DEPENDENCIES:   FUNCTIONS{is_empty from stack_implementation.c}; HEADERS{stdio.h}
        DESCRIPTION:    Function that used to enqueue item into queue.
    */
    if (is_empty(input_queue->stack1) == 1) {
        // This branch pushes item into stack1 if it is empty.
        push(input_queue->stack1, item);
        input_queue->rear = 0;
        printf("Enqueued %d into queue\n", item);
        return 0;
    } else {
        // This loop empties stack1 into stack2 if stack1 is not empty.
        while (is_empty(input_queue->stack1) == 0) {
            push(input_queue->stack2, pop(input_queue->stack1));
        }
        
        // Now, the elemnt is pushed into stack1
        push(input_queue->stack1, item);

        // Now all the elemnts in stack2 are emptied into stack1.
        // This entire process is done so that the first element that was enqueued is the first item that can be poped.
        while (is_empty(input_queue->stack2) == 0) {
            push(input_queue->stack1, pop(input_queue->stack2));
        }

        printf("Enqueued %d into queue\n", item);
        input_queue->rear++;
        return 0;
    }
}

int dequeue(struct Queue *input_queue)
{   
    /*
        INPUT:  --input_queue-- [Queue pointer object]
        OUTPUT: --item-- [The item that was dequeued]

        DEPENDENCIES:   FUNCTIONS{queue_is_empty}; HEADERS{stdio.h}
        DESCRIPTION:    Function to dequeue item from queue
    */
    if (queue_is_empty(input_queue) == 1) {
        printf("Error!\n");
        printf("Queue is empty!\n");
        return -1;
    } else {
        int item = pop(input_queue->stack1);
        printf("Dequeued %d from queue.\n", item);
        input_queue->rear--;
        return item;
    }
    
}


// a few sample commands to display the working of the queue.
int main(int argc, char *argv[])
{
    struct Queue *queue0 = create_queue(5);
    if (queue_is_empty(queue0) == 1) {
        printf("Queue is emtpy\n");
    } else {
        printf("Queue is not empty\n");
    }
    enqueue(queue0, 1);
    enqueue(queue0, 2);
    enqueue(queue0, 3);
    enqueue(queue0, 4);
    enqueue(queue0, 5);
    if (queue_is_full(queue0) == 1) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }
    dequeue(queue0);
    dequeue(queue0);
    dequeue(queue0);
    dequeue(queue0);
    dequeue(queue0);
    if (queue_is_empty(queue0) == 1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    enqueue(queue0, 1);
    enqueue(queue0, 2);
    enqueue(queue0, 3);
    enqueue(queue0, 4);
    enqueue(queue0, 5);

    if (queue_is_empty(queue0) == 1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
    if (queue_is_full(queue0) == 1) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }
    return 0;
}
