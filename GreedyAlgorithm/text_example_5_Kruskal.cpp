//最小生成树的Kruskal算法
#include <iostream>
using namespace std;

#define MAX 100
typedef int Weight;

struct Edge
{
    int no;//边的序号
    int x;//边的一个端点
    int y;//边的另一个端点
    Weight weight;
    bool selected;
};

//找出每一个集合的头节点
int FindSet(int x, int* parent);
//合并集合
void UnionSet(int x, int y, Weight w, Weight &sum, int *mstRank, int* parent);
//快读排序
void FastSort(Edge *edge, int begin, int end);

int main()
{
    Edge edge[MAX];

    //已找到的最小生成树其中一部分的秩
    int mstRank[MAX];

    //已找到的最小生成树其中一部分的头结点
    //用来判断一条边的两个端点是否在一个集合中，即加上这条边是否会形成回路
    int parent[MAX];

    int n;//边的总数
    //最小生成树的权值和
    Weight sum = 0;
    cout << "请输入边的个数：";
    cin >> n;

    //初始化以及输入
    Weight weight;
    for(int i=1;i<=n;i++)
    {
        edge[i].no = i;
        cout << "请输入第" << i << "条边的两个端点序号：";
        cin >> edge[i].x >> edge[i].y;
        cout << "这条边的权值：";
        cin >> edge[i].weight;
        //开始时所有边都没有被选中
        edge[i].selected = false;

        parent[edge[i].x] = edge[i].x;
        parent[edge[i].y] = edge[i].y;
        //开始时所有集合的秩都为0
        mstRank[edge[i].x] = 0;
        mstRank[edge[i].y] = 0;

    }
    //对所有边按权值排序
    FastSort(edge, 1, n);
    //对所有边按权值排序
    for(int i=1;i<=n;i++)
    {
        int x,y;
        x = FindSet(edge[i].x, parent);
        y = FindSet(edge[i].y, parent);
        //如果这条边的两个端点不在一个集合中
        if(x != y)
        {
            //将这条边加入最小生成树
            edge[i].selected = true;
            //合并这两个端点所在的集合
            //注意，这里前两个参数不能传edge[i].x和edge[i].y，而要传x和y。不然会改变集合的头节点
            UnionSet(x, y, edge[i].weight, sum, mstRank, parent);
        }
    }
    //输出最小生成树的边集
    cout << "最小生成树的边集为：" << endl;
    for(int i=1;i<=n;i++)
    {
        if(edge[i].selected)
        {
            cout << "(" << edge[i].x << "," << edge[i].y << ")" << " ";
        }
    }
    cout << endl;
    //输出最小生成树的权值和
    cout << "最小生成树的权值和为：" << sum << endl;

}

int FindSet(int x, int* parent)
{
    if(x!=parent[x])
    {
        parent[x] = FindSet(parent[x], parent);
    }
    return parent[x];
}

void UnionSet(int x, int y, Weight w, Weight &sum, int *mstRank, int* parent)
{
    if(x == y)
        return;
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
    sum += w;
}

void FastSort(Edge *edge, int begin, int end)
{
    if(begin < end)
    {
        int i= begin -1;
        int j = begin;
        edge[0] = edge[end];

        while(j<end)
        {
            if(edge[j].weight < edge[0].weight)
            {
                i++;
                Edge temp1 = edge[i];
                edge[i] = edge[j];
                edge[j] = temp1;
            }
            j++;
        }

        Edge temp2 = edge[i+1];
        edge[i+1] = edge[end];
        edge[end] = temp2;
        FastSort(edge, begin, i);
        FastSort(edge, i+2, end);
    }
}