#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define MAX_DEG 200 // 定义最大阶数

// 输入多项式系数
void input(float poly[], int n) {
    for (int i = 0; i <= n; i++) {
        cin >> poly[i];
    }
}

// 输出多项式
void output(float poly[], int n) {
    bool isFirst = true;
    bool isAllZero = true;
    cout << fixed << setprecision(2);
    for (int i = 0; i <= n; i++) {
        if (abs(poly[i]) < 1e-7) continue;
        isAllZero = false;

        if (!isFirst && poly[i] > 0) cout << "+";

        if (i == 0) cout << poly[i];
        else if (i == 1) {
            if (abs(poly[i] - 1.0) < 1e-7) cout << "X";
            else if (abs(poly[i] + 1.0) < 1e-7) cout << "-X";
            else cout << poly[i] << "X";
        } else {
            if (abs(poly[i] - 1.0) < 1e-7) cout << "X^" << i;
            else if (abs(poly[i] + 1.0) < 1e-7) cout << "-X^" << i;
            else cout << poly[i] << "X^" << i;
        }
        isFirst = false;
    }
    if (isAllZero) cout << "0.00";
    cout << endl;
}

// 多项式乘法：res = poly1 * poly2
void multiplication(float poly1[], int n1, float poly2[], int n2, float res[]) {
    // 初始化结果数组为0
    for (int i = 0; i <= n1 + n2; i++) res[i] = 0;

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            res[i + j] += poly1[i] * poly2[j];
        }
    }
}

// 多项式除法：a = q * b + r
// a 为被除数（执行后变为余数 r），q 为商
void division(float a[], int n, float b[], int m, float q[]) {
    // 初始化商为0
    for (int i = 0; i <= n - m; i++) q[i] = 0;

    if (m < 0 || (m == 0 && abs(b[0]) < 1e-7)) return;

    for (int i = n; i >= m; i--) {
        if (abs(a[i]) < 1e-7) continue;

        float coeff = a[i] / b[m];
        q[i - m] = coeff;

        for (int j = 0; j <= m; j++) {
            a[i - m + j] -= coeff * b[j];
        }
    }
}

int main() {
    system("chcp 65001 > nul");
    float poly1[MAX_DEG] = {0}, poly2[MAX_DEG] = {0};
    float mulRes[MAX_DEG] = {0}, divQ[MAX_DEG] = {0};
    int n1, n2;

    // 输入第一个多项式
    if (!(cin >> n1)) return 0;
    input(poly1, n1);

    // 输入第二个多项式
    if (!(cin >> n2)) return 0;
    input(poly2, n2);

    // 1. 乘法
    multiplication(poly1, n1, poly2, n2, mulRes);
    cout << "乘法结果: ";
    output(mulRes, n1 + n2);

    // 2. 除法 (用乘法结果除以 poly2)
    // 注意：division 会修改被除数数组，所以这里传入的是 mulRes 的副本或直接使用
    // 运行后 mulRes 将变成余数
    division(mulRes, n1 + n2, poly2, n2, divQ);
    
    cout << "除法商: ";
    output(divQ, n1); // 商的阶数应该是 n1
    cout << "除法余数: ";
    output(mulRes, n2 - 1); // 余数的阶数最大为 n2-1

    return 0;
}
