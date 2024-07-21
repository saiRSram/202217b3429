#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int b[MAX];  // Array to store elements
int n = 0;   // Current number of elements in the list

// Function prototypes
void create();
void deletion();
void search();
void insert();
void display();

int main() {
    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Enter the correct choice (1-6):\n");
                break;
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');

    return 0;
}

void create() {
    int i;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    int pos, i;

    if (n == 0) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    printf("\nEnter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return;
    }

    for (i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;

    printf("Element at position %d deleted successfully.\n", pos);
}

void search() {
    int e, i;
    printf("\nEnter the element to search: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Element %d found at position %d.\n", e, i);
            return;
        }
    }
    printf("Element %d not found in the list.\n", e);
}

void insert() {
    int pos, i, p;

    if (n == MAX) {
        printf("List is full. Cannot insert.\n");
        return;
    }

    printf("\nEnter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &p);

    for (i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }
    b[pos] = p;
    n++;

    printf("Element inserted successfully.\n");
}

void display() {
    int i;

    if (n == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("\nElements in the list:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
