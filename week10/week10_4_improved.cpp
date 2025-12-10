#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    int a[1000];
    for(int i=1;i<=k+1;i++)
    {
        cin >> a[i];
    }

    //检查是否有无法跨越的路段
    for(int i=1;i<=k+1;i++)
    {
        if(a[i] > n)
        {
            cout << "无解！" << endl;
            return 0;
        }
    }

    int pos = 0; //当前所在加油站编号，起点为0
    int cnt = 0; //加油次数
    
    while(pos<k+1)
    {
        int next = pos;
        int dist = 0;

        //找到最远能到达的加油站
        while(next+1 < k+1 && dist+a[next+1] <= n)
        {
            next++;
            dist += a[next];
        }

        //已到达终点，不用加油
        if(next == k+1)
        {
            break;
        }

        //必须在next加油
        cnt++;
        pos = next;
    }

    return 0;
}