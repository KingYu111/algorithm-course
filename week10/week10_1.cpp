#include <iostream>
using namespace std;

int main()
{
    double n;
    cin >> n;

    int pay = ((int)(n / 100) + 1) * 100 * 100;
    int change = pay - (int)(n * 100);

    int cent[] = {5000, 2000, 1000, 500, 100,50, 10};
    int count = 0;
    int remain = change;

    for(int money : cent)
    {
        if(remain >= money)
        {
            int num = remain/money;
            count += num;
            remain -= num * money;
        }
        if(remain == 0) break;
    }

    cout << count << endl;
    return 0;
}