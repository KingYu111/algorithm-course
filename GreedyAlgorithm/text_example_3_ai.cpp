#include <iostream>
#include <cstdlib>
#include <vector>

const int ROWS = 8;
const int COLS = 8;

const int xMove[]={-2,-1,1,2,2,1,-1,-2};
const int yMove[]={1,2,2,1,-1,-2,-2,-1};

//打印最后的矩阵
void PrintMatrix(int chess[][COLS]);
//找到数组中最小的非零整数的索引位置
int MinIndexInMatrix(int a[],int clos);
//贪心算法的马踏棋盘
bool WarnsdorffRole(int chess[][COLS],int startX,int startY);

int main(int argc, char* argv[])
{
    int startX = 0, startY = 0;
    if (argc == 3) {
        startX = std::atoi(argv[1]);
        startY = std::atoi(argv[2]);
    }

    int chess[ROWS][COLS]={0};
    if (WarnsdorffRole(chess,startX,startY)) {
        PrintMatrix(chess);
    } else {
        std::cout << "Could not find a solution for start position (" << startX << ", " << startY << ")" << std::endl;
    }
    return 0;
}

void PrintMatrix(int chess[][COLS])
{
    for(int i=0;i<ROWS;++i)
    {
        for(int j=0;j<COLS;++j)
        {
            std::cout.width(2);
            std::cout.fill('0');
            std::cout << chess[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int MinIndexInMatrix(int a[],int cols)
{
    int i=0,index = 0;
    int minValue = a[0];
    for(i=0;i<cols;++i)
    {
        if(a[i]>0)
        {
            minValue=a[i];
            index = i;
            break;
        }
    }
    for(i = index +1;i<cols;++i)
    {
        if(a[i]>0&&a[i]<minValue)
        {
            minValue=a[i];
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
bool WarnsdorffRole(int chess[][COLS], int startX,int startY)
{
    //下一步的X坐标和Y坐标
    std::vector<int> nextX;
    std::vector<int> nextY;
    // 再下一步的出口“数目”
    std::vector<int> exit;

    //第一步的位置
    chess[startX][startY] = 1;

    //一共要走ROWS*COLS步
    for(int m=1;m<ROWS*COLS;++m)
    {
        nextX.clear();
        nextY.clear();
        for(int i=0;i<8;++i)
        {
            //在8个可能的位置中，忽略掉那些不符合要求的
            if(startX+xMove[i]>=0&&startX+xMove[i]<ROWS&&startY+yMove[i]>=0&&startY+yMove[i]<COLS&&chess[startX+xMove[i]][startY+yMove[i]]==0)
            {
                nextX.push_back(startX+xMove[i]);
                nextY.push_back(startY+yMove[i]);
            }
        }
        //如果一个都没有，则算法失败，没有找到解
        if(nextX.empty())
        {
            std::cout << "Can not finish the game!!" << std::endl;
            std::cout << "The steps of game can be " << m << std::endl;
            PrintMatrix(chess);
            return false;
        }

        int minIndex;//再下一步的最小出口数
        //如果只有唯一的选择，直接下一步
        if(nextX.size()==1)
        {
            minIndex = 0;
            chess[nextX[0]][nextY[0]] = m+1;
            startX = nextX[0];
            startY = nextY[0];
            continue;
        }

        int nextPossibleMovesCount;//再下一步可能的走法数目
        //如果下一步有多个选择
        if(nextX.size()>1)
        {
            exit.clear();
            //计算下一步可能的出口数
            for(size_t i=0;i<nextX.size();++i)
            {
                nextPossibleMovesCount = 0;
                for(int j=0;j<8;++j)
                {
                    if(nextX[i]+xMove[j]>=0&&nextX[i]+xMove[j]<ROWS&&nextY[i]+yMove[j]>=0&&nextY[i]+yMove[j]<COLS&&chess[nextX[i]+xMove[j]][nextY[i]+yMove[j]]==0)
                    {
                        ++nextPossibleMovesCount;
                    }
                }
                exit.push_back(nextPossibleMovesCount);
            }
            //选出再下一步中出口最少的，作为下一步的走法
            if((minIndex = MinIndexInMatrix(exit.data(), exit.size()))>=0) 
            {
                chess[nextX[minIndex]][nextY[minIndex]] = m+1;
                startX = nextX[minIndex];
                startY = nextY[minIndex];
            }
            else//失败，所有再下一步全部走不成
            {
                std::cout << "Can not finish the game!!" << std::endl;
                std::cout << "The steps of game can be " << m << std::endl;
                PrintMatrix(chess);
                return false;
            }
        }
    }
    return true;
}
