#include <iostream>
#include <string.h>

using namespace std;

#define MAXLEN 1000

char X[MAXLEN];
int m;
char Y[MAXLEN];
int n;
int dp[MAXLEN][MAXLEN];
int trace[MAXLEN][MAXLEN];

void Init()
{
    cout << "Please input the first sequence:" << endl;
    cin.getline(X,MAXLEN);
    cout << "Please input the second sequence:" << endl;
    cin.getline(Y,MAXLEN);

    m = strlen(X);
    n = strlen(Y);
}

void LCSLength(char* x, char* y, int m, int n, int dp[][MAXLEN], int trace[][MAXLEN])
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1] == y[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                trace[i][j] = 1;
            }
            else if (dp[i-1][j]>=dp[i][j-1]) 
            {
                dp[i][j] = dp[i-1][j];
                trace[i][j] = 2;
            }
            else
            {
                dp[i][j] = dp[i][j-1];
                trace[i][j] = 3;
            }
        }
    }

    cout << "The length of LCS is: " << dp[m][n] << endl;
}

void PrintLCS(int trace[][MAXLEN], char* x, int i, int j)
{
    if(i == 0 || j == 0)
    {
        return;
    }
    if(trace[i][j] == 1)
    {
        PrintLCS(trace, x, i-1, j-1);
        cout << x[i-1];
    }
    else if(trace[i][j] == 2)
    {
        PrintLCS(trace, x, i-1, j);
    }
    else
    {
        PrintLCS(trace, x, i, j-1);
    }
}

int main()
{
    Init();
    LCSLength(X, Y, m, n, dp, trace);
    PrintLCS(trace, X, m, n);
    return 0;
}
