#include <stdio.h>
#include <stdlib.h>

int *ht, m, count = 0;

void insert(int key) {
    if (count == m) {
        printf("\nHash Table Full."); return;
    }
    int idx = key % m;
    while (ht[idx] != -1) {
        idx = (idx + 1) % m; // Linear Probing
    }
    ht[idx] = key;
    count++;
}

void display() {
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < m; i++) {
        if (ht[i] != -1) printf("T[%d] --> %d\n", i, ht[i]);
        else printf("T[%d] --> -1\n", i);
    }
}

int main() {
    int n, key, i;
    printf("Enter number of records (N): "); scanf("%d", &n);
    printf("Enter hash table size (m): "); scanf("%d", &m);
    
    ht = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) ht[i] = -1; // Init table

    printf("Enter keys:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}