#define MAXN 100005

typedef long long ll;

int bit[MAXN];

void update(int index, int value, int n) {
    index++;
    while (index <= n) {
        bit[index] += value;
        index += index & -index;
    }
}

int query(int index) {
    index++;
    int res = 0;
    while (index > 0) {
        res += bit[index];
        index -= index & -index;
    }
    return res;
}

void clearBIT(int n) {
    for (int i = 0; i <= n + 1; i++) {
        bit[i] = 0;
    }
}

long long goodTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size;
    int pos2[MAXN];
    
    for (int i = 0; i < n; i++) {
        pos2[nums2[i]] = i;
    }

    int transformed[MAXN];
    for (int i = 0; i < n; i++) {
        transformed[i] = pos2[nums1[i]];
    }

    int* leftCount = (int*)calloc(n, sizeof(int));
    int* rightCount = (int*)calloc(n, sizeof(int));

    // Left to right: count of elements less than current
    clearBIT(n);
    for (int i = 0; i < n; i++) {
        leftCount[i] = query(transformed[i] - 1);
        update(transformed[i], 1, n);
    }

    // Right to left: count of elements greater than current
    clearBIT(n);
    for (int i = n - 1; i >= 0; i--) {
        rightCount[i] = query(n - 1) - query(transformed[i]);
        update(transformed[i], 1, n);
    }

    ll result = 0;
    for (int i = 0; i < n; i++) {
        result += (ll)leftCount[i] * rightCount[i];
    }

    free(leftCount);
    free(rightCount);

    return result;
}
