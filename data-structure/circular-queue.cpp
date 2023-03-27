#include <iostream>

using namespace std;

#define QUEUE_SIZE 5

struct Queue{
    int front=0, rear=-1, count=0;
    int item[QUEUE_SIZE];
};

typedef struct Queue queue;

bool empty(queue *q){
    return !q->count;
}

void enqueue(queue *q, int entry){
    if (q->count == QUEUE_SIZE) return;
    q->rear++;
    if (q->rear == QUEUE_SIZE) q->rear = 0;
    q->item[q->rear] = entry;
    if (q->count == 0) q->front == 0;
    q->count++;
}

int dequeue(queue *q){
    if (empty(q)) exit(1);
    int dat = q->item[q->front];
    if (++q->front == QUEUE_SIZE) q->front = 0;
    if (q->count-- == 1) q->front = q->rear = -1;
    return dat;
}

void printQueue(queue *q){
    if (q->rear < q->front){
        for (int i = q->front; i < QUEUE_SIZE; i++) cout << q->item[i] << " ";
        for (int i = 0; i <= q->rear; i++) cout << q->item[i] << " ";
    } else {
        for (int i = q->front; i <= q->rear; i++) cout << q->item[i] << " ";
    }
    
}

void meta(queue *q){
    cout << "\n" << q->front << " " << q->rear << " " << q->count<< "\n";
}

int main(){
    queue q;

    for (int i = 1; i <= 5; i++){
        enqueue(&q, i);
    }
     for (int i = 1; i <= 2; i++) dequeue(&q);
     for (int i = 7; i <= 9; i++) enqueue(&q, i);
    meta(&q);
    printQueue(&q);

    
    return 0;
}
