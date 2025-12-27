#include <iostream>
using namespace std;

typedef struct HFTree
{
    char data;
    int weight;
    HFTree* lchild;
    HFTree* rchild;
}HFTree;

//创建哈夫曼树
HFTree* CreateHFTree(int n, int* weight);
//显示哈夫曼编码
void ShowHaffumanCode(HFTree* treeArray, string code);
//打印哈夫曼树
void PrintHFTree(HFTree* treeArray, int totalNode);
//计算哈夫曼树的带权路径长度
int CalculateWPL(HFTree* root, int depth);
//合并
void MergeHFTree(HFTree* treeArray, int n);


HFTree* CreateHFTree(int n, int* weight)
{
    int totalNode = 2*n-1;
    HFTree* treeArray = new HFTree[totalNode];//有2n-1个节点
    // 1.每个节点都是一棵树
    for(int i =0;i<n;i++)
    {
        HFTree* node = &treeArray[i];
        node->data = 'A' + i;
        node->weight = weight[i];
        node->lchild = NULL;
        node->rchild = NULL;
    }

    // 2.空节点处理
    for(int i = n;i<totalNode;i++)
    {
        HFTree* node = &treeArray[i];
        node->data = '\0';
        node->weight = 0;
        node->lchild = NULL;
        node->rchild = NULL;
    }
    

    // 3.合并
    MergeHFTree(treeArray, n);

    return treeArray;
}

void MergeHFTree(HFTree* treeArray, int n)
{
    int totalNode = 2*n-1;

    HFTree* forest[100];
    int forestSize = n;

    //初始化森林
    for(int i=0;i<n;i++)
    {
        forest[i] = &treeArray[i];
    }

    int cur = n;

    while(forestSize > 1)
    {
        // 1.找到权值最小的两个
        int min1 = 0;
        int min2 = 1;
        if(forest[min1]->weight > forest[min2]->weight)
        {
            min1 = min2;
            min2 = 0;
        }

        for(int i=2;i<forestSize;i++)
        {
            if(forest[i]->weight < forest[min1]->weight)
            {
                min2 = min1;
                min1 = i;
            }
            else if(forest[i]->weight < forest[min2]->weight)
            {
                min2 = i;
            }
        }

        // 2.合并
        HFTree* newTree = &treeArray[cur++];
        newTree->weight = forest[min1]->weight + forest[min2]->weight;
        newTree->lchild = forest[min1];
        newTree->rchild = forest[min2];

        // 3.更新森林，加一个，删除两个
        forest[min1] = newTree;
        forest[min2] = forest[forestSize-1];
        forestSize--;
    }
}

void ShowHaffumanCode(HFTree* treeArray, string code)
{
    if(treeArray == NULL) return;

    // 1.判断是否是叶子结点，如果是，则打印编码
    if(treeArray->lchild == NULL && treeArray->rchild == NULL)
    {
        cout << treeArray->data << " : " << code << endl;
    }
    else
    {
        // 2. 如果不是叶子结点，则递归打印左子树的编码
        ShowHaffumanCode(treeArray->lchild, code + "0");
        // 3. 递归打印右子树的编码
        ShowHaffumanCode(treeArray->rchild, code + "1");
    }
}

void PrintHFTree(HFTree* treeArray, int totalNode)
{
    cout << "哈夫曼树的结构如下：" << endl;
    for(int i=0;i<totalNode;i++)
    {
        cout << "节点" << i << "：" << treeArray[i].data << "，权重：" << treeArray[i].weight << endl;
        if(treeArray[i].lchild != NULL)
        {
            cout << "    左子节点：" << treeArray[i].lchild - treeArray << endl;
        }
        if(treeArray[i].rchild != NULL)
        {
            cout << "    右子节点：" << treeArray[i].rchild - treeArray << endl;
        }
    }
}

int CalculateWPL(HFTree* root, int depth)
{
    if(root == NULL) return 0;
    if(root->lchild == NULL && root->rchild == NULL)
    {
        return root->weight * depth;
    }
    
    return CalculateWPL(root->lchild,depth+1) + CalculateWPL(root->rchild,depth+1);

}

int main()
{
    system("chcp 65001 > nul");
    int n;//字符个数
    cin >> n;
    int* weight = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin >> weight[i];
    }

    HFTree* treeArray = CreateHFTree(n, weight);
    int totalNode = 2*n-1;

    PrintHFTree(treeArray, totalNode);

    HFTree* root = &treeArray[2*n-2];
    ShowHaffumanCode(root, "");

    int wpl = CalculateWPL(root, 0);
    cout << "哈夫曼树的带权路径长度为：" << wpl << endl;
    
    delete[] weight;
    delete[] treeArray;

    return 0;
}


