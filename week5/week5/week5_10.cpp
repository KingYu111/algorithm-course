//DP
//子问题结构：以第 i 个元素结尾的最佳解依赖于第 i−1 个的最佳解。
//最优子结构：全局最大值是所有局部最大值（b）的最大。
//状态转移方程：b = max(a, a+b)

// #include <iostream>
// using namespace std;

// int a,b,n,ans = -2000000;

// int main()
// {
//     cin >> n;
//     for(int i=1;i<=n;i++)
//     {
//         cin >> a;
//         if(i==1) b = a; //b以当前元素结尾的最大子列和
//         else
//         {
//             b=max(a,a+b);//状态转移方程
//         }
//         ans=max(ans,b);//所有b中最大的
//     }
//     cout << ans;
// }

//显示始末位置的版本
#include <iostream>
using namespace std;


int main()
{
    int n;
    cin >> n;

    int a;
    int dp;                 // 以当前结尾的最大子段和
    int ans = -2000000000;  // 全局最大
    int start = 1, end = 1; // 最终区间
    int tempStart = 1;      // 当前子段开始位置

    for(int i = 1; i <= n; i++)
    {
        cin >> a;

        if(i == 1)
        {
            dp = a;
            tempStart = 1;
        }
        else
        {
            // 是否需要从当前重新开始？
            if(a > dp + a)
            {
                dp = a;
                tempStart = i;
            }
            else
            {
                dp = dp + a;
            }
        }

        // 是否找到更大的全局最大？
        if(dp > ans)
        {
            ans = dp;
            start = tempStart;
            end = i;
        }
    }

    cout << "最大和 = " << ans << endl;
    cout << "区间 = [" << start << ", " << end << "]" << endl;

    return 0;
}
