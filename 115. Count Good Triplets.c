#include <stdlib.h>

int absDiff(int x, int y) {
    return x > y ? x - y : y - x;
}

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int count = 0;
    
    for (int i = 0; i < arrSize - 2; i++) {
        for (int j = i + 1; j < arrSize - 1; j++) {
            if (absDiff(arr[i], arr[j]) <= a) {
                for (int k = j + 1; k < arrSize; k++) {
                    if (absDiff(arr[j], arr[k]) <= b && absDiff(arr[i], arr[k]) <= c) {
                        count++;
                    }
                }
            }
        }
    }
    
    return count;
}
