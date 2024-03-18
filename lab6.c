#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to insert an element into the circular queue
void insert(char element) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = element;
    printf("Element %c inserted into the queue.\n", element);
}

// Function to delete an element from the circular queue
char delete() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return -1;
    }
    char deletedElement = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("Element %c deleted from the queue.\n", deletedElement);
    return deletedElement;
}

// Function to display the status of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    do {
        printf("%c ", queue[i]);
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    printf("\n");
}

int main() {
    int choice;
    char element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf(" %c", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
