//循环队列
#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef char DataType;

typedef struct CircularQueue
{
    DataType *data;
    int front;
    int rear;
    int maxsize;
}CQ;

CQ* CreateCQ(int size)
{
    CQ* cq = new CQ;
    if(cq)
    {
        cq->data = new DataType[size];
        if(!cq->data)
        {
            delete cq;
            return NULL;
        }
        cq->front = 0;
        cq->rear = 0;
        cq->maxsize = size;
    }
    return cq;
}

void EnCQ(CQ &cq, DataType data)
{
    //1. 如果队满
    if(cq.front == (cq.rear + 1)% cq.maxsize)
    {
        cout << "队满" << endl;
    }

    //2. 入队
    cq.rear = (cq.rear +1)%cq.maxsize;
    cq.data[cq.rear] = data;
}

void DeCQ(CQ &cq, DataType* data)
{
    // 1.如果队空
    if(cq.front == cq.rear)
    {
        cout << "队空" << endl;
        *data = '\0';
        return;
    }

    // 2.出队
    cq.front = (cq.front + 1)%cq.maxsize;
    *data = cq.data[cq.front];
}

int main()
{
    system("chcp 65001 > nul");
    CQ* cq = CreateCQ(MAXSIZE);
    
    EnCQ(*cq, 'a');
    cout << "入队a" << endl;
    EnCQ(*cq, 'b');
    cout << "入队b" << endl;
    EnCQ(*cq, 'c');
    cout << "入队c" << endl;
    DataType data;
    DeCQ(*cq, &data);
    cout << data << endl;
    DeCQ(*cq, &data);
    cout << data << endl;
    DeCQ(*cq, &data);
    cout << data << endl;
    DeCQ(*cq, &data);
    cout << data << endl;
    return 0;
}