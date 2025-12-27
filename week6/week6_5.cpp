#include <iostream>
using namespace std;

typedef int DataType;

typedef struct Point{
    int x;
    int y;
}Point;
typedef struct Stack
{
    Point *data;
    int top;
    int maxsize;
}Stack;

Stack* CreateStack(int maxsize)
{
    Stack* stack = new Stack;
    
    if(stack)
    {
        stack->data = new Point[maxsize];
        if(!stack->data)
        {
            delete stack;
            return NULL;
        }
        stack->top = -1;
        stack->maxsize = maxsize;
    }
    
    return stack;
}

int Pop(Stack* stack, Point* point)
{
    if(stack)
    {
        if(stack->top == -1)
        {
            return -1;
        }
        *point = stack->data[stack->top];
        stack->top--;
        return 1;
    }

    return -1;
}

int Push(Stack* stack, Point* point)
{
    if(stack)
    {
        if(stack->top == stack->maxsize - 1)
        {
            return -1;
        }
        stack->top++;
        stack->data[stack->top] = *point;
        return 1;
    }
    return -1;
}

int main()
{
    system("chcp 65001 > nul");

    Stack* stack = CreateStack(3);

    cout << "请输入三对坐标：" << endl;
    for(int i = 0; i<3;i++)
    {
        int x,y;
        cin >> x >> y;
        Point point;
        point.x = x;
        point.y = y;
        Push(stack, &point);
        cout << "入栈：" << point.x << "," << point.y << endl;
    }
    cout << "入栈结束" << endl;

    for(int i=0;i<3;i++)
    {
        Point point;
        Pop(stack, &point);
        cout << "出栈：" << point.x << "," << point.y << endl;
    }
    cout << "出栈结束" << endl;
    
    delete[] stack->data;
    delete stack;
}