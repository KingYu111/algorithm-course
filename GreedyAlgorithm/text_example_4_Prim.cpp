//最小生成树的Prim算法
#include <iostream>

#define MAX 100
#define Infinity 65535
typedef int Weight;
using namespace std;

//定义图的邻接表结构
struct EdgeNode
{
    int no;//边端的序号
    char info;//边端的名称
    Weight weight;//边的权值
    struct EdgeNode *next;//指向下一条边的指针
};

//结点的定义
struct VexNode
{
    char info;//结点名称
    struct EdgeNode* link;//与之相连的端点
};

//函数声明
//输入图的数据，创建邻接表
void CreateGraph(VexNode* adjlist, const int nVex, const int nEdge);
//得到最小生成树
Weight CreateMST(VexNode* adjlist, int* parent, const int n, const int startVex);

int main()
{
    //存储结点信息
    VexNode adjlist[MAX];

    int nVex;//结点总数
    int nEdge;//边的总数
    cout << "请输入结点总数：";
    cin >> nVex;
    cout << "请输入边的总数：";
    cin >> nEdge;
    cout << "请输入从哪一结点开始：";
    int startVex;
    cin >> startVex;
    //parent[j]表示结点j的前驱节点
    int parent[MAX];

    //创建邻接表
    CreateGraph(adjlist, nVex, nEdge);

    //得到最小生成树
    Weight sum = CreateMST(adjlist, parent, nVex, startVex);
    
    // 输出
    cout << "最小生成树的边集为：" << endl;
    for(int i=1;i<=nVex;i++)
    {
        if(i!=startVex && parent[i] != -1)
        {
            cout << "(" << adjlist[parent[i]].info << "," << adjlist[i].info << ")" << " ";
        }
    }
    cout << endl;
    cout << "最小生成树的权值为：" << sum << endl;
    return 0;
}

//建立邻接表存储
void CreateGraph(VexNode *adjlist, const int n, const int e)
{
    for(int i=1;i<=n;i++)
    {
        cout << "请输入结点" << i << "的名称：";
        cin >> adjlist[i].info;
        adjlist[i].link = NULL;
    }
    //每输入一条边，在邻接表中添加两个对应的结点
    EdgeNode* p1;
    EdgeNode* p2;

    int v1,v2;
    int weight;

    for(int i=1;i<=e;i++)
    {
        cout << "请输入边" << i << "的两个端点序号：";
        cin >> v1 >> v2;
        cout << "请输入边" << i << "的权值：";
        cin >> weight;

        p1 = new EdgeNode;
        p1->no = v2;
        p1->info = adjlist[v2].info;
        p1->weight = weight;
        p1->next = adjlist[v1].link;
        adjlist[v1].link = p1;

        p2 = new EdgeNode;
        p2->no = v1;
        p2->info = adjlist[v1].info;
        p2->weight = weight;
        p2->next = adjlist[v2].link;
        adjlist[v2].link = p2;
    }
}

Weight CreateMST(VexNode* adjlist, int* parent, const int n, const int startVex)
{
    bool visited[MAX];
    Weight lowcost[MAX];//存储从开始结点到结点j的最小花费

    for(int i=1;i<=n;i++)
    {
        visited[i] = false;
        lowcost[i] = Infinity;
        parent[i] = startVex;
    }

    //最小生成树的权值总和
    Weight sum = 0;
    EdgeNode *p,*q;
    p = adjlist[startVex].link;
    visited[startVex] = true;
    while(p!=NULL)
    {
        lowcost[p->no] = p->weight;
        p = p->next;
    }

    //寻找最小的权值加入
    Weight minCost;
    for(int i=1;i<=n-1;i++)
    {
        minCost = Infinity;
        int k = -1;
        for(int j =1;j<=n;j++)
        {
            if(!visited[j] && lowcost[j] < minCost)
            {
                minCost = lowcost[j];
                k = j;
            }
        }
        // 图可能不连通：未找到可达的下一个结点
        if (k == -1 || minCost == Infinity)
        {
            break;
        }
        //总权值
        sum += minCost;
        visited[k] = true;
        q = adjlist[k].link;
        while(q!=NULL)
        {
            if(!visited[q->no]&&lowcost[q->no]>q->weight)
            {
                lowcost[q->no] = q->weight;
                parent[q->no] = k;
            }
            q = q->next;
        }
    }
    // 设置无前驱标记：起点和未访问的结点
    for(int i=1;i<=n;i++)
    {
        if (i == startVex || !visited[i]) parent[i] = -1;
    }
    return sum;
}