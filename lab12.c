
#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define MAX_HT_SIZE 50

struct Employee {
    int key;
    // Other employee details
};

int hash(int key, int m) {
    return key % m;
}

int linearProbe(int HT[], int key, int m) {
    int index = hash(key, m);
    while (HT[index] != -1) {
        index = (index + 1) % m;
    }
    return index;
}

void insert(int HT[], int key, int m) {
    int index = linearProbe(HT, key, m);
    HT[index] = key;
}

int main() {
    int m, n;
    printf("Enter the number of memory locations in the hash table: ");
    scanf("%d", &m);
    printf("Enter the number of employee records: ");
    scanf("%d", &n);

    int HT[MAX_HT_SIZE];
    for (int i = 0; i < m; i++) {
        HT[i] = -1; // Initialize hash table with -1 (indicating empty)
    }

    printf("Enter %d employee keys:\n", n);
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insert(HT, key, m);
    }

    printf("Hash Table:\n");
    for (int i = 0; i < m; i++) {
        printf("HT[%d] -> %d\n", i, HT[i]);
    }

    return 0;
}
