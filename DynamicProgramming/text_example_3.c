#include <stdio.h>
#include <string.h>

#define MAXN 1000

int c[MAXN][MAXN];    // DP 表，c[i][j] 表示 X[1..i], Y[1..j] 的 LCS 长度
char X[MAXN], Y[MAXN];
char LCS[MAXN];       // 保存最终的 LCS 序列

int main()
{
    printf("请输入序列 X:");
    scanf("%s", X + 1);     // 从 1 开始存更好理解 DP
    printf("请输入序列 Y:");
    scanf("%s", Y + 1);

    int m = strlen(X + 1);
    int n = strlen(Y + 1);

    // ====== 构建 DP 表 ======
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i] == Y[j])
                c[i][j] = c[i-1][j-1] + 1;  // 字符相等 → 斜对角 +1
            else
                c[i][j] = (c[i-1][j] > c[i][j-1] ? c[i-1][j] : c[i][j-1]);
        }
    }

    printf("\nLCS 长度 = %d\n", c[m][n]);

    // ====== 回溯恢复 LCS ======
    int i = m, j = n, k = c[m][n];
    LCS[k] = '\0';   // 字符串结束符

    while (i > 0 && j > 0) {
        if (X[i] == Y[j]) {
            LCS[--k] = X[i];   // 放入 LCS（倒序填）
            i--;
            j--;
        }
        else if (c[i-1][j] >= c[i][j-1]) {
            i--;               // 来自上方
        }
        else {
            j--;               // 来自左方
        }
    }

    printf("LCS = %s\n", LCS);

    return 0;
}
