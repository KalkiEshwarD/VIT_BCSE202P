// Including all packages necessary for this program to work.
#include <stdio.h>
#include <stdlib.h>

// creating a structure Queue to implement our abstract data type Queue.
struct Queue {
    int front;              // keeps track of the first element in queue.
    unsigned int max_cap;   // it is the maximum capacity of the queue.
    int rear;               // it keeps track of the last item in the queue.
    int *array;             // the array that we will be using to create the queue.
};

// making a function create_queue that helps us in the initialization of a queue.
struct Queue* create_queue(unsigned max_cap) 
{
    struct Queue *my_queue = malloc(sizeof(struct Queue));      // allocates memeory to the Queue data type
    my_queue->front = -1;                                       // since the queue is empty, we make the front element as -1.
    my_queue->max_cap = max_cap;                                // fixing the maximum capcity of the queue we would like to have.
    my_queue->rear = -1;                                        // since queue is empty, we are making the rear element as -1.
    my_queue->array = malloc(max_cap * sizeof(int));            // allocating memory to the array which we will be using to store our items.

    return my_queue;                                            // returns a pointer to the queue data structure.
}

// creating a function is_empty to check if a given queue is empty or not.
int is_empty(struct Queue *input_queue)
{
    int curr_front = input_queue->front;
    int curr_rear = input_queue->rear;    
    if (curr_front == -1 && curr_rear == -1) { 
        return 1;
    } else {
        return 0;
    }
}

// creating a function is_full to check if a given queue is full or not.
int is_full(struct Queue *input_queue)
{
    int curr_rear = input_queue->rear;
    unsigned int max_cap = input_queue->max_cap;
    
    if (curr_rear == max_cap - 1) {
        return 1;
    } else {
        return 0;
    }
}

// creating a function to add items to the queue if necessary.
int enqueue(struct Queue *input_queue, int item)
{
    int curr_rear = input_queue->rear;
    int curr_front = input_queue->front;
    if (is_full(input_queue)) {                                     // we cannot add more elements to the queue if the queue is already full.
        printf("Error!\n");
        printf("Queue full!\n");
        return -1;
    } else {
        if (input_queue->rear == -1 && input_queue->front == -1) {  // adjusting the values of front and rear and then adding an item to the queue.
            input_queue->rear = 0;
            input_queue->front = 0;
        } else {
            input_queue->rear += 1;
        }
        input_queue->array[input_queue->rear] = item;
        printf("Enqueued %d\n", item);
        return 0;
    }

}

// creating a function to remove the first item from the queue and to shift all the elements of the queue.
int dequeue(struct Queue *input_queue)
{
    if (!is_empty(input_queue)) {                               // A queue needs to have something for us to dequeue, just checking that.
        int item = input_queue->array[input_queue->front];
        int i = 0;
        for (i = 0; i < input_queue->rear; i++) {               // shifting all the elements in front after dequeing
            input_queue->array[i] = input_queue->array[i + 1];
        }
        input_queue->array[input_queue->rear] = '\0';
        printf("Dequeued %d\n", item);
    } else {
        printf("Error!\n");
        printf("Queue is empty!\n");
        return -1;
    }
    if (input_queue->front == 0 && input_queue->rear == 0) {
        input_queue->front = -1;
        input_queue->rear = -1;
        return 0;
    } else {
        input_queue->rear -= 1;
        return 0;
    }
    
}


// a few sample commands to display the working of the queue.
int main(int argc, char *argv[])
{
    struct Queue *queue0 = create_queue(10);
    if (is_empty(queue0) == 1) {
        printf("Queue is emtpy\n");
    } else {
        printf("Queue is not empty\n");
    }
    enqueue(queue0, 1);
    enqueue(queue0, 2);
    enqueue(queue0, 3);
    enqueue(queue0, 4);
    enqueue(queue0, 5);
    
    if (is_full(queue0) == 1) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }
    dequeue(queue0);
    dequeue(queue0);
    dequeue(queue0);
    if (is_empty(queue0) == 1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
    return 0;
}
