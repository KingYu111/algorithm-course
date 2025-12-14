#ifndef _LIST_H_
#define _LIST_H_

typedef int DataType;

//定义线性表的结构
typedef struct List
{
    DataType *list;     //指向线性表的指针
    int length;         //表长
    int maxLength;      //表容量
} ListType;

//声明线性表具有的方法
ListType* CreateList(int length);
void DestoryList(ListType *pList);
void ClearList(ListType *pList);
int IsEmptyList(ListType *pList);
int GetListLength(ListType *pList);
int GetListElement(ListType *pList, int n, DataType *data);
int FindElement(ListType *pList, int pos, DataType data);
int GetPriorElement(ListType *pList, int pos, DataType *data);
int GetNextElement(ListType *pList, int pos, DataType *data);
int InsertToList(ListType *pList, int pos, DataType data);
int DeleteFromList(ListType *pList, int pos);
void PrintList(ListType *pList);

#endif