#include "common.h"

int uniquePaths(int m, int n) 
{
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[j] += dp[j - 1];
        }
    }

    return dp[n - 1];
}

int uniquePaths2(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n,1));
    dp[0][0] = 0;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp.back().back();
}