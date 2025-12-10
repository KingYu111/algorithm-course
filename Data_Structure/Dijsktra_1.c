#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000
#define MAXN 100

int graph[MAXN][MAXN];   // 邻接矩阵
int dist[MAXN];          // 最短距离
int parent[MAXN];        // 路径恢复
int visited[MAXN];       // 是否访问过


// -------------------------------
// 无向图加边函数
// -------------------------------
void addEdge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;   // 无向图：双向
}


// -------------------------------
// Dijkstra 邻接矩阵 O(V^2)
// -------------------------------
void dijkstra(int n, int start)
{
    int i, j, k;

    // 初始化
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }

    dist[start] = 0;

    // 总共找 n 次
    for (k = 0; k < n; k++) {

        // 1. 找 dist 最小的未访问点 u
        int u = -1;
        int MIN = INF;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < MIN) {
                MIN = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // 剩下全不可达
        visited[u] = 1;

        // 2. 用 u 松弛所有邻居 v
        for (j = 0; j < n; j++) {
            if (graph[u][j] < INF) { // 表示有边
                if (!visited[j] && dist[j] > dist[u] + graph[u][j]) {
                    dist[j] = dist[u] + graph[u][j];
                    parent[j] = u;
                }
            }
        }
    }
}


// -------------------------------
// 路径恢复：把路径放入 path[]
// 返回路径长度
// -------------------------------
int getPath(int end, int *path)
{
    int len = 0;
    int v = end;

    while (v != -1) {
        path[len++] = v;
        v = parent[v];
    }

    // 反转
    for (int i = 0; i < len / 2; i++) {
        int tmp = path[i];
        path[i] = path[len - 1 - i];
        path[len - 1 - i] = tmp;
    }

    return len;
}


// -------------------------------
// 主函数
// -------------------------------
int main()
{
    // 节点编号：A=0, B=1, C=2, D=3, E=4
    int n = 5;

    // 初始化邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j ? 0 : INF);
        }
    }

    // 无向图建边
    addEdge(0, 1, 2);  // A-B
    addEdge(0, 2, 5);  // A-C
    addEdge(1, 3, 4);  // B-D
    addEdge(2, 3, 1);  // C-D
    addEdge(3, 4, 3);  // D-E

    // 从 A (0) 出发
    dijkstra(n, 0);

    int target = 4; // 目标：E

    printf("Shortest distance A->E: %d\n", dist[target]);

    int path[100];
    int len = getPath(target, path);

    printf("Path: ");
    for (int i = 0; i < len; i++) {
        printf("%c ", 'A' + path[i]);
    }
    printf("\n");

    return 0;
}
