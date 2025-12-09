//无向图
//时间复杂度O(V^2)
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;

// -------------------------------
// Dijkstra 邻接矩阵 + 路径恢复
// -------------------------------
void dijkstra(int n, int start, vector<vector<int>>& graph,
              vector<int>& dist, vector<int>& parent)
{
    vector<bool> visited(n, false);
    dist.assign(n, INF);
    parent.assign(n, -1);

    // 起点
    dist[start] = 0;

    // 进行 n 次
    for (int k = 0; k < n; k++) {
        // 1. 找 dist 最小的未访问点 u
        int u = -1;
        int MIN = INF;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < MIN) {
                MIN = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // 所有连通点处理完
        visited[u] = true;

        // 2. 用 u 松弛所有邻居 v
        for (int v = 0; v < n; v++) {
            if (graph[u][v] < INF) { // 有边
                if (!visited[v] && dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

// -------------------------------
// 路径恢复
// -------------------------------
vector<int> getPath(int end, vector<int>& parent)
{
    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

// -------------------------------
// 主函数
// -------------------------------
int main() {
    // 节点编号：A=0, B=1, C=2, D=3, E=4
    int n = 5;

    // 初始化图矩阵
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) graph[i][i] = 0;

    // 无向图 addEdge
    auto addEdge = [&](int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;
    };

    // 构造示例图
    // A-B (2), A-C (5), B-D (4), C-D (1), D-E (3)
    addEdge(0,1,2);
    addEdge(0,2,5);
    addEdge(1,3,4);
    addEdge(2,3,1);
    addEdge(3,4,3);

    vector<int> dist, parent;
    dijkstra(n, 0, graph, dist, parent); // 从 A(0) 出发

    int target = 4; // E(4)

    // 输出最短距离
    cout << "Shortest distance: " << dist[target] << endl;

    // 输出最短路径
    vector<int> path = getPath(target, parent);
    cout << "Path: ";
    for (int x : path) cout << char('A' + x) << " ";
    cout << endl;

    return 0;
}



