//最长公共子序列问题
#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

#define MAXLEN 100

char x[MAXLEN];
char y[MAXLEN];
int b[MAXLEN][MAXLEN];
int c[MAXLEN][MAXLEN];
int m,n;

// 初始化序列x和y
void initial()
{
    cout << "请输入第一个序列: " << endl;
    cin.getline(x,MAXLEN);
    cout << "请输入第二个序列: " << endl;
    cin.getline(y,MAXLEN);
    m = strlen(x);
    n = strlen(y);
}

//根据递推关系，求最优值，并记录相关信息
//f[i][j]记录序列x的前i个字符和序列y的前j个字符的最长公共子序列的长度
//b[i][j]记录f[i][j]是由哪个子问题的最优解得到的
void LCSLength(char *x, char *y, int m, int n, int f[][MAXLEN], int b[][MAXLEN])
{
    int i,j;

    for(i=0;i<=m;i++)
    {
        f[i][0]=0;
    }
    for(j=0;j<=n;j++)
    {
        f[0][j]=0;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                f[i][j]=f[i-1][j-1]+1;
                b[i][j]=0;
            }
            else if(f[i-1][j]>=f[i][j-1])
            {
                f[i][j]=f[i-1][j];
                b[i][j]=1;
            }
            else
            {
                f[i][j]=f[i][j-1];
                b[i][j]=-1;
            }
        }
    }
}

//根据数组b回溯得到序列的最长公共子序列
void PrintLCS(int b[][MAXLEN], char *x, int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(b[i][j]==0)
    {
        PrintLCS(b,x,i-1,j-1);
        cout << x[i-1];
    }
    else if(b[i][j]==1)
    {
        PrintLCS(b,x,i-1,j);
    }
    else
    {
        PrintLCS(b,x,i,j-1);
    }
} 

int main()
{
    SetConsoleOutputCP(65001);
    initial();
    LCSLength(x,y,m,n,c,b);
    cout << "最长公共子序列是: ";
    PrintLCS(b,x,m,n);
    cout << endl;
    return 0;
}
