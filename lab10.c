#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void traverse(struct Node *root, char type) {
    if (!root) return;
    if (type == 'i') traverse(root->left, type), printf("%d ", root->data), traverse(root->right, type);
    else if (type == 'p') printf("%d ", root->data), traverse(root->left, type), traverse(root->right, type);
    else if (type == 'o') traverse(root->left, type), traverse(root->right, type), printf("%d ", root->data);
}

struct Node* search(struct Node *root, int key) {
    while (root && root->data != key) root = (key < root->data) ? root->left : root->right;
    return root;
}

int main() {
    struct Node *root = NULL;
    int choice, key, nums[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) root = insert(root, nums[i]);

    while (1) {
        printf("\nMenu:\n1. Inorder\n2. Preorder\n3. Postorder\n4. Search\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: traverse(root, 'i'); break;
            case 2: traverse(root, 'p'); break;
            case 3: traverse(root, 'o'); break;
            case 4: printf("Enter element to search: "); scanf("%d", &key); printf(search(root, key) ? "Element found\n" : "Element not found\n"); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
