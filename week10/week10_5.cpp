//Kruskal算法
#include <iostream>
using namespace std;

const int MAXVEX = 100;
const int MAXEDGE = 100;

typedef struct
{
    int begin;
    int end;
    int weight;
    bool selected;
}Edge;

void Init(Edge* edges, int &n, int* parent, int* mstRank);
int Kruskal(Edge* edges, int n, int* parent, int* mstRank);
int FindSet(int x, int* parent);
void UnionSet(int x, int y, int weight, int &sum, int* mstRank, int* parent);
void Sort(Edge* edge, int n);

int main()
{
    Edge edges[MAXEDGE];    //存储边的数组
    int parent[MAXVEX];     //用于寻找根节点的数组
    int mstRank[MAXVEX];    //用于记录每个集合的高度，初始化为 0
    int n;                  //边的总数
    int sum;                //最小生成树的权值和

    Init(edges, n, parent, mstRank);

    sum = Kruskal(edges, n, parent, mstRank);
    cout << "最小生成树权值和为: " << sum << endl;
    
    for(int i = 1; i <= n; i++)
    {
        if(edges[i].selected)
        {
            cout << edges[i].begin << "-" << edges[i].end << endl;
        }
    }
    
    return 0;
}

void Init(Edge* edges, int &n, int* parent, int* mstRank)
{
    for(int i = 0; i < MAXVEX; i++)
    {
        parent[i] = i;
        mstRank[i] = 0;
    }

    //输入边的总数
    cin >> n;
    //初始化边的集合
    for(int i = 1; i <= n; i++)
    {
        cin >> edges[i].begin >> edges[i].end >> edges[i].weight;
        edges[i].selected = false;
        parent[edges[i].begin] = edges[i].begin;
        parent[edges[i].end] = edges[i].end;
        mstRank[edges[i].begin] = 0;
        mstRank[edges[i].end] = 0;
    }

    //对所有边按权值排序
    Sort(edges, n);
}


int Kruskal(Edge* edges, int n, int* parent, int* mstRank)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        x = FindSet(edges[i].begin, parent);
        y = FindSet(edges[i].end, parent);
        if(x != y)
        {
            edges[i].selected = true;
            UnionSet(x, y, edges[i].weight, sum, mstRank, parent);
        }
    }
    return sum;
}

int FindSet(int x, int* parent)
{
    if(parent[x] != x)
    {
        parent[x] = FindSet(parent[x], parent);
    }

    return parent[x];
}

void UnionSet(int x, int y, int weight ,int &sum, int* mstrank, int* parent)
{
    if(mstrank[x] > mstrank[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
        if(mstrank[x] == mstrank[y])
        {
            mstrank[y]++;
        }
    }
    sum += weight;
}

void Sort(Edge* edge, int n)
{
    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 1; j <= n - i; j++)
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
