#include <iostream>
#include <cstdlib>
using namespace std;

const int ROWS = 8;
const int COLS = 8;

const int xMove[]={-2,-1,1,2,2,1,-1,-2};
const int yMove[]={1,2,2,1,-1,-2,-2,-1};

//打印最后的矩阵
void PrintMatrix(int chess[][COLS]);
//找到数组中最小的非零整数的索引位置
int MinIndexInMatrix(int a[],int clos);
//贪心算法的马踏棋盘
void WarnsdorffRole(int chess[][COLS],int startX,int startY);

int main()
{
    int chess[ROWS][COLS]={0};
    WarnsdorffRole(chess,5,1);
    PrintMatrix(chess);
    return 0;
}

void PrintMatrix(int chess[][COLS])
{
    for(int i=0;i<ROWS;++i)
    {
        for(int j=0;j<COLS;++j)
        {
            cout.width(2);
            cout.fill('0');
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int MinIndexInMatrix(int a[],int cols)
{
    int i=0,index = 0;
    int min = a[0];
    for(i=0;i<cols;++i)
    {
        if(a[i]>0)
        {
            min=a[i];
            index = i;
            break;
        }
    }
    for(i = index +1;i<cols;++i)
    {
        if(a[i]>0&&a[i]<min)
        {
            min=a[i];
            index = i;
        }
    }
    if(a[index]>0)
    {
        return index;
    }
    else
    {
        return -1;
    }
}

//贪心算法的马踏棋盘
//chess是棋盘存储矩阵，startX和startY是马的起始坐标
void WarnsdorffRole(int chess[][COLS], int startX,int startY)
{
    //下一步的X坐标和Y坐标
    int nextX[8] = {0};
    int nextY[8] = {0};
    // 再下一步的出口“数目”
    int exit[8]={0};

    //第一步的位置
    chess[startX][startY] = 1;

    int npos;//从当前位置进行一步的可选择的走法数
    //一共要走ROWS*COLS步
    for(int m=1;m<ROWS*COLS;++m)
    {
        npos=0;
        for(int i=0;i<8;++i)
        {
            //在8个可能的位置中，忽略掉那些不符合要求的
            if(startX+xMove[i]>=0&&startX+xMove[i]<ROWS&&startY+yMove[i]>=0&&startY+yMove[i]<COLS&&chess[startX+xMove[i]][startY+yMove[i]]==0)
            {
                nextX[npos] = startX+xMove[i];
                nextY[npos] = startY+yMove[i];
                ++npos;
            }
        }
        //如果一个都没有，则算法失败，没有找到解
        if(npos==0)
        {
            cout << "Can not finish the game!!" << endl;
            cout << "The steps of game can be " << m << endl;
            PrintMatrix(chess);
            std::exit(1);
        }

        int min;//再下一步的最小出口数
        //如果只有唯一的选择，直接下一步
        if(npos==1)
        {
            min = 0;
            chess[nextX[0]][nextY[0]] = m+1;
            startX = nextX[0];
            startY = nextY[0];
            continue;
        }

        int nnpos;//再下一步可能的走法数目
        //如果下一步有多个选择
        if(npos>1)
        {
            //计算下一步可能的出口数
            for(int i=0;i<npos;++i)
            {
                nnpos = 0;
                for(int j=0;j<8;++j)
                {
                    if(nextX[i]+xMove[j]>=0&&nextX[i]+xMove[j]<ROWS&&nextY[i]+yMove[j]>=0&&nextY[i]+yMove[j]<COLS&&chess[nextX[i]+xMove[j]][nextY[i]+yMove[j]]==0)
                    {
                        ++nnpos;
                    }
                }
                exit[i] = nnpos;
            }
            //选出再下一步中出口最少的，作为下一步的走法
            if((min = MinIndexInMatrix(exit,npos))>=0) 
            {
                chess[nextX[min]][nextY[min]] = m+1;
                startX = nextX[min];
                startY = nextY[min];
            }
            else//失败，所有再下一步全部走不成
            {
                cout << "Can not finish the game!!" << endl;
                cout << "The steps of game can be " << m << endl;
                PrintMatrix(chess);
                std::exit(1);
            }
        }
    }
}
