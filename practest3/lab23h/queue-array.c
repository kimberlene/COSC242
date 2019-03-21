#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

struct queue {
    double *items;
    int head;
    int capacity;
    int num_items;
};

queue queue_new() {
    
    int default_size = 7, i;
    
    queue result = emalloc(sizeof *result);

    result->head = 0;
    result->num_items = 0;
    result->capacity = default_size;

    result->items = emalloc(result->capacity * sizeof result->items[0]);

    for (i = 0; i < result->capacity; i++) {
        result->items[i] = 0;
    }
    
    return result;
}

void enqueue(queue q, double item) {
    if (q->num_items < q->capacity) {
        q->items[(q->head + q->num_items++) % q->capacity] = item;
    }
}

double dequeue(queue q) {
    if (q->num_items > 0) {
        double result = q->items[q->head];

        if (q->head == q->capacity - 1) {
            q->head = 0;
        } else {
            q->head++;
        }
        q->num_items--;

        return result;
        
    } else {
        printf("Queue Empty.\n");
        return 0;
    }
}

void queue_print(queue q) {
    int count = 0;
    int i = q->head;

    while (count < q->num_items) {
        printf("%.2f\n", q->items[i]);
        i = (i + 1) % q->capacity;
        count++;
    }
}

void queue_print_info(queue q) {
    int i;
    printf("capacity %d, num_items %d, head %d\n[", q->capacity, q->num_items,
           q->head);
    for (i = 0; i < q->capacity; i++) {
        printf("%s%.2f", i == 0 ? "" : ", ", q->items[i]);
    }
    printf("]\n");
}

int queue_size(queue q) {
    return q->num_items;
}

queue queue_free(queue q) {
    free(q->items);
    free(q);

    return q;
}
