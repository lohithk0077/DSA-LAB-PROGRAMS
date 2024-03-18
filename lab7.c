#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent student data
struct Student {
    char USN[20];
    char Name[50];
    char Programme[50];
    int Sem;
    long long int PhNo;
    struct Student *next;
};

// Global variable to keep track of the head of the linked list
struct Student *head = NULL;

// Function to create a new student node
struct Student* createNode(char USN[], char Name[], char Programme[], int Sem, long long int PhNo) {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->USN, USN);
    strcpy(newNode->Name, Name);
    strcpy(newNode->Programme, Programme);
    newNode->Sem = Sem;
    newNode->PhNo = PhNo;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a student at the front of the linked list
void insertFront(char USN[], char Name[], char Programme[], int Sem, long long int PhNo) {
    struct Student *newNode = createNode(USN, Name, Programme, Sem, PhNo);
    newNode->next = head;
    head = newNode;
}

// Function to insert a student at the end of the linked list
void insertEnd(char USN[], char Name[], char Programme[], int Sem, long long int PhNo) {
    struct Student *newNode = createNode(USN, Name, Programme, Sem, PhNo);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Student *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the status of the linked list and count the number of nodes
void displayAndCount() {
    if (head == NULL) {
        printf("SLL is empty.\n");
        return;
    }
    struct Student *temp = head;
    int count = 0;
    printf("SLL:\n");
    while (temp != NULL) {
        printf("USN: %s, Name: %s, Programme: %s, Sem: %d, PhNo: %lld\n", temp->USN, temp->Name, temp->Programme, temp->Sem, temp->PhNo);
        temp = temp->next;
        count++;
    }
    printf("Number of nodes: %d\n", count);
}

// Function to delete the front node of the linked list
void deleteFront() {
    if (head == NULL) {
        printf("SLL is empty.\n");
        return;
    }
    struct Student *temp = head;
    head = head->next;
    free(temp);
    printf("Front node deleted.\n");
}

// Function to delete the end node of the linked list
void deleteEnd() {
    if (head == NULL) {
        printf("SLL is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("End node deleted.\n");
        return;
    }
    struct Student *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("End node deleted.\n");
}

int main() {
    int choice, Sem;
    char USN[20], Name[50], Programme[50];
    long long int PhNo;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Display and Count\n");
        printf("4. Delete Front\n");
        printf("5. Delete End\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student details (USN Name Programme Sem PhNo): ");
                scanf("%s %s %s %d %lld", USN, Name, Programme, &Sem, &PhNo);
                insertFront(USN, Name, Programme, Sem, PhNo);
                break;
            case 2:
                printf("Enter student details (USN Name Programme Sem PhNo): ");
                scanf("%s %s %s %d %lld", USN, Name, Programme, &Sem, &PhNo);
                insertEnd(USN, Name, Programme, Sem, PhNo);
                break;
            case 3:
                displayAndCount();
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
