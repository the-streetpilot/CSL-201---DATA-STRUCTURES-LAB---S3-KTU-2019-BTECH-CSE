#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 5  // Number of vertices

// Function to perform BFS
void BFS(int matrix[V][V], int start) {
    bool visited[V] = {false};
    int queue[V];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS starting from vertex %d:\n", start);

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < V; i++) {
            if (matrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int matrix[V][V] = { {0, 1, 0, 0, 1},
                         {1, 0, 1, 0, 1},
                         {0, 1, 0, 1, 0},
                         {0, 0, 1, 0, 1},
                         {1, 1, 0, 1, 0} };

    BFS(matrix, 0);  // Start BFS from vertex 0

    return 0;
}
