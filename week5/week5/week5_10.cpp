#include <iostream>
using namespace std;

int a,b,n,ans = -2000000;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a;
        if(i==1) b = a; //b为当前子序列的最大和
        else
        {
            b=max(a,a+b);
        }
        ans=max(ans,b);
    }
    cout << ans;
}