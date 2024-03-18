#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = element;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate a suffix expression
int evaluateSuffixExpression(char *suffix) {
    int i = 0, operand1, operand2, result;
    char ch;

    while ((ch = suffix[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            operand2 = pop();
            operand1 = pop();
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '%':
                    result = operand1 % operand2;
                    break;
                case '^':
                    result = 1;
                    for (int i = 0; i < operand2; i++)
                        result *= operand1;
                    break;
                default:
                    printf("Invalid operator!\n");
                    exit(1);
            }
            push(result);
        }
    }
    return pop();
}

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    char suffix[MAX];
    int result;

    printf("Enter the suffix expression: ");
    scanf("%s", suffix);

    result = evaluateSuffixExpression(suffix);
    printf("Result: %d\n", result);

    printf("\nTower of Hanoi Solution for 3 disks:\n");
    towerOfHanoi(3, 'A', 'B', 'C');

    return 0;
}
