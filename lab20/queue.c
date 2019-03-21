#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "mylib.h"
#include "graph.h"

struct queue {
    int *items;
    int head;
    int capacity;
    int num_items;
};

queue queue_new(int size){
    int i;
    queue result = emalloc(sizeof *result);
    result->capacity = size;
    result->num_items = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    result->head = 0;

    for(i=0;i<result->capacity;i++){
        result->items[i] = 0;
    }
    return result;
}

queue queue_free(queue q){
    free(q->items);
    free(q);
    return q;
}

void enqueue(queue q,int item){
   
     int position;
     if(q->num_items < q->capacity){
     position = ((q->head) + (q->num_items))%(q->capacity);
     q->items[position] = item;
     q->num_items++;
    }
  
}

double dequeue(queue q){
    
    int dequeue_val;
    if(q->num_items>0){
        
        dequeue_val = q->items[q->head];
        q->num_items--;
        q->head = (q->head+1)%(q->capacity);
        return dequeue_val;
    }
    return -1;
   
}

        
int queue_size(queue q){
    return q->num_items;
}

void queue_print(queue q){
    int i;
    int index;
    for(i=0;i<q->num_items;i++){
        index = (q->head + i)% q->capacity;
        printf("%d\n", q->items[index]);
    }
}


















