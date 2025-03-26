#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int m = gridSize, n = gridColSize[0];
    int size = m * n;
    int* arr = (int*)malloc(size * sizeof(int));
    if (!arr) return -1;

    // Flatten the grid into a 1D array
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[index++] = grid[i][j];
        }
    }

    // Check if all elements are transformable
    for (int i = 1; i < size; i++) {
        if ((arr[i] - arr[0]) % x != 0) {
            free(arr);
            return -1;
        }
    }

    // Sort the array
    qsort(arr, size, sizeof(int), compare);

    // Find the median element
    int median = arr[size / 2];
    int operations = 0;

    // Compute the number of operations needed
    for (int i = 0; i < size; i++) {
        operations += abs(arr[i] - median) / x;
    }

    free(arr);
    return operations;
}
