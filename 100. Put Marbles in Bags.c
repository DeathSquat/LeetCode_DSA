#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long putMarbles(int* weights, int weightsSize, int k) {
    if (k == 1) return 0;

    int n = weightsSize;
    long long maxScore = 0, minScore = 0;

    int* pairSums = (int*)malloc((n - 1) * sizeof(int));
    for (int i = 0; i < n - 1; i++) {
        pairSums[i] = weights[i] + weights[i + 1];
    }

    qsort(pairSums, n - 1, sizeof(int), cmp);

    for (int i = 0; i < k - 1; i++) {
        minScore += pairSums[i];
        maxScore += pairSums[n - 2 - i];
    }

    free(pairSums);
    return maxScore - minScore;
}
