#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define N 100

void input(float y[], int m)
{
    for(int i = 0; i<m;i++)
    {
        cin >> y[i];
    }
}

void output(float a[], int x)
{
    bool isFirst = true;
    bool isAllZero = true;
    cout << fixed << setprecision(2);
    for (int i = 0; i < x; i++)
    {
        if (abs(a[i]) < 1e-7) continue;
        isAllZero = false;

        if (!isFirst && a[i] > 0) cout << "+";
        
        if (i == 0) cout << a[i];
        else if (i == 1)
        {
            if (abs(a[i] - 1.0) < 1e-7) cout << "X";
            else if (abs(a[i] + 1.0) < 1e-7) cout << "-X";
            else cout << a[i] << "X";
        }
        else
        {
            if (abs(a[i] - 1.0) < 1e-7) cout << "X^" << i;
            else if (abs(a[i] + 1.0) < 1e-7) cout << "-X^" << i;
            else cout << a[i] << "X^" << i;
        }
        isFirst = false;
    }
    if (isAllZero) cout << "0.00";
}

void division(float a[], int x, float b[], int y)
{
    float q[N] = { 0 }; //商

    for (int i = x - 1; i >= y - 1; i--)
    {
        if (abs(a[i]) < 1e-7) continue;

        float coeff = a[i] / b[y - 1];
        q[i - (y - 1)] = coeff;

        for (int j = 0; j < y; j++)
        {
            a[i - (y - 1) + j] -= coeff * b[j];
        }
    }

    output(q, x - y + 1);
    cout << endl;

    output(a, y - 1);
    cout << endl;
}

int main()
{
    float a[N] = {0}, b[N] = {0};
    int x, y;

    if (!(cin >> x)) return 0;
    input(a, x);

    if (!(cin >> y)) return 0;
    input(b, y);

    if (y == 0 || (y == 1 && abs(b[0]) < 1e-7)) {
        return 0;
    }

    division(a, x, b, y);

    return 0;
}