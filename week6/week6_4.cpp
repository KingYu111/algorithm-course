#include <iostream>

using namespace std;

typedef int DataType;

typedef struct Info
{
    int id;
    string name;
}Info;
typedef struct Node
{
    Info info;
    Node* next;
}Node;

typedef Node* Head;

int GetLinkListLength(Head head)
{
    if(head == NULL)
    {
        return 0;
    }
    int i = 1;
    Node* pNode = head;
    while(pNode->next != NULL)
    {
        i++;
        pNode = pNode->next;
    }
    return i;
}

void InsertToListAndSort(Head* head, Info info)
{
    
    Node* newNode = new Node;
    if(newNode == NULL)
    {
        printf("内存非配失败");
    }
    newNode->info = info;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    if(info.id > (*head)->info.id)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* tempNode = *head;
    while(tempNode->next != NULL && tempNode->next->info.id > info.id)
    {
        tempNode = tempNode->next;
    }
   
    newNode->next = tempNode->next;
    tempNode->next = newNode;
    //printf("插入成功");
}

void InsertHead(Head* head, Info info)
{
    Node* newNode = new Node;
    if(newNode)
    {
        newNode->info = info;
        newNode->next = *head;
        *head = newNode;
    }
    else 
    {
        printf("内存分配失败");
    }
}

void InsertRear(Head* head, Info info)
{
    Node* tempNode = *head;
    Node* newNode = new Node;
    if(newNode == NULL)
    {
        printf("内存分配失败");
    }
    else
    {
        newNode->info = info;
        newNode->next = NULL;
    }

    int len = GetLinkListLength(*head);

    if(len == 0)
    {
        *head = newNode;
        return;
    }
    
    for(int i=0;i<len-1;i++)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
}

void DeleteFromList(Head* head, int id)
{
    Node* tempNode = *head;
    int len = GetLinkListLength(*head);
    if(len == 0)
    {
        printf("链表为空");
        return;
    }

    if((*head)->info.id == id)
    {
        Node* delNode = *head;
        *head = (*head)->next;
        delete delNode;
        //printf("删除成功");
        return;
    }
    
    while(tempNode->next != NULL && tempNode->next->info.id != id)
    {
        tempNode = tempNode->next;
    }

    if(tempNode->next == NULL)
    {
        printf("未找到该元素");
        return;
    }
    
    Node* delNode = tempNode->next;
    tempNode->next = tempNode->next->next;
    delete delNode;
    //printf("删除成功");
}

void PrintList(Head head)
{
    if(head == NULL)
    {
        printf("链表为空");
        return;
    }
    Node* pNode = head;
    while(pNode != NULL)
    {
        cout << pNode->info.id << " " << pNode->info.name << endl;
        pNode = pNode->next;
    }
}

int main()
{
    system("chcp 65001 > nul");
    Head head = NULL;
    
    for(int i=0;i<3;i++)
    {
        Info tempinfo;
        cin >> tempinfo.id >> tempinfo.name;
        InsertToListAndSort(&head, tempinfo);
    }
    int delid;
    cin >> delid;
    PrintList(head);
    
    cout << endl;
    DeleteFromList(&head, delid);
    PrintList(head);

    return 0;
}