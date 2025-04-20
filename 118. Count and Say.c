#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    if (n == 1) {
        char* base = (char*)malloc(2);
        strcpy(base, "1");
        return base;
    }

    char* prev = (char*)malloc(2);
    strcpy(prev, "1");

    for (int i = 2; i <= n; ++i) {
        int len = strlen(prev);
        char* curr = (char*)malloc(len * 2 + 1); // Allocating enough space
        int index = 0;
        for (int j = 0; j < len;) {
            char digit = prev[j];
            int count = 0;
            while (j < len && prev[j] == digit) {
                ++count;
                ++j;
            }
            index += sprintf(curr + index, "%d%c", count, digit);
        }
        free(prev);  // Free the previous string
        prev = curr; // Move to the new string
    }

    return prev;
}
