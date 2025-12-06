#include <iostream>
#include <cstdio>

using namespace std;

int m = 90;//背包容量
int n;//物品数
int w[101];//重量
int v[101];//价值	
double x[101];//第i个物品取的比例
int idx[101];// 记录物品的编号，用于排序，按价值密度从大到小排序

void init()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> v[i];
		idx[i] = i;//初始化编号数组
	}
	for(int i=1;i<=n;i++)
	{
		cin >> w[i];
	}
}

void swap(int* a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Value_Sort()
{
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			double ratio1 = (double)v[idx[j]] / (double)w[idx[j]];
			double ratio2 = (double)v[idx[j+1]] / (double)w[idx[j+1]];
			if(ratio1<ratio2)
			{
				swap(&idx[j],&idx[j+1]);
			}
		}
	}
}

void FractionalKnapsack()
{
    int remaining = m;
	double totalValue = 0.0f;

	for(int i=1;i<=n;i++)
	{
		x[i] = 0.0f;
	}

	for(int i=1;i<=n;i++)
	{
		int id = idx[i];

		if(remaining == 0) break;
		
		if(remaining >= w[id])
		{
			x[id] = 1.0f;
			totalValue += v[id];
			remaining -= w[id];
		}
		else
		{
			x[id] = (double)remaining/(double)w[id];
			totalValue += (double)remaining/(double)w[id] * (double)v[id];
			remaining = 0;
		}
	}
}

int main()
{
	
	init();
	Value_Sort();
	FractionalKnapsack();

	int blank_flag = 0;
	for(int i=1;i<=n;i++)
	{
		if(!blank_flag)
		{
			printf("x[%d]",i);
			blank_flag = 1;
		}
		else
		{
			printf(" x[%d]",i);
		}
		if(i == n) printf("\n");
	}
	blank_flag = 0;
	for(int i=1;i<=n;i++)
	{
		if(!blank_flag)
		{
			printf("%.3f",x[i]);
			blank_flag = 1;
		}
		else
		{
			printf(" %.3f",x[i]);
		}
	}
	return 0;
}
