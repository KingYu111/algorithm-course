#ifndef QUEUE_H
#define QUEUE_H

typedef char DataType;//字符型循环队列

typedef struct QUEUE
{
    DataType* queArray;
    int front;
    int rear;
    int maxLength;
}Queue;

Queue* CreateQueue(int length);
void DestoryQueue(Queue* queue);
void ClearQueue(Queue* queue);
int GetQueueLength(Queue* queue);
void EnQueue(Queue* queue, DataType data);
DataType DlQueue(Queue* queue);
DataType GetQueueHead(Queue* queue);

#endif