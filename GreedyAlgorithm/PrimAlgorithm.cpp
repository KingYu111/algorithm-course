// Prim算法
#include <iostream>

using namespace std;

#define MAXVEX 100
#define INF 2147483647

typedef char DataType;

typedef struct EdgeNode
{
    int adjvex;
    int weight;
    EdgeNode* next;
}EdgeNode;

typedef struct VertexNode
{
    DataType data;
    EdgeNode* firstedge;
}VertexNode;

typedef VertexNode AdjList[MAXVEX];

typedef struct ALGraph
{
    AdjList adjlist;
    int n,e;
}ALGraph;

ALGraph* CreateALGraph()
{
    ALGraph* G = new ALGraph;

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

int MST(ALGraph* G, int* parent, int startVex)
{
    int sum = 0;
    int n = G->n;

    bool included[MAXVEX];
    int externalMinimal[MAXVEX];

    for(int i=0;i<n;i++)
    {
        included[i] = false;
        externalMinimal[i] = INF;
        parent[i] = -1;
    }

    included[startVex] = true;
    externalMinimal[startVex] = 0;

    EdgeNode* p =G->adjlist[startVex].firstedge;
    while(p!=NULL)
    {
        externalMinimal[p->adjvex] = p->weight;
        parent[p->adjvex] = startVex;
        p = p->next;
    }

    int minWeight;
    int minExternalVex;

    for(int i=0;i<n;i++)
    {
        minWeight = INF;
        minExternalVex = -1;

        for(int j=0;j<n;j++)
        {
            if(!included[j] && externalMinimal[j]<minWeight)
            {
                minWeight = externalMinimal[j];
                minExternalVex = j;
            }
        }

        if(minExternalVex == -1 || minWeight == INF)
        {
            break;
        }

        included[minExternalVex] = true;
        sum +=minWeight;

        p = G->adjlist[minExternalVex].firstedge;
        while(p!=NULL)
        {
            if(!included[p->adjvex] && p->weight<externalMinimal[p->adjvex])
            {
                externalMinimal[p->adjvex] = p->weight;
                parent[p->adjvex] = minExternalVex;
            }
            p = p->next;
        }
    }

    return sum;
}

void Traceback(ALGraph* G, int* parent)
{
    for(int i=0;i<G->n;i++)
    {
        if(parent[i] != -1)
        cout << parent[i] << "->" << i << endl;
    }
}

int main()
{
    ALGraph* G = CreateALGraph();
    int parent[MAXVEX];
    int sum = MST(G,parent,0);
    cout << "The sum of the minimal spanning tree is: " << sum << endl;
    Traceback(G,parent);
    return 0;
}

