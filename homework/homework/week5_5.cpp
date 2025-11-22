/*#include <cstdio>
#include <iostream>
using namespace std;
int ispalindrome(int n)
{
    int re = 0, ori = n;
    while (n > 0) {
        re = re * 10 + n % 10;
        n = n / 10;
    }
    return (re == ori);
}
int main()
{
    int n, p = 1;
    scanf("%d", &n);
    
    if (ispalindrome(n)) {
        cout << 1;
    }
    else cout << 0;
    
    return 0;
}
*/