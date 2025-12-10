/*
1).题目

一辆汽车加满油后可行驶n公里。旅途中有k个加油站。设计一个有效算法，指出应

在哪些加油站停靠加油，使沿途加油次数最少。对于给定的n(n <= 5000)和k(k <= 1000)个加油站位置，编程计算最少加油次数。

输入：

第一行有2个正整数n和k，表示汽车加满油后可行驶n公里，旅行中途有k个加油站。另外，第0 个加油站表示出发地（汽车油已加满），第k+1 个加油站为目的地。接下来的1 行中，有k+1 个整数，表示第k个加油站与第k-1 个加油站之间的距离。

输出：

输出编程计算出的最少加油次数。如果无法到达目的地，则输出“无解！”。

样本输入：

（汽车加满油后可行驶n公里和k个加油站:----------注：此行不显示）

600 6

（7个加油站彼此之间的距离:----------注：此行不显示）

300 200 100 500 200 100 90

样本输出：

最少加油次数：2

思路

汽车行驶过程中，应走到自己能走到并且离自己最远的那个加油站，在那个加油站加油后再按照同样的贪心方法。

 2).实验内容与要求

  算法

  具体算法：

先检测各加油站之间的距离，若发现其中有一个距离大于汽车加满油能跑的距离，则输出“无解！”，否则，对加油站间的距离进行逐个扫描，尽量选择往远处走，不能走了就让num++，最终统计出来的num便是最少的加油站数。

 3). 编程实现上述方案        


样例输入：
600 6
300 200 100 500 200 100 90
样例输出：
2
*/
#include <iostream>
using namespace std;

int main()
{
    //读取数据
    int n,k=0;
    cin >> n >> k;
    int a[100];
    int total_distance = 0;
    a[0] = 0;
    for(int i=1;i<=k+1;i++)
    {
        cin >> a[i];
        total_distance += a[i];
    }

    //cout << "total_distance:" << total_distance << endl;
    //判断
    int ok = 1;
    int num = -1;
    int able_to_reach_index = 0;
    for(int i=0;i<k+1;i++)
    {
        if(i == able_to_reach_index)
        {
            //cout << "i:" << i << endl;
            int current_distance = 0;
            if( a[i+1] > n)
            {
                ok = 0;
                break;
            }
            for(int j = i+1;j<=k+1;j++)
            {
                
                current_distance += a[j];
                if(current_distance <= n)
                {
                    able_to_reach_index = j;
                }
                else break;
                //cout << "able_to_reach_index:" << able_to_reach_index << endl;
            }
            num++;
        }
    }
    if(ok == 0)
    {
        cout << "无解!" << endl;
    }
    else cout << num << endl;
    return 0;
}
