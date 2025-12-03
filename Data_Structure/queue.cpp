#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/**
 *@brief 创建一个队列
 *@param length 队列的最大长度
 *@return Queue* 队列的指针
 */
Queue* CreateQueue(int length)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(queue)
    {
        queue->queArray = (DataType*)malloc(sizeof(DataType) * length);
        if(!queue->queArray)
        {
            free(queue);
            return NULL;
        }
        queue->front = 0;
        queue->rear = 0;
        queue->maxLength = length;
    }
    return queue;
}

/**
 *@brief 销毁队列
 *@param queue 队列的指针
 */
void DestoryQueue(Queue* queue)
{
    free(queue->queArray);
    free(queue);
}

/**
 *@brief 清空队列
 *@param queue 队列的指针
 */
void ClearQueue(Queue* queue)
{
    if(queue)
    {
        queue->front = 0;
        queue->rear = 0;
    }
}

/**
 *@brief 获取队列的长度
 *@param queue 队列的指针
 *@return int 队列的长度
 */
int GetQueueLength(Queue* queue)
{
    return queue->rear >= queue->front ?
            queue->rear - queue->front :
            queue->maxLength - (queue->front - queue->rear);
}

/**
 *@brief 入队
 *@param queue 队列的指针
 *@param data 要入队的数据
 */
void EnQueue(Queue* queue, DataType data)
{
    if((queue->rear+1)%queue->maxLength != queue->front)
    {
        queue->queArray[queue->rear] = data;
        queue->rear = (queue->rear+1)%queue->maxLength;
    }
    else
    {
        printf("队列已满，无法入队\n");
    }
}

/**
 *@brief 出队
 *@param queue 队列的指针
 *@return 出队的元素值，如队空，返回0
 */
DataType DlQueue(Queue* queue)
{
    if(GetQueueLength(queue) >0)
    {
        queue->front = (queue->front+1)%queue->maxLength;
        return queue->queArray[queue->front-1];
    }
    else
    {
        printf("队列已空，无法出队\n");
        return 0;
    }
}

/**
 *@brief 获取队列的头元素
 *@param queue 队列的指针
 *@return DataType 队列的头元素值，如队空，返回0
 */
DataType GetQueueHead(Queue* queue)
{
    if(GetQueueLength(queue) >0)
    {
        return queue->queArray[(queue->front+1)%queue->maxLength];
    }
    else
    {
        printf("队列已空，无法获取头元素\n");
        return 0;
    }
}

int main()
{
    system("chcp 65001 > nul");
    const int QueueMax = 100;

    Queue* queue = CreateQueue(QueueMax);
    if(queue == NULL)
    {
        printf("创建队列失败\n");
        return 0;
    }

    printf("请输入不超过10个字符作为入队列字符:\n");
    char ch[10];
    scanf("%s", ch);
    for(int i = 0; i < strlen(ch); i++)
    {
        EnQueue(queue, ch[i]);
    }
    printf("出队顺序为:\n");
    while(GetQueueLength(queue) > 0)
    {
        printf("出队:%c\n", DlQueue(queue));
    }
    printf("\n");
    DestoryQueue(queue);
    return 0;
}
