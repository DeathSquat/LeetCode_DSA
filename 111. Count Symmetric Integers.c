#include <stdio.h>
#include <string.h>

int countSymmetricIntegers(int low, int high) {
    int count = 0;
    char s[10];

    for (int num = low; num <= high; num++) {
        sprintf(s, "%d", num);
        int len = strlen(s);

        // Skip numbers with odd number of digits
        if (len % 2 != 0) continue;

        int half = len / 2;
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < half; i++) {
            sum1 += s[i] - '0';
        }

        for (int i = half; i < len; i++) {
            sum2 += s[i] - '0';
        }

        if (sum1 == sum2) {
            count++;
        }
    }

    return count;
}
