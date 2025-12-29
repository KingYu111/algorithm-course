#include <iostream>
#include <cmath>

using namespace std;

// 判断一个数是否为素数
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void seive(int n)
{
    bool* isprime = new bool[n+1];
    for(int i=2;i<=n;i++)
    {
        isprime[i] = true;
    }
    for(int i=2;i<n;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                isprime[j] = false;
            }
        }
    }
}

int main() {
    int N;
    // 输入整数 N
    if (!(cin >> N)) return 0;

    // 输出比 N 小的所有素数
    bool first = true;
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << endl;

    return 0;
}
