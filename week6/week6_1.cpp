#include <stdio.h>
#include <stdlib.h>
#include <cstring>

typedef char DataType;

typedef struct List
{
    DataType *list;     //指向线性表的指针
    int length;         //表长
    int maxLength;      //表容量
} ListType;

ListType* CreateList(int maxLength)
{
    ListType *sqlist = (ListType *)malloc(sizeof(ListType));
    if(sqlist == NULL)
    {
        printf("内存分配失败");
        return NULL;
    }

    sqlist->list = (DataType *)malloc(maxLength * sizeof(DataType));
    if(sqlist->list == NULL)
    {
        printf("内存分配失败");
        return NULL;
    }

    sqlist->length = 0;
    sqlist->maxLength = maxLength;
    return sqlist;
}

void Insert(ListType *chL, int i, char ch)
{
    if(i < 0 || i > chL->length)
    {
        printf("插入位置错误");
        return;
    }

    if(chL->length == chL->maxLength)
    {
        printf("线性表已满");
        return;
    }
    
    for(int j = chL->length - 1; j >=i;j--)
    {
        chL->list[j+1] = chL->list[j];
    }
    chL->list[i] = ch;
    chL->length++;
}

void Delete(ListType *L, int i)
{
    if( i < 0 || i > L->length - 1)
    {
        printf("删除位置错误");
        return;
    }

    for(int j = i; j < L->length - 1; j++)
    {
        L->list[j] = L->list[j+1];
    }
    L->length--;
}

int Locate(ListType L, char x)
{
    for(int i = 0; i < L.length; i++)
    {
        if(L.list[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void Show(ListType chL)
{
    for(int i=0;i<chL.length;i++)
    {
        printf("%c",chL.list[i]);
    }   
}

int main()
{
    const int MAXLENGTH = 1000;
    ListType *chL = CreateList(MAXLENGTH);

    char input[1000];
    fgets(input, sizeof(input), stdin);   //gets()在学校系统里编译不过去
    input[strlen(input)- 1] = '\0';
    for(int i=0;i<strlen(input);i++)
    {
        Insert(chL,i,input[i]);
    }
    Show(*chL);
    printf("\n");
    printf("%d\n",chL->length);

    char x;
    scanf("%c",&x);
    for(int i = chL->length - 1;i>=0;i--)
    {
        if(chL->list[i] == x)
        {
            Delete(chL,i);
        }
    }
    Show(*chL);
    printf("\n");
    printf("%d",chL->length);


}