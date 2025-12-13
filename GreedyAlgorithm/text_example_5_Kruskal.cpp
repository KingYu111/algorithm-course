//最小生成树的Kruskal算法
//把图中所有边按权值从小到大排序。
//按这个顺序依次枚举每一条边 (u, v, w)：
//如果这条边连接的两个点 当前不在同一个连通块（不会形成环），就把这条边加入生成树；
//否则跳过这条边。
//当加入的边数达到 n-1（n 是顶点数）时，算法结束；这些边构成一棵最小生成树。
//关键点在于：如何判断一条边会不会成环？
//——用一个叫“并查集”的数据结构。
//并(Union)查(Find)集(Set)
//并查集是一种树型的数据结构，用于处理一些不相交集合的合并及查询问题。
//它支持两种操作：
//查找（Find）：确定某个元素属于哪个集合，通常是返回集合内的一个“代表元素”。
//合并（Union）：将两个集合合并为一个集合。
//Kruskal算法步骤：
//1.将边按权值排序
//2.初始化并查集
//3.开始一条条“试边”，组成最小生成树
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
//冒泡排序
void BubbleSort(Edge *edge, int n);

int main()
{
    Edge edge[MAX];

    //已找到的最小生成树其中一部分的秩
    //用来判断两个集合的大小，哪个集合大，就把小的集合合并到大的集合中。矮树挂在高树下面。
    //秩让树尽量矮，加快FindSet速度
    int mstRank[MAX];

    //已找到的最小生成树其中一部分的头结点
    //用来判断一条边的两个端点是否在一个集合中，即加上这条边是否会形成回路
    int parent[MAX];//parent[i]表示i节点的头节点，就是i节点的在树中的上一个节点

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
    //FastSort(edge, 1, n);
    BubbleSort(edge, n);
    //开始试边
    for(int i=1;i<=n;i++)
    {
        int x,y;
        x = FindSet(edge[i].x, parent);
        y = FindSet(edge[i].y, parent);
        //如果这条边的两个端点不在一个集合中
        if(x != y)//如果在一个集合就成环了
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

/**
 * @brief 查找集合的头节点
 * @param x 集合的一个元素
 * @param parent 集合的头节点数组
 * @return int 集合的头节点
 */
int FindSet(int x, int* parent)
{
    if(x!=parent[x])
    {
        parent[x] = FindSet(parent[x], parent);
    }
    return parent[x];
}
/**
 * @brief 合并集合
 * @param x 集合的一个元素
 * @param y 集合的另一个元素
 * @param w 合并的边的权值
 * @param sum 最小生成树的权值和
 * @param mstRank 集合的秩数组
 * @param parent 集合的头节点数组
 */
void UnionSet(int x, int y, Weight w, Weight &sum, int *mstRank, int* parent)//sum是引用
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
/**
 * @brief 冒泡排序
 * @param edge 边数组
 * @param n 边的总数
 */
void BubbleSort(Edge *edge, int n)
{
    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 1; j <= n - i; j++)
        {
            if(edge[j].weight > edge[j + 1].weight)
            {
                Edge temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }
}
/**
 * @brief 快读排序
 * @param edge 边数组
 * @param begin 排序的开始位置
 * @param end 排序的结束位置
 */
void FastSort(Edge *edge, int begin, int end)
{
    if(begin < end)
    {
        int i= begin -1;
        int j = begin;
        //edge[0] = edge[end];
        Edge pivot = edge[end];

        while(j<end)
        {
            if(edge[j].weight < pivot.weight)
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