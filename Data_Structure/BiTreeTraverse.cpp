#include "BiTreeTraverse.h"
#include "List.h"
using namespace std;

//前序遍历，先根遍历
bool PreOrder(const BiTreeNode* node, ListType* list)
{
    //如果结点不为空，进行遍历
    if(!IsBiTreeEob(node))//如果结点不是空结点
    {
        //1.将结点的数据存储到线性表中
        if(InsertToList(list, list->length, node->data) == -1)
        {
            return false;
        }

        //2.如果左子树不为空，递归遍历左子树
        if(!IsBiTreeEob(GetBiTreeLeft(node)))
        {
            if(!PreOrder(GetBiTreeLeft(node), list))
            {
                return false;
            }
        }
        //3.如果右子树不为空，递归遍历右子树
        if(!IsBiTreeEob(GetBiTreeRight(node)))
        {
            if(!PreOrder(GetBiTreeRight(node), list))
            {
                return false;
            }
        }
    }
    return true;
}

bool InOrder(const BiTreeNode* node, ListType* list)
{
    //如果结点不为空，进行遍历
    if(!IsBiTreeEob(node))
    {
        //1.如果左子树结点不为空，先递归遍历左子树
        if(!IsBiTreeEob(GetBiTreeLeft(node)))
        {
            if(!InOrder(GetBiTreeLeft(node), list))
            {
                return false;
            }
        }

        //2.将结点数据插入到线性表中
        if(InsertToList(list, list->length, node->data) == -1)
        {
            return false;
        }

        //3.如果右子树结点不为空，递归遍历右子树
        if(!IsBiTreeEob(GetBiTreeRight(node)))
        {
            if(!InOrder(GetBiTreeRight(node), list))
            {
                return false;
            }
        }
    }
    return true;
}

bool PostOrder(const BiTreeNode* node, ListType* list)
{
    if(!IsBiTreeEob(node))
    {
        if(!IsBiTreeEob(GetBiTreeLeft(node)))
        {
            if(!PostOrder(GetBiTreeLeft(node), list))
            {
                return false;
            }
        }

        if(!IsBiTreeEob(GetBiTreeRight(node)))
        {
            if(!PostOrder(GetBiTreeRight(node), list))
            {
                return false;
            }
        }

        if(InsertToList(list, list->length, node->data) == -1)
        {
            return false;
        }
    }
    return true;
}
