#include <stdio.h>
#include <stdlib.h>  // For exit() function

#define MAX_SIZE 5  // Maximum size of the queue

// Global variables
int queue[MAX_SIZE];
int front = 0, rear = 0;

// Function prototypes
void insert();
void delete();
void display();

int main() {
    int choice;

    printf("Queue using Array\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid menu option.\n");
        }
    }

    return 0;
}

void insert() {
    int item;

    if (rear == MAX_SIZE) {
        printf("Queue is full. Insertion is not possible.\n");
    } else {
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        queue[rear++] = item;
        printf("Element %d has been inserted into the queue.\n", item);
    }
}

void delete() {
    if (front == rear) {
        printf("Queue is empty. Deletion is not possible.\n");
    } else {
        printf("Deleted element: %d\n", queue[front++]);
    }
}

void display() {
    if (front == rear) {
        printf("Queue is empty. No elements to display.\n");
    } else {
        printf("Queue elements:\n");
        for (int i = front; i < rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
