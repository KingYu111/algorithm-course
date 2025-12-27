#include <iostream>
using namespace std;

#define MAX_VERTEX_NUM 100

typedef char DataType; 

typedef struct EdgeNode
{
    int adjvex;
    int weight;
    EdgeNode* next;
} EdgeNode;

typedef struct VertexNode
{
    DataType data;
    EdgeNode* firstedge;
}VertexNode;

typedef VertexNode AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph
{
    AdjList adjlist;
    int n,e;
}ALGraph;

ALGraph* CreateALGraph();
void DFS(ALGraph* G, int i, bool visited[]);
void DFSTraverse(ALGraph* G);

int main()
{
    ALGraph* G = CreateALGraph();
    DFSTraverse(G);
    return 0;
}

ALGraph* CreateALGraph()
{
    int n,e;
    cin >> n >> e;
    ALGraph* G = new ALGraph;
    G->n = n;
    G->e = e;
    for(int i = 0;i<n;i++)
    {
        cin >> G->adjlist[i].data;
        G->adjlist[i].firstedge = NULL;
    }

    for(int i=0;i<e;i++)
    {
        int v1,v2,w;
        cin >> v1 >> v2 >> w;

        EdgeNode* e1 = new EdgeNode;
        e1->adjvex = v2;
        e1->weight = w;
        e1->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge = e1;

        EdgeNode* e2 = new EdgeNode;
        e2->adjvex = v1;
        e2->weight = w;
        e2->next = G->adjlist[v2].firstedge;
        G->adjlist[v2].firstedge = e2;
    }

    return G;
}

void DFS(ALGraph* G, int i, bool visited[])
{
    visited[i] = true;

    cout << "visit " << G->adjlist[i].data << endl;

    EdgeNode* p = G->adjlist[i].firstedge;

    while(p)
    {
        if(!visited[p->adjvex] && p->weight != 0)
        {
            DFS(G, p->adjvex, visited);
        }
        p = p->next;
    }
}

void DFSTraverse(ALGraph* G)
{
    bool visited[MAX_VERTEX_NUM];

    for(int i=0;i<G->n;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<G->n;i++)
    {
        if(!visited[i])
        {
            DFS(G, i, visited);
        }
    }
}