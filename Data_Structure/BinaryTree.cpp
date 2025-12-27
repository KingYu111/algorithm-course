#include "BinaryTree.h"
#include <new>
using namespace std;

BiTree* CreateBiTree(void(*destory)(Data data))
{
    BiTree* tree = new(nothrow)BiTree;//new后的nothrow用来在new分配失败时，返回指针NULL，而不是抛出异常
    if(tree)
    {
        tree->destory = nullptr;
        tree->size = 0;
        tree->root = nullptr;
    }
    return tree;
}

void DestoryBiTree(BiTree* tree)
{
    //直接调用移除左子树的函数即可
    RemoveBiTreeLeft(tree,nullptr);
}

bool InsertBiTreeLeft(BiTree* tree,BiTreeNode* node, const Data data)
{
    //1.创建新的结点
    BiTreeNode* newNode;

    newNode = new(nothrow)BiTreeNode;
    if(!newNode)
    {
        return false;
    }

    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    //2.寻找在哪里插入结点
    if(node == nullptr)//插入的结点是根节点
    {
        if(tree->size > 0)
        {
            return false;
        }
        tree->root = newNode;
    }
    else
    {
        //只有在所给子树左结点为空的情况下才插入
        if(node->left != nullptr)
        {
            return false;
        }
        node->left = newNode;
    }
    tree->size++;
    return true;
}

bool InsertBiTreeRight(BiTree* tree, BiTreeNode* node, const Data data)
{
    //1.创建新的结点
    BiTreeNode* newNode;

    newNode = new(nothrow)BiTreeNode;
    if(!newNode)
    {
        return false;
    }

    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    //2.寻找在哪里插入结点
    if(node == nullptr)//插入的结点是根节点
    {
        if(tree->size > 0)
        {
            return false;
        }
        tree->root = newNode;
    }
    else
    {
        //只有在所给子树右结点为空的情况下才插入
        if(node->right != nullptr)
        {
            return false;
        }
        node->right = newNode;
    }
    tree->size++;
    return true;
}

//移除Tree中node所指的左子结点为根的子树
//如果node为NULL，则移除树中的所有结点
void RemoveBiTreeLeft(BiTree* tree, BiTreeNode* node)
{
    BiTreeNode* position;
    
    if(tree->size == 0)
    {
        return;
    }

    if(node == nullptr)
    {
        position = tree->root;
    }
    else
    {
        position = node->left;
    }

    if(position != nullptr)
    {
        RemoveBiTreeLeft(tree, position);
        RemoveBiTreeRight(tree, position);
        if(tree->destory != nullptr)
        {
            tree->destory(position->data);
        }

        delete(position);
        position = nullptr;
        if(node != nullptr)
        {
            node->left = nullptr;
        }      
        else 
        {
            tree->root = nullptr;
        }

        tree->size--;
    }
    return;
}

void RemoveBiTreeRight(BiTree* tree, BiTreeNode* node)
{
    
    BiTreeNode* position;
    //1.判断树是否为空
    if(tree->size == 0)
    {
        return;
    }
    //2.判断node是否为空，确定要移除的结点在哪
    if(node == nullptr)
    {
        position = tree->root;
    }
    else
    {
        position = node->right;
    }
    //3.移除结点
    if(position != nullptr)
    {
        RemoveBiTreeLeft(tree, position);
        RemoveBiTreeRight(tree, position);
        if(tree->destory != nullptr)
        {
            tree->destory(position->data);
        }

        delete(position);
        position = nullptr;

        tree->size--;
    }
    return;
}

BiTree* MergeBiTree(BiTree* left, BiTree* right, const Data data)
{
    //1.创建一个新树作为合并后的树
    BiTree* merge = CreateBiTree(left->destory);

    //2.将数据作为新树的根结点数据插入
    //如果失败，返回空指针
    if(!InsertBiTreeLeft(merge, nullptr, data))
    {
        DestoryBiTree(merge);
        return nullptr;
    }

    //3.合并两个二叉树为新树
    GetBiTreeRoot(merge)->left = left->root;
    GetBiTreeRoot(merge)->right = right->root;

    //4.计算新树大小
    merge->size = merge->size + GetBiTreeSize(left) + GetBiTreeSize(right);

    //5.清理旧树
    left->root = nullptr;
    left->size = 0;
    right->root = nullptr;
    right->size = 0;

    return merge;
}

int GetBiTreeSize(const BiTree* tree)
{
    return tree->size;
}

BiTreeNode* GetBiTreeRoot(BiTree* tree)
{
    return tree->root;
}

bool IsBiTreeEob(const BiTreeNode* node)
{
    return node == nullptr;
}

bool IsBiTreeLeaf(const BiTreeNode* node)
{
    return node->left == nullptr && node->right == nullptr;
}

Data GetNodeData(const BiTreeNode* node)
{
    return node->data;
}

//得到node的左子结点
BiTreeNode* GetBiTreeLeft(const BiTreeNode* node)
{
    return node->left;
}

BiTreeNode* GetBiTreeRight(const BiTreeNode* node)
{
    return node->right;
}