#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef int Data;

//二叉树结点的结构
typedef struct BiTreeNode
{
    Data data;          //若将此行改为void* data，则可以存储任意类型的数据
    BiTreeNode *left;
    BiTreeNode *right;
} BiTreeNode;
//二叉树的结构
typedef struct BiTree
{
    int size;
    BiTreeNode* root;
    void(*destory)(Data data);  //destory是一个指向函数的指针。若是void* data,则写成void(*destory)(void* data)
    //解耦：BiTree 作为通用二叉树的管理结构，不关心节点存的是 int、字符串还是自定义结构体，只负责 “调用用户提供的销毁函数”；具体怎么销毁，由使用者根据数据类型自己实现。
    //如果动态申请了内存，在销毁一个结点时，由destory来负责释放内存。这个函数是有用户在使用具体的数据时提供的。如果不需要释放内存，可以让destory=NULL
} BiTree;

//创建一个空的二叉树,返回指向该二叉树的指针
//如果用户数据需要自行管理释放，则传递用户定义函数destory的指针
//如果用户数据不需要自行管理释放，则传递NULL
//返回BiTree*
BiTree* CreateBiTree(void(*destory)(Data data));//不指向根结点
//销毁一个二叉树：1.销毁所有结点 2.销毁二叉树管理结构
void DestoryBiTree(BiTree* tree);
//在二叉树中插入一个结点，使其成为node所指结点的左子结点
//如果node原来有左子结点，则用函数返回false
//如果node为NULL，则新结点作为根节点插入
//作为根节点插入式，树必须为空，否则返回false
//插入的结点包含数据data，内容由使用者维护
bool InsertBiTreeLeft(BiTree* tree, BiTreeNode* node, Data data);
//插入右结点
bool InsertBiTreeRight(BiTree* tree, BiTreeNode* node, Data data);
//移除Tree中node所指的左子结点为根的子树
//如果node为NULL，则移除根节点为根的子树
//如果创建树时，destory不为空，则会调用destory来销毁子树中的结点
void RemoveBiTreeLeft(BiTree* tree, BiTreeNode* node);
void RemoveBiTreeRight(BiTree* tree, BiTreeNode* node);
//合并两颗二叉树
//将left和right指定的二叉树合并为一棵二叉树
//合并完成后，left作为左子树，right作为右子树
//参data保存在根结点数据域
//原有的树left和right将不再可用
//合并成功后，返回指向新树的指针，失败返回NULL，left和right指向的树不变
BiTree* MergeBiTree(BiTree* left, BiTree* right, const Data data);
//得到树中结点数
int GetBiTreeSize(const BiTree* tree);
//得到树的根结点
BiTreeNode* GetBiTreeRoot(BiTree* tree);
//判断结点是否为空（某个分支结束）
bool IsBiTreeEob(const BiTreeNode* node);
//判断节点是否为叶子结点
bool IsBiTreeLeaf(const BiTreeNode* node);
//得到存储在结点中的数据
Data GetNodeData(const BiTreeNode* node);
//得到指定结点的左子结点
BiTreeNode* GetBiTreeLeft(const BiTreeNode* node);
//得到指定结点的右子结点
BiTreeNode* GetBiTreeRight(const BiTreeNode* node);

#endif