#include <stdlib.h>
#include <string.h>

#define MAX_HASH_SIZE 200005

typedef struct HashNode {
    int key;
    int count;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[MAX_HASH_SIZE];

unsigned int hash(int key) {
    return ((unsigned int)key) % MAX_HASH_SIZE;
}

void clearHashTable() {
    for (int i = 0; i < MAX_HASH_SIZE; ++i) {
        HashNode* node = hashTable[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int getAndUpdate(int key, int delta) {
    unsigned int index = hash(key);
    HashNode* node = hashTable[index];
    while (node) {
        if (node->key == key) {
            int oldCount = node->count;
            node->count += delta;
            return oldCount;
        }
        node = node->next;
    }
    // Key not found, insert new
    node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->count = delta;
    node->next = hashTable[index];
    hashTable[index] = node;
    return 0;
}

long long countGood(int* nums, int numsSize, int k) {
    long long result = 0;
    int left = 0;
    long long pairs = 0;

    clearHashTable();  // Clean up before use

    for (int right = 0; right < numsSize; ++right) {
        int countBefore = getAndUpdate(nums[right], 1);
        pairs += countBefore;

        while (pairs >= k) {
            result += numsSize - right;
            int countLeftBefore = getAndUpdate(nums[left], -1);
            pairs -= (countLeftBefore - 1);
            left++;
        }
    }

    clearHashTable();  // Clean up after use
    return result;
}
