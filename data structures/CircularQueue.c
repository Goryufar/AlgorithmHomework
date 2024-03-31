#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

void initialize(struct CircularQueue *cq) {
    cq->front = -1;
    cq->rear = -1;
}

int isEmpty(struct CircularQueue *cq) {
    return cq->front == -1;
}

int isFull(struct CircularQueue *cq) {
    return (cq->rear + 1) % MAX_SIZE == cq->front;
}

void enqueue(struct CircularQueue *cq, int value) {
    if (isFull(cq)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(cq))
        cq->front = 0;
    cq->rear = (cq->rear + 1) % MAX_SIZE;
    cq->items[cq->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue Underflow\n");
        exit(EXIT_FAILURE);
    }
    int removed = cq->items[cq->front];
    if (cq->front == cq->rear)
        initialize(cq);
    else
        cq->front = (cq->front + 1) % MAX_SIZE;
    printf("Dequeued %d\n", removed);
    return removed;
}

int peek(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    printf("Front element: %d\n", cq->items[cq->front]);
    return cq->items[cq->front];
}

int main() {
    struct CircularQueue cq;
    initialize(&cq);

    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&cq, value);
                break;
            case 2:
                dequeue(&cq);
                break;
            case 3:
                peek(&cq);
                break;
            case 4:
                printf("Exiting program\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
