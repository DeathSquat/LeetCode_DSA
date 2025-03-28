#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int val, row, col;
} Cell;

typedef struct {
    Cell* heap;
    int size;
} MinHeap;

void swap(Cell* a, Cell* b) {
    Cell temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap->heap[parent].val <= heap->heap[idx].val) break;
        swap(&heap->heap[parent], &heap->heap[idx]);
        idx = parent;
    }
}

void heapifyDown(MinHeap* heap, int idx) {
    int left, right, smallest;
    while (1) {
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        smallest = idx;
        if (left < heap->size && heap->heap[left].val < heap->heap[smallest].val)
            smallest = left;
        if (right < heap->size && heap->heap[right].val < heap->heap[smallest].val)
            smallest = right;
        if (smallest == idx) break;
        swap(&heap->heap[idx], &heap->heap[smallest]);
        idx = smallest;
    }
}

void push(MinHeap* heap, int val, int row, int col) {
    heap->heap[heap->size] = (Cell){val, row, col};
    heapifyUp(heap, heap->size);
    heap->size++;
}

Cell pop(MinHeap* heap) {
    Cell top = heap->heap[0];
    heap->size--;
    heap->heap[0] = heap->heap[heap->size];
    heapifyDown(heap, 0);
    return top;
}

// Comparison function for sorting queries
int compareQueries(const void* a, const void* b) {
    return (*(int(*)[2])a)[0] - (*(int(*)[2])b)[0];
}

int* maxPoints(int** grid, int gridSize, int* gridColSize, int* queries, int queriesSize, int* returnSize) {
    int m = gridSize, n = gridColSize[0];
    int* answer = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    int** visited = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        visited[i] = (int*)calloc(n, sizeof(int));
    }

    // Sort queries with original indices
    int sortedQueries[queriesSize][2];
    for (int i = 0; i < queriesSize; i++) {
        sortedQueries[i][0] = queries[i];
        sortedQueries[i][1] = i;
    }
    qsort(sortedQueries, queriesSize, sizeof(sortedQueries[0]), compareQueries);

    // MinHeap
    MinHeap heap = { (Cell*)malloc(m * n * sizeof(Cell)), 0 };
    
    // BFS Directions
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // Start BFS from (0,0)
    push(&heap, grid[0][0], 0, 0);
    visited[0][0] = 1;
    
    int count = 0, index = 0;
    
    // Process Queries
    for (int i = 0; i < queriesSize; i++) {
        int q = sortedQueries[i][0], idx = sortedQueries[i][1];

        // Expand grid cells whose value is < query
        while (heap.size > 0 && heap.heap[0].val < q) {
            Cell cur = pop(&heap);
            count++;  // New cell counted

            // Explore all 4 directions
            for (int d = 0; d < 4; d++) {
                int nr = cur.row + dr[d], nc = cur.col + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    push(&heap, grid[nr][nc], nr, nc);
                    visited[nr][nc] = 1;
                }
            }
        }
        
        answer[idx] = count;  // Store answer in original order
    }

    // Free allocated memory
    free(heap.heap);
    for (int i = 0; i < m; i++) free(visited[i]);
    free(visited);

    return answer;
}
