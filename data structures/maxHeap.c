#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct MaxHeap {
    int *array;
    int capacity;
    int size;
};

struct MaxHeap* createMaxHeap(int capacity) {
    struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->capacity = capacity;
    maxHeap->size = 0;
    maxHeap->array = (int*) malloc(capacity * sizeof(int));
    return maxHeap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct MaxHeap* maxHeap, int index) {
    while (index > 0 && maxHeap->array[(index - 1) / 2] < maxHeap->array[index]) {
        swap(&maxHeap->array[index], &maxHeap->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void insert(struct MaxHeap* maxHeap, int key) {
    if (maxHeap->size == maxHeap->capacity) {
        printf("Overflow: Could not insert key\n");
        return;
    }
    maxHeap->size++;
    int index = maxHeap->size - 1;
    maxHeap->array[index] = key;
    heapifyUp(maxHeap, index);
}

int extractMax(struct MaxHeap* maxHeap);

int peek(struct MaxHeap* maxHeap) {
    if (maxHeap->size <= 0)
        return INT_MIN;
    return maxHeap->array[0];
}

void increaseKey(struct MaxHeap* maxHeap, int index, int newValue) {
    if (index < 0 || index >= maxHeap->size) {
        printf("Index out of range\n");
        return;
    }
    maxHeap->array[index] = newValue;
    heapifyUp(maxHeap, index);
}

void heapifyDown(struct MaxHeap* maxHeap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
        largest = right;

    if (largest != index) {
        swap(&maxHeap->array[index], &maxHeap->array[largest]);
        heapifyDown(maxHeap, largest);
    }
}

int extractMax(struct MaxHeap* maxHeap) {
    if (maxHeap->size <= 0)
        return INT_MIN;
    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->array[0];
    }

    int root = maxHeap->array[0];
    maxHeap->array[0] = maxHeap->array[maxHeap->size - 1];
    maxHeap->size--;
    heapifyDown(maxHeap, 0);
    return root;
}

void printMaxHeap(struct MaxHeap* maxHeap) {
    printf("Max Heap: ");
    for (int i = 0; i < maxHeap->size; i++)
        printf("%d ", maxHeap->array[i]);
    printf("\n");
}

int main() {
    struct MaxHeap* maxHeap = createMaxHeap(10);
    int choice, key, index, newValue;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Extract Maximum\n");
        printf("3. Peek\n");
        printf("4. Increase Key\n");
        printf("5. Print Max Heap\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(maxHeap, key);
                break;
            case 2:
                printf("Extracted Max element: %d\n", extractMax(maxHeap));
                break;
            case 3:
                printf("Maximum element (Peek): %d\n", peek(maxHeap));
                break;
            case 4:
                printf("Enter index and new value: ");
                scanf("%d %d", &index, &newValue);
                increaseKey(maxHeap, index, newValue);
                break;
            case 5:
                printMaxHeap(maxHeap);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
