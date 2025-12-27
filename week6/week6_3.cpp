#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

const int MAXLENGTH = 100;

typedef int DataType;

typedef struct List
{
    DataType* list;
    int length;
    int maxLength;
}List;

List* CreateList(int length)
{
    List* list = (List*)malloc(sizeof(List));
    if(list)
    {
        list->list = (DataType*)malloc(sizeof(DataType)*length);
        if(!list->list)
        {
            free(list);
            return NULL;
        }
    }

    list->length = 0;
    list->maxLength = length;
    return list;
}

void DisplayList(List* list)
{
    if(list)
    {
        for(int i = 0; i < list->length; ++i)
        {
            if(i == list->length - 1)
            {
                printf("%d", list->list[i]);
            }
            else
            {
                printf("%d ", list->list[i]);
            }
        }
    }
}

void InsertToList(List* list, int pos, DataType data)
{
    if(list)
    {
        if(pos < 0 || pos > list->length)
        {
            cout << "插入位置错误" << endl;
            return;
        }

        for(int i= list->length -1; i>=pos; ++i)
        {
            list->list[i+1] = list->list[i];
        }
        list->list[pos] = data;
        list->length++;
    }
}

void DeleteFromList(List *list, int pos)
{
    if(list)
    {
        if(pos < 0 || pos >= list->length)
        {
            cout << "删除位置错误" << endl;
            return;
        }
        for(int i=pos; i<list->length-1; ++i)
        {
            list->list[i] = list->list[i+1];
        }

        list->length--;
    }
}

int FindItemDelete(List* list, int num)
{
    if(list)
    {
        for(int i=0;i<list->length;i++)
        {
            if(list->list[i] == num)
            {
                DeleteFromList(list, i);
            }
        }
        return 1;
    }
    return 0;
}

int DestoryList(List* list)
{
    if(list)
    {
        free(list->list);
        free(list);
        return 1;
    }
    return 0;
}

int main()
{
    system("chcp 65001 > nul");
    List* list = CreateList(MAXLENGTH);
    for(int i=0;i<3;i++)
    {
        int n;
        cin >> n;
        InsertToList(list, i, n);
    }

    DisplayList(list);
    cout << endl;

    int del;
    cin >> del;
    FindItemDelete(list, del);
    DisplayList(list);
}



