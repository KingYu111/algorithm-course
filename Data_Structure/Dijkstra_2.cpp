//有向图
//时间复杂度O(V^2)
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cstring>
using namespace std;

#define Max_VertexNum 100
typedef char VertexType;
typedef int EdgeType;

// 边表节点
typedef struct EdgeNode {
    int adjvex;
    int weight;
    EdgeNode* next;
} EdgeNode;

// 顶点节点
typedef struct VertexNode {
    VertexType data;
    EdgeNode* firstedge;
} VertexNode;

typedef VertexNode AdjList[Max_VertexNum];

typedef struct ALGraph {
    AdjList adjlist;
    int n, e;
} ALGraph;

// 创建图（手动输入）
void CreateGraphAL(ALGraph* G)
{
    cout << "请输入顶点数 n 和边数 e:\n";
    cin >> G->n >> G->e;

    cout << "请输入每个顶点的字符名称，例如 A B C D:\n";
    for (int i = 0; i < G->n; i++) {
        cin >> G->adjlist[i].data;
        G->adjlist[i].firstedge = NULL;
    }

    cout << "请输入每条边: 起点 终点 权值(如 A B 4 )\n";
    for (int k = 0; k < G->e; k++) {
        char a, b;
        int w;
        cin >> a >> b >> w;

        int i, j;
        for (i = 0; i < G->n; i++)
            if (G->adjlist[i].data == a) break;
        for (j = 0; j < G->n; j++)
            if (G->adjlist[j].data == b) break;

        // 插入边 i -> j
        EdgeNode* p = new EdgeNode;
        p->adjvex = j;
        p->weight = w;
        p->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge = p;

        // 若是无向图，还要插入 j -> i（如需要可加）
        // 本例默认是有向图，不加
    }
}

// 打印邻接表
void PrintfGraphAL(ALGraph* G)
{
    cout << "\n图的邻接表:\n";
    for (int i = 0; i < G->n; i++) {
        cout << G->adjlist[i].data << ": ";
        EdgeNode* p = G->adjlist[i].firstedge;
        while (p) {
            cout << "(" << G->adjlist[p->adjvex].data
                 << ", w=" << p->weight << ") ";
            p = p->next;
        }
        cout << endl;
    }
}

// Dijkstra
void Dijkstra(ALGraph* G, int src, int dest)
{
    int n = G->n;
    const int INF = (int)1e9;

    vector<int> dist(n, INF);
    vector<int> prev(n, -1);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int k = 0; k < n; k++) {
        int u = -1;
        int best = INF;

        // 找当前未访问最小 dist
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        // 松弛邻居
        EdgeNode* p = G->adjlist[u].firstedge;
        while (p) {
            int v = p->adjvex;
            int w = p->weight;
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
            p = p->next;
        }
    }

    // 输出结果
    if (dist[dest] == INF) {
        cout << "\n源点无法到达终点\n";
        return;
    }

    cout << "\n最短路径长度 = " << dist[dest] << endl;

    // 回溯路径
    vector<int> path;
    for (int cur = dest; cur != -1; cur = prev[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << "最短路径：";
    for (int i = 0; i < path.size(); i++) {
        cout << G->adjlist[path[i]].data;
        if (i + 1 < path.size()) cout << " -> ";
    }
    cout << endl;
}


int main()
{
    system("chcp 65001 > nul");
    ALGraph G;
    CreateGraphAL(&G);
    PrintfGraphAL(&G);

    cout << "\n请输入源点字符和终点字符（如 A E）:\n";
    char s, t;
    cin >> s >> t;

    int src = -1, dest = -1;
    for (int i = 0; i < G.n; i++) {
        if (G.adjlist[i].data == s) src = i;
        if (G.adjlist[i].data == t) dest = i;
    }

    if (src == -1 || dest == -1) {
        cout << "顶点不存在！\n";
        return 0;
    }

    Dijkstra(&G, src, dest);

    return 0;
}
