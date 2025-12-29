// Kruskal算法
// 不用建图，直接排序即可
#include <iostream>
using namespace std;

#define MAXEDGE 100
#define MAXVEX 100

typedef struct Edge
{
    int begin,end;
    int weight;
    bool selected;
}Edge;

void Init(Edge* edge, int &n, int* parent, int* mstRank);
void Sort(Edge* edge, int n);
int Kruskal(Edge* edge, int n, int* parent, int* mstRank);
int FindSet(int x, int* parent);
void UnionSet(int x, int y, int weight, int &sum, int* mstRank, int* parent);

int main()
{
    Edge edge[MAXEDGE];
    int parent[MAXVEX];
    int mstRank[MAXVEX];
    int n;
    int sum = 0;

    cin >> n;

    Init(edge, n, parent, mstRank);

    sum = Kruskal(edge, n, parent, mstRank);
    cout << "最小生成树权值和为: " << sum << endl;
    
    for(int i=1;i<=n;i++)
    {
        if(edge[i].selected)
        {
            cout << edge[i].begin << "-" << edge[i].end << endl;
        }
    }

    return 0;
}

void Init(Edge* edge, int &n, int* parent, int* mstRank)
{
    for(int i = 0; i < MAXVEX; i++)
    {
        parent[i] = i;
        mstRank[i] = 0;
    }

    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> edge[i].begin >> edge[i].end >> edge[i].weight;
        edge[i].selected = false;
    }
    
    Sort(edge, n);
}

void Sort(Edge* edge, int n)
{
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(edge[j].weight > edge[j+1].weight)
            {
                Edge temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
            }
        }
    }
}

int FindSet(int x, int* parent)
{
    if(parent[x] != x)
    {
        parent[x] = FindSet(parent[x], parent);
    }
    return parent[x];
}

void UnionSet(int x, int y, int weight, int &sum, int* mstRank, int* parent)
{
    if(mstRank[x] > mstRank[y])
    {
        parent[y] = x;
    }
    else 
    {
        parent[x] = y;
        if(mstRank[x] == mstRank[y])
        {
            mstRank[y]++;
        }
    }

    sum +=weight;
}

int Kruskal(Edge* edge, int n, int* parent, int* mstRank)
{
    int sum = 0;

    for(int i=1;i<=n;i++)
    {
        int xRoot = FindSet(edge[i].begin, parent);
        int yRoot = FindSet(edge[i].end, parent);
        if(xRoot != yRoot)
        {
            UnionSet(xRoot, yRoot, edge[i].weight, sum ,mstRank, parent);
            edge[i].selected = true;
        }
    }

    return sum;
}