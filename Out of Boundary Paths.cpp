class Solution {
public:
    int dp[51][51][51];
    int fun(int m, int n, int moves, int i, int j)
    {
        if(i < 0 || j < 0 || i >= m || j >= n)
        {
            return 1;
        }
        if(moves == 0)
        {
            return 0;
        }
        if(dp[i][j][moves] != -1)
        {
            return dp[i][j][moves];
        }
        int ans = 0;
        ans = (ans + fun(m, n, moves - 1, i - 1, j)) % 1000000007;
        ans = (ans + fun(m, n, moves - 1, i + 1, j)) % 1000000007;
        ans = (ans + fun(m, n, moves - 1, i, j - 1)) % 1000000007;
        ans = (ans + fun(m, n, moves - 1, i, j + 1)) % 1000000007;
        return dp[i][j][moves] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return fun(m, n, maxMove, startRow, startColumn);
    }
};
