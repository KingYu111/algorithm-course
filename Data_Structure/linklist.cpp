#include <stdlib.h>
#include <stdio.h>

//假设使用整数链表
typedef int DataType;
//单链表的结点定义
typedef struct NODE Node;
typedef struct NODE
{
    DataType data;
    Node *next;
}Node;
//头指针
typedef Node* Head;
//链表的方法声明
int GetLinkListLength(Head head);
void DestoryLinkList(Head head);
int GetElement(Head head ,int n, DataType* data);
int FindElement(Head head, DataType data);
int GetPriorElement(Head head, int n, DataType* data);
int GetNextElement(Head head, int n, DataType* data);
int DeleteFromList(Head* head, int pos);
int InsertToList(Head* head, int pos, DataType data);
int InsertRear(Head* head, DataType data);
int InsertHead(Head* head, DataType data);
void PrintList(Head head);

//链表的方法实现
/** 
 * @brief 获取链表的长度
 * 
 * @param head 链表的头指针
 * @return int 链表的长度
*/
int GetLinkListLength(Head head)
{
    if(head == NULL)
    {
        return 0;
    }
    int i =1;
    Node* pNode = head;
    while(pNode->next != NULL)
    {
        i++;
        pNode = pNode->next;
    }
    return i;
}
/** 
 * @brief 销毁链表
 * 
 * @param head 链表的头指针
*/
void DestoryLinkList(Head head)
{
    if(head == NULL)
    {
        return;
    }
    Node* pNode;
    while(head)
    {
        pNode = head;
        head = head->next;
        free(pNode);
    }
}
/** 
 * @brief 获取线性表中第n个元素
 * @param head 链表的头指针
 * @param n 元素的位置
 * @param data 元素的值
 * @return 成功返回1，失败返回0
*/
int GetElement(Head head, int n, DataType* data)
{
    if(n <= 0 || n> GetLinkListLength(head) -1)
    {
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        head = head -> next;
    }
    *data = head->data;
    return 1;
}
/** 
 * @brief 查找data第一次出现的位置
 * @param head 链表的头指针
 * @param data 元素的值
 * @return 成功返回该位置，不成功返回-1
*/
int FindElement(Head head, DataType data)
{
    int i=0;
    while(head)
    {
        if(head->data == data)
        {
            return i;
        }
        i++;
        head = head->next;
    }
    return -1;
}
/** 
 * @brief 获取线性表中第n个元素的前驱
 * @param head 链表的头指针
 * @param n 元素的位置
 * @param data 元素的值
 * @return 成功返回前驱位置(n-1),失败返回-1
*/
int GetPriorElement(Head head, int n, DataType* data)
{
    if(n <1 || n> GetLinkListLength(head) -1)
    {
        return -1;
    }
    for(int i=0;i<n-1;i++)
    {
        head = head->next;
    }
    *data = head->data;
    return n-1;
}
/** 
 * @brief 获取线性表中第n个元素的后继
 * @param head 链表的头指针
 * @param n 元素的位置
 * @param data 元素的值
 * @return 成功返回后继位置(n+1),失败返回-1
*/
int GetNextElement(Head head, int n, DataType* data)
{
    if(n <0 || n> GetLinkListLength(head) -2)
    {
        return -1;
    }
    for(int i=0;i<n;i++)
    {
        head = head->next;
    }
    *data = head->next->data;
    return n+1;
}
/**
 *@brief 将data插入pos处
 *@param head 链表的头指针
 *@param pos 元素的位置
 *@param data 元素的值
 *@return 成功返回新的表长，失败返回-1
*/
int InsertToList(Head* head, int pos, DataType data)
{
    Node* pNode = *head;
    int length = GetLinkListLength(pNode);
    if(pos <0 || pos> length)
    {
        return -1;
    }
    if(pos == 0)
    {
        return InsertHead(head, data);
    }
    if(pos == length - 1)
    {
        return InsertRear(head, data);
    }
    //定位到pos前一位
    for(int i=0;i<pos-1;i++)
    {
        pNode = pNode->next;
    }
    //创建新节点
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    if(pNewNode == NULL)
    {
        return -1;
    }
    pNewNode->data = data;
    pNewNode->next = pNode->next;
    pNode->next = pNewNode;
    return ++length;
}
/**
 *@brief 删除pos处的元素
 *@param head 链表的头指针
 *@param pos 元素的位置
 *@return 成功返回新的表长，失败返回-1
*/
int DeleteFromList(Head* head, int pos)
{
    Node* pNode = *head;
    int length = GetLinkListLength(pNode);
    if(pos <0 || pos> length - 1)
    {
        return -1;
    }
    Node* pDeleteNode;
    if(pos == 0)
    {
        pDeleteNode = *head;
        *head = (*head)->next;
    }
    if(pos > 0 )
    {
        for(int i =0;i<pos-1;i++)
        {
            pNode = pNode->next;
        }
        pDeleteNode = pNode->next;
        pNode->next = pNode->next->next;
    }
    free(pDeleteNode);
    return --length;
}
/**
 *@brief 从表尾插入元素
 *@param head 链表的头指针
 *@param data 元素的值
 *@return 成功返回新的表长，失败返回-1
*/
int InsertRear(Head* head, DataType data)
{
    Node* pNode = *head;
    int length = GetLinkListLength(pNode);
    //创建新节点
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    if(pNewNode == NULL)
    {
        return -1;
    }
    pNewNode->data = data;
    pNewNode->next = NULL;
    //定位到表尾
    for(int i=0;i<length-1;i++)
    {
        pNode = pNode->next;
    }
    pNode->next = pNewNode;
    return ++length;
}
/**
 *@brief  从表头插入元素
 *@param head 链表的头指针
 *@param data 元素的值
 *@return 成功返回新的表长，失败返回-1
*/
int InsertHead(Head* head, DataType data)
{
    Node* pNewNode = (Node*)malloc(sizeof(Node));
    if(pNewNode == NULL)
    {
        return -1;
    }
    pNewNode->data = data;
    pNewNode->next = *head;
    *head = pNewNode;
    return GetLinkListLength(*head);
}

/**
 *@brief 输出链表
 *@param head 链表的头指针
*/
void PrintLinkList(Head head)
{
    int n = 0;
    while(head)
    {
        printf("第%d个元素为:%d\n",n,head->data);
        head = head->next;
        n++;
    }
}

int main()
{
    system("chcp 65001 > nul");

    //创建一个空的线性表
    Head head = NULL;
    //插入元素
    InsertHead(&head, 1);
    InsertHead(&head, 2);
    InsertHead(&head, 3);
    InsertHead(&head, 4);
    InsertHead(&head, 5);
    //输出链表
    PrintLinkList(head);
    printf("在位置2插入99后的表长为:%d\n",InsertToList(&head, 2, 99));
    printf("此时的线性表为:\n");
    PrintLinkList(head);
    //删除第四个元素
    DeleteFromList(&head, 3);
    printf("删除第四个元素后的表长为:%d\n",DeleteFromList(&head, 3));
    printf("此时的线性表为:\n");
    PrintLinkList(head);
    //显示第三个元素的前驱
    DataType prior;
    GetPriorElement(head, 3, &prior);
    printf("第三个元素的前驱为:%d\n",prior);

    DestoryLinkList(head);
    return 0;
}
