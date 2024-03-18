#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 100

int adjMatrix[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];

void createGraph(int n) {
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
}

void DFS(int city, int n) {
    printf("%d ", city);
    visited[city] = 1;
    for (int i = 0; i < n; i++) {
        if (adjMatrix[city][i] && !visited[i]) {
            DFS(i, n);
        }
    }
}

void BFS(int city, int n) {
    int queue[MAX_CITIES], front = 0, rear = 0;
    printf("%d ", city);
    visited[city] = 1;
    queue[rear++] = city;
    while (front < rear) {
        int currCity = queue[front++];
        for (int i = 0; i < n; i++) {
            if (adjMatrix[currCity][i] && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int n, startCity;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    createGraph(n);
    printf("Enter the starting city: ");
    scanf("%d", &startCity);
    printf("DFS traversal from city %d: ", startCity);
    DFS(startCity, n);
    printf("\n");
    for (int i = 0; i < n; i++) visited[i] = 0; // Reset visited array
    printf("BFS traversal from city %d: ", startCity);
    BFS(startCity, n);
    printf("\n");
    return 0;
}
