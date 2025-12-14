#ifndef _BINARY_TREE_TRAVERSE_H_
#define _BINARY_TREE_TRAVERSE_H_

#include "BinaryTree.h"

typedef int Data;

//前序、中序、后序遍历，遍历结果放在数组里
bool PreOrder(const BiTreeNode* node, Data* list);
bool InOrder(const BiTreeNode* node, Data* list);
bool PostOrder(const BiTreeNode* node, Data* list);

#endif
