#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义一个字符栈
typedef char DataType;
//定义栈
typedef struct STACK
{
    DataType* stackArray;
    int top;
    int maxLength;
}Stack;

//声明函数
Stack* CreateStack(int length);
void ClearStack(Stack* stack);
void DestoryStack(Stack* stack);
int Pop(Stack* stack, DataType* data);
void Push(Stack* stack, DataType data);
int GetLength(Stack* stack);
int GetStackPeek(Stack* stack, DataType* data);

// 函数的实现
/**
 *@brief 创建一个栈
 *@param length 栈的最大长度
 *@return Stack* 栈的指针
*/
Stack* CreateStack(int length)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack)
    {
        stack->stackArray = (DataType*)malloc(sizeof(DataType) * length);
        if(!stack->stackArray)
        {
            free(stack);
            return NULL;
        }
        stack->top = -1;//置为空栈
        stack->maxLength = length;
    }
    return stack;
}
/**
 *@brief 清空栈
 *@param stack 栈的指针
*/
void ClearStack(Stack* stack)
{
    if(stack)
    {
        stack->top = -1;//置为空栈
    }
}
/**
 *@brief 销毁栈
 *@param stack 栈的指针
*/
void DestoryStack(Stack* stack)
{
    if(stack)
    {
        free(stack->stackArray);
        free(stack);
    }
}
/**
 *@brief 弹出栈顶元素
 *@param stack 栈的指针
 *@param data 弹出的元素
 *@return 弹出的栈顶元素，失败返回0
*/
int Pop(Stack* stack, DataType* data)
{
    if(stack)
    {
        //先判断栈是否为空
        if(stack->top == -1)
        {
            return 0;
        }
        *data = stack->stackArray[stack->top];
        stack->top--;
        return 1;
    }
    return 0;
}
/**
 *@brief 压栈
 *@param stack 栈的指针
 *@param data 压栈的元素
*/
void Push(Stack* stack, DataType data)
{
    if(stack)
    {
        //先判断栈是否已满
        if(stack->top == stack->maxLength - 1)
        {
            return;
        }
        stack->top++;
        stack->stackArray[stack->top] = data;
    }
}
/**
 *@brief 获取栈的长度
 *@param stack 栈的指针
 *@return int 栈的长度
*/
int GetLength(Stack* stack)
{
    if(stack)
    {
        return stack->top + 1;
    }
    return 0;
}
/**
 *@brief 获取栈的栈顶元素
 *@param stack 栈的指针
 *@param data 栈顶元素
 *@return int 栈顶元素，失败返回0
*/
int GetStackPeek(Stack* stack, DataType* data)
{
    if(stack)
    {
        //先判断栈是否为空
        if(stack->top == -1)
        {
            return 0;
        }
        *data = stack->stackArray[stack->top];
        return 1;
    }
    return 0;
}

int main()
{
    system("chcp 65001 > nul");
    const int MAXLENGTH = 100;
    Stack* stack = CreateStack(MAXLENGTH);
    if(!stack)
    {
        printf("create stack failed");
        return -1;
    }
    printf("连续输入不超过10个字符作为入栈字符\n");
    char input[10];
    scanf("%s",input);
    //将输入的字符压栈
    for(int i = 0;i<strlen(input);i++)
    {
        Push(stack,input[i]);
    }
    //将栈中的字符出栈
    DataType data;
    while(GetStackPeek(stack,&data))
    {
        Pop(stack,&data);
        printf("%c",data);
    }
    printf("\n");
    DestoryStack(stack);
    return 0;
}
