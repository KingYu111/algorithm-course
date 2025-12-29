#include <iostream>

using namespace std;

int dp[105][1005];
int v[105],w[105];

int main()
{
    int n,W;
    cin >> n >> W;

    for(int i=1;i<=n;i++)
    {
        cin >> v[i] >> w[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(j<w[i])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }

    cout << dp[n][W] << endl;

    int j = W;
    for(int i = n; i >= 1; i--) 
    {
        if(dp[i][j] != dp[i-1][j]) 
        { // 说明选了第 i 件
            cout << i << " ";
            j -= w[i];
        }
    }
    return 0;
}