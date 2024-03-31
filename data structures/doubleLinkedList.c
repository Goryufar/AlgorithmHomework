#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;


void insert(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Node inserted at the beginning.\n");
}

void delete(int key) {
    struct Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    printf("Node with data %d deleted.\n", key);
}

void search(int key) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL && current->data != key) {
        current = current->next;
        position++;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", key);
    } else {
        printf("Node with data %d found at position %d.\n", key, position);
    }
}

void display() {
    struct Node* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                printf("Enter the item to delete: ");
                scanf("%d", &item);
                delete(item);
                break;
            case 3:
                printf("Enter the item to search: ");
                scanf("%d", &item);
                search(item);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
