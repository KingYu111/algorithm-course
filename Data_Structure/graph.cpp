#include "graph.h"
#include <iostream>
using namespace std;

//建立无向图的邻接表算法
void CreateGraphAL(ALGraph *G)
{
    //1.输入顶点数和边数
    cout << "please input the number of vertex and edge:" << endl;
    cin >> G->n >> G->e;
    
    //2.输入顶点
    cout << "please input the vertex:" << endl;
    for(int i = 0; i < G->n; i++)
    {
        cin >> G->adjlist[i].data;
        G->adjlist[i].firstedge = NULL;
    }
    
    //3.输入边
    cout << "please input the edge:" << endl;
    for(int i = 0; i < G->e; i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        EdgeNode *e1 = new EdgeNode;
        e1->adjvex = v2;
        e1->next = G->adjlist[v1].firstedge;
        G->adjlist[v1].firstedge = e1;
        EdgeNode *e2 = new EdgeNode;
        e2->adjvex = v1;
        e2->next = G->adjlist[v2].firstedge;
        G->adjlist[v2].firstedge = e2;
    }
}

//深度优先遍历
void DFS(ALGraph *G, int i, bool *visited)
{
    //以vi为出发点对邻接表表示的图G进行深度优先搜索
    EdgeNode *p;
    //访问结点vi
    cout << "visit vertex:" << G->adjlist[i].data << endl;
    //标记以访问
    visited[i] = true;
    //取vi边表的头指针
    p = G->adjlist[i].firstedge;

    while(p != NULL)
    {
        //依次搜索vi的邻接点vj，这里j=p->adjvex
        if(!visited[p->adjvex])
        {
            DFS(G, p->adjvex, visited);
        }
        p = p->next;
    }
}

//深度优先遍历图
void DFSTraverseM(ALGraph *G)
{
    bool *visited = new bool[G->n];
    for(int i = 0; i < G->n; i++)
    {
        visited[i] = false;
    }
    for(int i = 0; i < G->n; i++)
    {
        if(!visited[i])
        {
            DFS(G, i, visited);
        }
    }
}

//广度优先遍历
void BFS(ALGraph *G, int k, bool *visited)
{
    
}

//广度优先遍历图
void BFSTraverseM(ALGraph *G)
{
    bool *visited = new bool[G->n];
    for(int i = 0; i < G->n; i++)
    {
        visited[i] = false;
    }
    for(int i = 0; i < G->n; i++)
    {
        if(!visited[i])
        {
            BFS(G, i, visited);
        }
    }
}

//打印邻接表
void PrintfGraphAL(ALGraph *G)
{
    for(int i = 0; i < G->n; i++)
    {
        cout << G->adjlist[i].data << "->";
        EdgeNode *p = G->adjlist[i].firstedge;
        while(p != NULL)
        {
            cout << G->adjlist[p->adjvex].data << "(" << p->weight << ")";
            p = p->next;
        }
        cout << endl;
    }
}

//删除邻接表
void DeleteGraphAL(ALGraph *G)
{
    for(int i = 0; i < G->n; i++)
    {
        EdgeNode *p = G->adjlist[i].firstedge;
        while(p != NULL)
        {
            EdgeNode *temp = p;
            p = p->next;
            delete temp;
        }
        G->adjlist[i].firstedge = NULL;
    }
}