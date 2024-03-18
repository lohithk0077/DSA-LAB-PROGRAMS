#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = element;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void checkPalindrome() {
    int tempTop = top;
    int isPalindrome = 1;
    while (tempTop > top / 2) {
        if (stack[tempTop] != stack[top - tempTop]) {
            isPalindrome = 0;
            break;
        }
        tempTop--;
    }
    if (isPalindrome) {
        printf("Stack contents form a Palindrome\n");
    } else {
        printf("Stack contents do not form a Palindrome\n");
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("a. Push\n");
        printf("b. Pop\n");
        printf("c. Check Palindrome\n");
        printf("d. Display\n");
        printf("e. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                printf("Popped element: %d\n", pop());
                break;
            case 3:
                checkPalindrome();
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
