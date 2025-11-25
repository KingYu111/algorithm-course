//顺序表
//以整数为元素的顺序表

#include <stdio.h>
#include <stdlib.h>

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

//线性表方法实现
/** 
 * @brief 创建一个线性表
 * 
 * @param length 线性表的初始长度
 * @return ListType* 指向创建的线性表的指针
 */
 ListType* CreateList(int length)
 {
    //1.分配内存空间
    ListType *sqList = (ListType *)malloc(sizeof(ListType));
    if(sqList == NULL)
    {
        printf("内存分配失败");
        return NULL;
    }
    //2.初始化
    sqList->list = (DataType *)malloc(length * sizeof(DataType));
    if(sqList->list == NULL)
    {
        printf("内存分配失败");
        return NULL;
    }
    //置为空表
    sqList->length = 0;
    sqList->maxLength = length; 
    //3.返回指针
    return sqList;  
 }

 /** 
 * @brief 销毁一个线性表
 * 
 * @param pList 指向要销毁的线性表的指针
 */
void DestoryList(ListType *pList)
{
    //1.释放线性表的内存
    free(pList->list);
    //2.释放线性表结构体的内存
    free(pList);
}

/** 
 * @brief 清空一个线性表
 * 
 * @param pList 指向要清空的线性表的指针
 */
void ClearList(ListType *pList)
{
    //将线性表的长度设为0
    pList->length = 0;
}

/** 
 * @brief 判断一个线性表是否为空
 * 
 * @param pList 指向要判断的线性表的指针
 * @return int 若线性表为空则返回1，否则返回0
 */
int IsEmptyList(ListType *pList)
{
    //判断线性表的长度是否为0
    return pList->length == 0;
}

/** 
 * @brief 获取一个线性表的长度
 * 
 * @param pList 指向要获取长度的线性表的指针
 * @return int 线性表的长度
 */
int GetListLength(ListType *pList)
{
    //返回线性表的长度
    return pList->length;
}

/** 
 * @brief 获取一个线性表的元素
 * 
 * @param pList 指向要获取元素的线性表的指针
 * @param n 要获取元素在线性表中的位置    
 * @param data 指向要存储元素的变量的指针
 * @return int 若获取成功则返回1，否则返回0
 */
int GetListElement(ListType *pList, int n, DataType *data)
{
    //判断n是否在合法范围内
    if(n < 0 || n > pList->length-1)
    {
        printf("位置n不合法");
        return 0;
    }
    //将第n个元素赋值给data
    *data = pList->list[n];   
    //返回1表示成功
    return 1;
}

/** 
 * @brief 查找一个线性表中指定元素的位置
 * 
 * @param pList 指向要查找的线性表的指针
 * @param pos 要查找的元素在线性表中的位置
 * @param data 要查找的元素
 * @return int 若查找成功则返回元素的位置，否则返回0
 */
int FindElement(ListType *pList, int pos, DataType data)
{
    //判断pos是否在合法范围内
    if(pos < 0 || pos > pList->length-1)
    {
        printf("位置pos不合法");
        return 0;
    }
    //从pos位置开始查找
    for(int i = pos; i < pList->length; i++)
    {
        if(pList->list[i] == data)
        {
            return i;
        }
    }
    //未找到
    return -1;
}

/** 
 * @brief 获取一个线性表中指定位置元素的前驱
 * 
 * @param pList 指向要获取前驱的线性表的指针
 * @param pos 要获取前驱的元素在线性表中的位置
 * @param data 指向要存储前驱的变量的指针
 * @return int 找到则返回前驱的位置pos-1，未找到则返回-1
 */
int GetPriorElement(ListType *pList, int pos, DataType *data)
{
    //判断pos是否在合法范围内
    if(pos < 0 || pos > pList->length-1)
    {
        printf("位置pos不合法");
        return -1;
    }
    //判断pos是否为第一个元素
    if(pos == 0)
    {
        printf("第一个元素无前驱");
        return -1;
    }
    //将pos位置的前一个元素赋值给data
    *data = pList->list[pos-1];   
    //返回前驱的位置
    return pos-1;       
}

/** 
 * @brief 获取一个线性表中指定位置元素的后继
 * 
 * @param pList 指向要获取后继的线性表的指针
 * @param pos 要获取后继的元素在线性表中的位置
 * @param data 指向要存储后继的变量的指针
 * @return int 找到则返回后继的位置pos+1，未找到则返回-1
 */
int GetNextElement(ListType *pList, int pos, DataType *data)
{
    //判断pos是否在合法范围内
    if(pos < 0 || pos > pList->length-1)
    {
        printf("位置pos不合法");
        return -1;
    }
    //判断pos是否为最后一个元素
    if(pos == pList->length-1)
    {
        printf("最后一个元素无后继");
        return -1;
    }
    //将pos位置的后一个元素赋值给data
    *data = pList->list[pos+1];   
    //返回后继的位置
    return pos+1;       
}

/** 
 * @brief 在线性表中指定位置插入一个元素
 * 
 * @param pList 指向要插入元素的线性表的指针
 * @param pos 要插入元素的位置
 * @param data 要插入的元素
 * @return int 若插入成功则返回原表长+1，否则返回-1
 */
int InsertToList(ListType *pList, int pos, DataType data)
{
    //判断pos是否在合法范围内
    if(pos < 0 || pos > pList->length)
    {
        printf("位置pos不合法");
        return -1;
    }
    //判断线性表是否已满
    if(pList->length == pList->maxLength)
    {
        printf("线性表已满");
        return -1;
    }
    //将pos位置及后面的元素后移一位
    for(int i = pList->length-1; i >= pos; i--)
    {
        pList->list[i+1] = pList->list[i];
    }
    //将data赋值给pos位置
    pList->list[pos] = data;
    //线性表长度加1
    pList->length++;
    //返回原表长+1
    return pList->length;
}

/** 
 * @brief 删除一个线性表中指定位置的元素
 * 
 * @param pList 指向要删除元素的线性表的指针
 * @param pos 要删除元素的位置
 * @param data 指向要存储删除元素的变量的指针
 * @return int 若删除成功则返回原表长-1，否则返回-1
 */
int DeleteFromList(ListType *pList, int pos)
{
    //判断pos是否在合法范围内
    if(pos < 0 || pos > pList->length-1)
    {
        printf("位置pos不合法");
        return -1;
    }
    //将pos位置后面的元素前移一位
    for(int i = pos; i < pList->length-1; i++)
    {
        pList->list[i] = pList->list[i+1];
    }
    //线性表长度减1
    pList->length--;
    //返回原表长-1
    return pList->length;
}

/**
 * @brief 输出线性表
 * 
 * @param pList 指向要输出的线性表的指针
 */
void PrintList(ListType *pList)
{
    //判断线性表是否为空
    if(pList->length == 0)
    {
        printf("线性表为空");
        return;
    }
    //输出线性表的元素
    for(int i = 0; i < pList->length; i++)
    {
        printf("第%d项:%d\n ", i, pList->list[i]);
    }
    printf("\n");
}

/* 主函数，创建一个线性表，并测试*/
int main()
{
    system("chcp 65001 > nul");

    const int MAXLENGTH = 1000;        // 假设最大容量为 1000
    // 创建线性表
    ListType* sqList = CreateList(MAXLENGTH);
    // 以下是对线性表的测试
    ClearList(sqList);                 // 置表为空
    // 插入 10 个元素并显示
    for (int i = 0; i < 10; ++i)
        InsertToList(sqList, i, i + 1);
    // 输出线性表
    PrintList(sqList);
    // 在位置5插入99并显示
    InsertToList(sqList, 5, 99);
    printf("插入99后的线性表\n");
    PrintList(sqList);
    // 删除第8个元素
    DeleteFromList(sqList, 8);
    printf("删除第8个元素后的线性表\n");
    PrintList(sqList);
    // 显示第3个元素的前驱
    DataType data;
    if (GetPriorElement(sqList, 3, &data) > -1)
        printf("第3个元素的前驱是%d\n", data);
    return 0;
}
