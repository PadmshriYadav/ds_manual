#include <stdio.h>
#include <stdlib.h>

int a[20][20], vis[20], n;

void bfs(int v) {
    int q[20], f = 0, r = 0, cur, i;
    vis[v] = 1;
    q[r++] = v;
    while (f < r) {
        cur = q[f++];
        printf("%d ", cur);
        for (i = 1; i <= n; i++) {
            if (a[cur][i] && !vis[i]) {
                vis[i] = 1;
                q[r++] = i;
            }
        }
    }
}

void dfs(int v) {
    int i;
    vis[v] = 1;
    printf("%d ", v);
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !vis[i])
            dfs(i);
    }
}

int main() {
    int ch, start, i, j;
    printf("Enter num vertices: ");
    scanf("%d", &n);
    printf("Enter Adj Matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    while(1) {
        for(i=1; i<=n; i++) vis[i]=0; // Reset visited
        printf("\n1.BFS 2.DFS 3.Exit: ");
        scanf("%d", &ch);
        if(ch==3) exit(0);
        printf("Enter start node: ");
        scanf("%d", &start);
        printf("Nodes reachable: ");
        if(ch==1) bfs(start);
        else dfs(start);
    }
}