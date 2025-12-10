#include <iostream>
using namespace std;

int n,a,b,ans = -100;

int main()
{
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> a;

        if(i == 1) b = a;
        else 
        {
            b = max(b , a+b);
        }
        ans  = max(ans , b);
    }
    cout << ans << endl;
}