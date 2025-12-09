#include <iostream>
#include <ostream>
#include "graph.h"
using namespace std;

int main()
{
    ALGraph *g = new ALGraph;
    g->n = 0;
    g->e = 0;
    CreateGraphAL(g);
    cout << "深度优先遍历：" << endl;
    DFSTraverseM(g);\
    cout << "广度优先遍历：" << endl;
    BFSTraverseM(g);
    cout << "邻接表:" << endl;
    PrintfGraphAL(g);
    DeleteGraphAL(g);

    return 0;
}