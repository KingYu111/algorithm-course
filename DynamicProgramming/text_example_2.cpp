//0-1背包问题
#include <stdio.h>

int c[101][1001];//对应每种情况的最大价值，其中程序限定能处理的最多物品数为100，最大价值为1000
int m,n;//m表示背包可承受的最大质量，n表示物品数
int w[101];//每个物品的重量
int v[101];//每个物品的价值
int x[101];//物品是否放入背包，是用1表示，反之用0

/*初始化条件*/
void init()
{
    int i;
    printf("input the max capacity and the number of the goods:\n");
    scanf("%d %d",&m,&n);
    printf("input the weight and the value of each goods:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&w[i],&v[i]);
    }
}

int min(int a, int b)
{
    return a<b?a:b;
}

int max(int a, int b)
{
    return a>b?a:b;
}

/*
寻找每个子问题的最优解
c[i][j]表示背包容量为j，可选择物品为i,i+1,...,n的最大价值
0-1背包问题的最优值为c[1][m]
*/
void knapsack()
{
    int jMax = min(w[n]-1,m);//背包可承受最大重量和物体n的重量-1中较小数
    int i,j;
    //初始化c[n][j]
    //当j<jMax时，c[n][j]=0
    //假设jMax=w[n]-1,即背包可以容纳物体n,则在j<=jMax时，c[n][j]=0,w[n]<=j<=m时，c[n][j]=v[n]
    for(j=0;j<=jMax;j++)
    {
        c[n][j]=0;
    }
    for(j=w[n];j<=m;j++)
    {
        c[n][j]=v[n];
    }
    //自底向上计算其他子问题的最优值
    for(i=n-1;i>=1;i--)
    {
        jMax=min(w[i]-1,m);
        for(j=0;j<=jMax;j++)
        {
            c[i][j]=c[i+1][j];
        }
        for(j=w[i];j<=m;j++)
        {
            c[i][j]=max(c[i+1][j],c[i+1][j-w[i]]+v[i]);
        }
    }
}

/*
构造最优解
*/
void traceBack()
{
    int i,j;
    j = m;
    for(i=1;i<n;i++)
    {
        if(c[i][j]==c[i+1][j])
        {
            x[i]=0;
        }
        else
        {
            x[i]=1;
            j=j-w[i];
        }
    }
    x[n] = (j >= w[n]) ? 1 : 0;
}

int main()
{
    int i,j;
    init();
    knapsack();
    traceBack();
    printf("the max value is: %d\n",c[1][m]);
    printf("the goods is:\n");
    for(i=1;i<=n;i++)
    {
        if(x[i]!=0)
        {
            printf("%d ",i);
        }
    }

    return 0;
}
