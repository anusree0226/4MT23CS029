#include <stdio.h>
#include <limits.h>

#define N 15
#define INF INT_MAX

void dijkstra(int g[N][N], int src) {
    int d[N];
    for (int i = 0; i < N; i++) d[i] = INF;
    d[src] = 0;
    
    for (int i = 0; i < N - 1; i++) {
        int u = -1;
        for (int j = 0; j < N; j++)
            if (d[j] < INF && (u == -1 || d[j] < d[u])) u = j;
        if (u == -1) break;
        
        for (int v = 0; v < N; v++)
            if (g[u][v] && d[u] + g[u][v] < d[v]) d[v] = d[u] + g[u][v];
    }
    
    printf("Warehouse %d:\n", src + 1);
    for (int i = 5; i < N; i++)
        printf("To %d: %d\n", i - 4, d[i]);
}

int main() {
    int g[N][N] = {{0, 10, 20, 0, 0, 50},
                    {10, 0, 30, 0, 0, 40},
                    {20, 30, 0, 10, 0, 0},
                    {0, 0, 10, 0, 15, 0},
                    {0, 0, 0, 15, 0, 0},
                    {50, 40, 0, 0, 0, 0}};
    
    for (int i = 0; i < 5; i++) dijkstra(g, i);
    return 0;
}
