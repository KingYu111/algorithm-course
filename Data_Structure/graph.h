#ifndef GRAPH_H
#define GRAPH_H

//图的邻接表存储结构

#define Max_VertexNum 100 //最大顶点数
typedef char VertexType; //顶点类型
typedef int EdgeType; //边类型

//边表节点
typedef struct EdgeNode
{
    int adjvex;//邻接点域，存储该边的下标，即指向哪一个节点。不管是有向图还是无向图，都要有
    int weight;//边的权值
    EdgeNode* next;//指向下一条边
} EdgeNode;

//顶点表节点
typedef struct VertexNode
{
    VertexType data;
    EdgeNode* firstedge;
} VertexNode;

typedef VertexNode AdjList[Max_VertexNum];//邻接表

typedef struct ALGraph //Adjacent List Graph
{
    AdjList adjlist;//邻接表
    int n,e;//顶点数和边数
} ALGraph;

/*----------函数声明----------*/
//创建邻接表表示的图
void CreateGraphAL(ALGraph *G);
//深度优先遍历  
void DFS(ALGraph *G, int i, bool *visited);
//深度优先遍历图
void DFSTraverseM(ALGraph *G);
//广度优先遍历  
void BFS(ALGraph *G, int k, bool *visited);
//广度优先遍历图
void BFSTraverseM(ALGraph *G);
//打印邻接表表示的图
void PrintfGraphAL(ALGraph *G);
//删除邻接表表示的图
void DeleteGraphAL(ALGraph *G);

#endif // GRAPH_H