#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent employee data
struct Employee {
    char SSN[20];
    char Name[50];
    char Dept[50];
    char Designation[50];
    float Sal;
    long long int PhNo;
    struct Employee *prev;
    struct Employee *next;
};

// Global variables to keep track of the head and tail of the doubly linked list
struct Employee *head = NULL;
struct Employee *tail = NULL;

// Function to create a new employee node
struct Employee* createNode(char SSN[], char Name[], char Dept[], char Designation[], float Sal, long long int PhNo) {
    struct Employee *newNode = (struct Employee*)malloc(sizeof(struct Employee));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->SSN, SSN);
    strcpy(newNode->Name, Name);
    strcpy(newNode->Dept, Dept);
    strcpy(newNode->Designation, Designation);
    newNode->Sal = Sal;
    newNode->PhNo = PhNo;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an employee at the end of the doubly linked list
void insertEnd(char SSN[], char Name[], char Dept[], char Designation[], float Sal, long long int PhNo) {
    struct Employee *newNode = createNode(SSN, Name, Dept, Designation, Sal, PhNo);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to display the status of the doubly linked list and count the number of nodes
void displayAndCount() {
    if (head == NULL) {
        printf("DLL is empty.\n");
        return;
    }
    struct Employee *temp = head;
    int count = 0;
    printf("DLL:\n");
    while (temp != NULL) {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Sal: %.2f, PhNo: %lld\n", temp->SSN, temp->Name, temp->Dept, temp->Designation, temp->Sal, temp->PhNo);
        temp = temp->next;
        count++;
    }
    printf("Number of nodes: %d\n", count);
}

// Function to delete the front node of the doubly linked list
void deleteFront() {
    if (head == NULL) {
        printf("DLL is empty.\n");
        return;
    }
    struct Employee *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    free(temp);
    printf("Front node deleted.\n");
}

// Function to delete the end node of the doubly linked list
void deleteEnd() {
    if (head == NULL) {
        printf("DLL is empty.\n");
        return;
    }
    struct Employee *temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    printf("End node deleted.\n");
}

int main() {
    int choice;
    char SSN[20], Name[50], Dept[50], Designation[50];
    float Sal;
    long long int PhNo;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Display and Count\n");
        printf("3. Delete Front\n");
        printf("4. Delete End\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter employee details (SSN Name Dept Designation Sal PhNo): ");
                scanf("%s %s %s %s %f %lld", SSN, Name, Dept, Designation, &Sal, &PhNo);
                insertEnd(SSN, Name, Dept, Designation, Sal, PhNo);
                break;
            case 2:
                displayAndCount();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteEnd();
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
