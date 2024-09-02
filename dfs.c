#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices

// Function to perform DFS
void DFSUtil(int matrix[V][V], int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++) {
        if (matrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(matrix, i, visited);
        }
    }
}

void DFS(int matrix[V][V], int start) {
    bool visited[V] = {false};
    printf("DFS starting from vertex %d:\n", start);
    DFSUtil(matrix, start, visited);
    printf("\n");
}

// Main function
int main() {
    int matrix[V][V] = { {0, 1, 0, 0, 1},
                         {1, 0, 1, 0, 1},
                         {0, 1, 0, 1, 0},
                         {0, 0, 1, 0, 1},
                         {1, 1, 0, 1, 0} };

    DFS(matrix, 0);  // Start DFS from vertex 0

    return 0;
}

