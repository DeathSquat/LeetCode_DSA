#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007
#define INF LLONG_MAX  // Define infinite distance as long long max

typedef struct {
    int node;
    long long time;  // Use long long for time to prevent overflow
} Pair;

typedef struct {
    Pair *heap;
    int size;
} MinHeap;

// Min-Heap functions
MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->heap = (Pair*)malloc(capacity * sizeof(Pair));
    minHeap->size = 0;
    return minHeap;
}

void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < minHeap->size && minHeap->heap[left].time < minHeap->heap[smallest].time)
        smallest = left;
    if (right < minHeap->size && minHeap->heap[right].time < minHeap->heap[smallest].time)
        smallest = right;
    if (smallest != i) {
        swap(&minHeap->heap[i], &minHeap->heap[smallest]);
        minHeapify(minHeap, smallest);
    }
}

Pair extractMin(MinHeap *minHeap) {
    Pair root = minHeap->heap[0];
    minHeap->heap[0] = minHeap->heap[--minHeap->size];
    minHeapify(minHeap, 0);
    return root;
}

void insertMinHeap(MinHeap *minHeap, int node, long long time) {
    int i = minHeap->size++;
    minHeap->heap[i].node = node;
    minHeap->heap[i].time = time;
    while (i && minHeap->heap[i].time < minHeap->heap[(i - 1) / 2].time) {
        swap(&minHeap->heap[i], &minHeap->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Graph adjacency list
typedef struct Node {
    int dest;
    long long weight;  // Use long long for weight to prevent overflow
    struct Node *next;
} Node;

typedef struct {
    Node **adj;
} Graph;

Graph* createGraph(int n) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->adj = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) graph->adj[i] = NULL;
    return graph;
}

void addEdge(Graph *graph, int u, int v, long long w) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v, newNode->weight = w, newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
    
    newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = u, newNode->weight = w, newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

// Function to count paths
int countPaths(int n, int** roads, int roadsSize, int* roadsColSize) {
    Graph *graph = createGraph(n);
    for (int i = 0; i < roadsSize; i++)
        addEdge(graph, roads[i][0], roads[i][1], roads[i][2]);

    long long *dist = (long long*)malloc(n * sizeof(long long));
    int *ways = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = INF;  // Set all distances to INF
        ways[i] = 0;
    }

    MinHeap *minHeap = createMinHeap(n);
    insertMinHeap(minHeap, 0, 0);
    dist[0] = 0;
    ways[0] = 1;

    while (minHeap->size) {
        Pair curr = extractMin(minHeap);
        int u = curr.node;
        long long timeU = curr.time;

        // If the extracted distance is greater than the stored shortest path, ignore it
        if (timeU > dist[u]) continue;

        Node *temp = graph->adj[u];
        while (temp) {
            int v = temp->dest;
            long long timeV = temp->weight;
            long long newDist = timeU + timeV;  // Use long long to prevent overflow

            if (newDist < dist[v]) {
                dist[v] = newDist;
                ways[v] = ways[u];
                insertMinHeap(minHeap, v, newDist);
            } else if (newDist == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
            temp = temp->next;
        }
    }

    int result = ways[n - 1];
    
    free(dist);
    free(ways);
    free(minHeap->heap);
    free(minHeap);
    for (int i = 0; i < n; i++) {
        Node *temp = graph->adj[i];
        while (temp) {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adj);
    free(graph);
    
    return result;
}
