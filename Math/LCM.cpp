// 求最小公倍数
#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;

    int max = a>b?a:b;
    int _lcm = a*b;

    for(int i=max;i<=a*b;i++)
    {
        if(i%a==0&&i%b==0)
        {
            _lcm = i;
            break;
        }
    }
    cout << _lcm << endl;
    return 0;
}

// 事实上，最小公倍数可以用最大公约数来求
// a*b = gcd(a,b)*lcm(a,b)
// gcd(a,b)用辗转相除法求得
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

// 最小公倍数 = a*b/gcd(a,b)
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}