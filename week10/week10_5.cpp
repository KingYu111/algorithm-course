/*提示如下：
在矩阵中以上排序操作不方便编程，所以定义下面结构体存储边的信息。
typedef  struct
{
        int begin;      // 边的起点
        int end;        // 边的终点
        int weight;     // 边的权重
       bool selected;  // 是否作为最小生成树的边，初值flase
}Edge;  
// 定义存放边的数组
Edge edges[MAXEDGE];   
算法概要
int parent[MAXVEX];  //用于寻找根节点的数组，初始化为 -1
Edge edges[MAXEDGE];     //定义存储边的数组
// 初始化 edges 数组
for (i = 0; i < 顶点数-1; i++)
    for (j = i + 1; j <顶点数-1; j++)
      读入邻接矩阵边的信息到 edges[]
Sort(edges，边数);     // Sort函数为边数组Edge排序
for (i = 0; i < 边数; i++)
{
    n = Find(parent, edges[i].begin);    //找边的起点的根
    m = Find(parent, edges[i].end);      //找边的终点的根
    // 两个顶点不在一棵子树内
    if(n != m)  {  
parent[m] = n;   
设置边i的selected为true; 
}
}
输出所有选中的边；
*/
#include <iostream>
#include <cstdio>
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

int FindSet(int x, int* parent);
void UnionSet(int x, int y, int weight, int &sum, int* mstRank, int* parent);
void Sort(Edge* edge, int n);

int main()
{
    Edge edges[MAXEDGE];    //存储边的数组
    int parent[MAXVEX];     //用于寻找根节点的数组
    int mstRank[MAXVEX];    //用于记录每个集合的高度，初始化为 0

    for(int i = 0; i < MAXVEX; i++)
    {
    parent[i] = i;
    mstRank[i] = 0;
    }

    int n;  //边的总数
    int sum = 0;    //最小生成树的权值和

    //输入边的总数
    cin >> n;
    //初始化边的集合
    for(int i = 1;i<=n;i++)
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

    //开始Kruskal算法
    for(int i=1;i<=n;i++)
    {
        int x,y;
        x = FindSet(edges[i].begin, parent);
        y = FindSet(edges[i].end, parent);
        if(x != y)
        {
            edges[i].selected = true;

            UnionSet(x, y, edges[i].weight, sum, mstRank, parent);
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(edges[i].selected)
        {
            cout << edges[i].begin << "-" << edges[i].end << endl;
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