/*
利用顺序栈将十进制整数转换为二进制数。
要求：至少实现以下操作：
置空栈、入栈、出栈，计算表长。
输入输出样例：
输入为：
30
输出：
表长：5
二进制：11110
*/
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

typedef int DataType;

typedef struct STACK
{
    DataType* stackArray;//栈数组
    int top;//栈顶指针
    int maxLength;//栈最大长度
} Stack;

//声明函数
Stack* CreateStack(int length);
void ClearStack(Stack* stack);
void DestoryStack(Stack* stack);
int Pop(Stack* stack, DataType* data);
void Push(Stack* stack, DataType data);
int GetLength(Stack* stack);
int GetStackPeek(Stack* stack, DataType* data);

Stack* CreateStack(int maxLength)
{
    Stack* stack = (Stack *)malloc(sizeof(Stack));
    if(stack)
    {
        stack->stackArray = (DataType*)malloc(sizeof(DataType)*maxLength);
        if(!stack->stackArray)
        {
            free(stack);
            return NULL;
        }
        stack->top = -1;
        stack->maxLength = maxLength;
    }
    return stack;
}

void ClearStack(Stack* stack)
{
    if(stack)
    {
        stack->top = -1;//置为空栈
    }
}

void DestoryStack(Stack* stack)
{
    if(stack)
    {
        if(stack->stackArray)
        {
            free(stack->stackArray);
        }
        free(stack);
    }
}

int Pop(Stack* stack, DataType* data)
{
    if(stack && stack->top != -1)//如果不是NULL且栈不为空
    {
        *data = stack->stackArray[stack->top];
        stack->top--;
        return 1;
    }
    return 0;
}

void Push(Stack* stack, DataType data)
{
    if(stack && stack->top != stack->maxLength-1)//如果不是NULL且栈未满
    {
        stack->top++;
        stack->stackArray[stack->top] =data;
    }
}

int Getlength(Stack* stack)
{
    if(stack)//如果不是NULL
    {
        return stack->top + 1;
    }
    return 0;
}

int GetStackPeek(Stack* stack, DataType* data)
{
    if(stack && stack->top != -1)//如果不是NULL且栈不为空
    {
        *data = stack->stackArray[stack->top];
        return 1;
    }
    return 0;
}



int main()
{
    int n;
    scanf("%d",&n);
    Stack* stack = CreateStack(100);
    while(n)
    {
        Push(stack,n%2);
        n /=2;
    }
    while(Getlength(stack))
    {
        DataType data;
        Pop(stack,&data);
        printf("%d",data);
    }
    return 0;
}