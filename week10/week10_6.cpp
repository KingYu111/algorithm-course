/*
【Prim算法】设U为生成树顶点的集合，初始状态仅包含起点u0

1.       从含权连通图的某一顶点 u0 出发，选择与它关联的具有最小权值的边（u0,v），将其顶点 v 加入到生成树的顶点集合U中，同时记录边（u0,v）为生成树的一部分

2.       从一个顶点在U中（记作u），而另一个顶点不在U中（记作v）的各条边中选择权值最小的边（u,v），把顶点 v 加入集合U，同时记录边（u,v）为生成树的一部分

3.       将上面步骤反复作下去，直到图中的所有顶点都加入到生成树顶点集合U中
*/
#include <iostream>
using namespace std;

#define MaxVertexNum 100
#define INF 65535


typedef struct EdgeNode
{
    int adjvex;//指向的结点
    int weight;//边的权值
    EdgeNode *next;
} EdgeNode;

typedef struct VertexNode
{
    int data;//顶点信息
    EdgeNode *firstedge;//指向第一条边
} VertexNode;

typedef VertexNode AdjList[MaxVertexNum];

typedef struct ALGraph
{
    AdjList adjlist;
    int n,e;
} ALGraph;

void CreateALGraph(ALGraph *G)
{
    cin >> G->n >> G->e;

    for(int i=0;i<G->n;i++)
    {
        cin >> G->adjlist[i].data;
        G->adjlist[i].firstedge = NULL;
    }

    for(int i=0;i<G->e;i++)
    {
        int v1,v2,w;
        cin >> v1 >> v2 >> w;

        EdgeNode *e1 = new EdgeNode;
        e1->adjvex = v2;
        e1->weight = w;
        e1->next = G->adjlist[v1].firstedge;
        G->adjlist[v1].firstedge = e1;

        EdgeNode *e2 = new EdgeNode;
        e2->adjvex = v1;
        e2->weight = w;
        e2->next = G->adjlist[v2].firstedge;
        G->adjlist[v2].firstedge = e2;
    }
}

int CreateMST(ALGraph *G, int startVex, int* parent)
{
    int n = G->n;
    int sum = 0;

    bool included[MaxVertexNum];
    int externalminimal[MaxVertexNum];// 包含集合旁边一圈的最小的权值，如果是INFINITY，说明这个顶点不在包含集合旁边一圈

    for(int i=0;i<n;i++)
    {
        included[i] = false;
        externalminimal[i] = INF;
        parent[i] = -1;
    }

    included[startVex] = true;
    externalminimal[startVex] = -1;

    EdgeNode *p = G->adjlist[startVex].firstedge;
    while(p!=NULL)
    {
        externalminimal[p->adjvex] = p->weight;
        parent[p->adjvex] = startVex;
        p = p->next;
    }

    int minWeight;
    int minVex; //记录最小边在最小生成树外的顶点

    for(int i= 0;i<n;i++)
    {
        minWeight = INF;
        minVex = -1;
        for(int j = 0;j<n;j++)
        {
            if(!included[j] && externalminimal[j] < minWeight)
            {
                minWeight = externalminimal[j];
                minVex = j;
            }
        }

        if(minVex == -1 || minWeight == INF)
        {
            break;
        }

        included[minVex] = true;
        sum += minWeight;

        p = G->adjlist[minVex].firstedge;
        
        while(p!=NULL)
        {
            if(!included[p->adjvex] && externalminimal[p->adjvex] > p->weight)
            {
                externalminimal[p->adjvex] = p->weight;
                parent[p->adjvex] = minVex;
            }
            p = p->next;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(i == startVex || !included[i])
        {
            parent[i] = -1;
        }
    }

    return sum;
}

int main()
{
    ALGraph G;
    CreateALGraph(&G);
    int parent[MaxVertexNum];
    int sum = CreateMST(&G, 0, parent);
    cout << sum << endl;
    for(int i=0;i<G.n;i++)
    {
        if(parent[i] != -1)
        {
            cout << parent[i] << " -> " << i << endl;
        }
    }
    
    return 0;

}

